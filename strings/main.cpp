#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include <algorithm>
using str = std::string;

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // // 0 task
    // const size_t ENG_LOWER_START = 97;
    // const size_t ENG_LOWER_END = 122;
    // const size_t ENG_UPPER_START = 65;
    // const size_t ENG_UPPER_END = 90;
    // const size_t RU_START = 192;
    // const size_t RU_END = 255;
    // const size_t DIGITS_PUNCTUATION_START = 44;
    // const size_t DIGITS_PUNCTUATION_END = 63;
    // for(int i = ENG_LOWER_START; i <= ENG_LOWER_END; i++){
    //     std::cout << i << " - " << static_cast<char>(i) << std::endl;
    // }
    // for(int i = ENG_UPPER_START; i <= ENG_UPPER_END; i++){
    //     std::cout << i << " - " << static_cast<char>(i) << std::endl;
    // }
    // for(int i = RU_START; i <= RU_END; i++){
    //     std::cout << i << " - " << static_cast<char>(i) << std::endl;
    // }
    // for(int i = DIGITS_PUNCTUATION_START; i <= DIGITS_PUNCTUATION_END; i++){
    //     std::cout << i << " - " << static_cast<char>(i) << std::endl;
    // }

    // //1 task
    
    
    // str line = "ÛÌÛÂÀûâìûâùëçêåðüàâèøàùøÎÇîâàùèâõÒÌÛÖÄâëàù";
    // char main_arr[42];
    // for (int i = 0; i < line.size(); i++){
    //     main_arr[i] = line[i];
    // }

    // char arr_consonats[] = {'á', 'â', 'ã', 'ä', 'æ', 'ç', 'é', 'ê', 'ë', 'ì', 'í', 'ï', 'ð', 'ñ', 'ò', 'ô', 'õ', 'ö', '÷', 'ø', 'ù'};
    // for (int i = 0; i < sizeof(main_arr); i++ ){
    //     for (int j = 0; j < sizeof(arr_consonats); j++){
    //         if (main_arr[i] == arr_consonats[j]){
    //             main_arr[i] = static_cast<char>(static_cast<int>(main_arr[i]) - 32);
    //         }
    //     }
        
    // }

    // for (int i = 0; i < sizeof(main_arr); i++ ){
    //     std::cout << main_arr[i] << std::endl;
    // }

// 2 task
    std::ifstream prm_file("../input.txt");
    const int PARAM_SIZE = 3;
    str param_arr[PARAM_SIZE] = {};
    if (prm_file.is_open()){
        size_t cnt = 0;
        str word;
        while (prm_file >> word){
            param_arr[cnt] = word;
            cnt+=1;
        }
        prm_file.close();
    }


    std::ifstream file("../text.txt");
    const int TEXT_SIZE = 756;
    str arr_text[TEXT_SIZE] = {};
    if (file.is_open()){
        size_t cnt = 0;
        str word;
        while(file >> word){
            arr_text[cnt] = word;
            cnt +=1;
        }

        // for (int i = 0; i <TEXT_SIZE; i++ ){
        //     std::cout << arr_text[i] << std::endl;
        // }
        file.close();
        char first_letter = param_arr[1][0];
        char second_letter = param_arr[2][0];
        const int RESULT_SIZE = 1000;   
        int cnt_words = 0;
        str result_arr[RESULT_SIZE];
        for (int i = 0; i < TEXT_SIZE; i++){
            auto is_first_letter = std::find(arr_text[i].begin(), arr_text[i].end(), first_letter);
            auto is_second_letter = std::find(arr_text[i].begin(), arr_text[i].end(), second_letter);
            if ((is_first_letter != arr_text[i].end()) && (is_second_letter != arr_text[i].end())){
                result_arr[cnt_words] = arr_text[i];
                cnt_words +=1;
                }
            }

        std::string available_start_symbols = "éöóêåíãøùçõúôûâàïðîëäæýÿ÷ñìèòüáþ¸1234567890¨ÉÖÓÊÅÍÃØÙÇÕÚÔÛÂÀÏÐÎËÄÆÝß×ÑÌÈÒÜÁÞ";
        std::string available_end_symbols = "éöóêåíãøùçõúôûâàïðîëäæýÿ÷ñìèòüáþ¸¨ÉÖÓÊÅÍÃØÙÇÕÚÔÛÂÀÏÐÎËÄÆÝß×ÑÌÈÒÜÁÞ";
        for (int i = 0; i < cnt_words; i++) {
            for (int k = 0; k < result_arr[i].size(); ) {
                bool is_valid = false;
                for (int j = 0; j < available_start_symbols.size(); j++) {
                    if (result_arr[i][k] == available_start_symbols[j]) {
                        is_valid = true;
                        break;
                    }
                }
                if (!is_valid) {
                    result_arr[i].erase(k, 1);
                } else {
                    k++;
                }
            }
        }

        for (int i = 0; i < cnt_words; i++) {
            for (int k = result_arr[i].size() - 1; k >= 0; k--) {
                bool is_valid = false;
                for (int j = 0; j < available_end_symbols.size(); j++) {
                    if (result_arr[i][k] == available_end_symbols[j]) {
                        is_valid = true;
                        break;
                    }
                }
                if (!is_valid) {
                    result_arr[i].erase(k, 1);
                }
            }
        }
        
        for (int i = 0; i < cnt_words - 1; i++) {
            for (int j = 0; j < cnt_words - i - 1; j++) {
            if (result_arr[j].length() > result_arr[j + 1].length()) {
                str temp = result_arr[j];
                result_arr[j] = result_arr[j + 1];
                result_arr[j + 1] = temp;
                }
            }   
        }
        
        const int N = std::stoi(param_arr[0]);
        const int THE_FINAL_ARR_SIZE = 100;
        str the_final_arr[THE_FINAL_ARR_SIZE];
        int count_n = 0;
        for (int i = 0; i < cnt_words; i++){
            bool is_same  = false;
            str first_word = result_arr[i].substr(1);
            for (int j = 0; j < cnt_words; j++){
                if (i == j) continue;
                str second_word = result_arr[j].substr(1);
                if (first_word == second_word){
                    is_same = true;
                    break;
                }
            }
            if (!is_same){
                the_final_arr[count_n] = result_arr[i];
                count_n++;
            }
            if(count_n == N){
                break;
            }

        } 
        for(int i = 0; i < count_n; i++){
            std::cout << the_final_arr[i] << std::endl;
        }
        std::ofstream result("../result.txt");
        if (result.is_open()){
            for (int i = 0; i < count_n; i++){
                result << the_final_arr[i] << " ";
            }
            result.close();
            std::cout << std::endl;
        }
        return 0;
    }
}
    


