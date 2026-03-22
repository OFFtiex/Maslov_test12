#include <iostream>
#include <cstring>
#include<windows.h>
#include <fstream>
using namespace std;

char ToLower(unsigned char c){
    if ( c >= 'A' && c <= 'Z' ) return c + 32;
    if (c >= 192 && c <= 223) return c + 32;
    if (c == 168) return 184;
    return c;
}

char ToUpper(unsigned char c){
    if ( c >= 'a' && c <= 'z' ) return c - 32;
    if (c >= 224 && c <= 255) return c - 32;
    if (c == 184) return 168;
    return c;
}

bool isRussianChar(char c) {
    unsigned char uc = c;
    return (uc >= 192 && uc <= 255); 
}

bool isLetter(char c) {
    return (isalpha(c) || isRussianChar(c));
}

bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

bool isWordPart(char c) {
    return (isLetter(c) || isDigit(c));
}

bool isWordStart(char c) {
    return (isLetter(c) || isDigit(c));
}


//пункт 0

// void PrintTable(){
    
//     cout << "=== ТАБЛИЦА СИМВОЛОВ ===" << endl;

//     cout << "Русские буквы" << endl;
//     for (unsigned char c = 192; c <= 255; c++){
//         cout << "Символ: " << c << " Код: " <<  static_cast<unsigned int>(c) << endl;
//     }
//     cout << " " << endl;

//     cout << "Английские буквы:" << endl;
//     for (char c = 'A' ; c <= 'Z' ; c++ ){
//         cout << "Символ: " << c << " Код: " << static_cast<int>(c) << endl;
//     }
//     for (char c = 'a' ; c <= 'z' ; c++ ){
//         cout << "Символ: " << c << " Код: " << static_cast<int>(c) << endl;
//     }
//     cout << " " << endl;

//     cout << "Цифры:" << endl;
//     for ( char c = '0'; c <= '9'; c++){
//         cout << "Символ: " << c << " Код: " << static_cast<int>(c) << endl;
//     }
//     cout << " " << endl;

//     cout << "Знаки препинания: " << endl;
//     char signs[] = ".,!?;:-()\"'";
//     for (int i = 0;  i < strlen(signs); i++){
//         cout << "Символ: " << signs[i] << " Код: " << static_cast<int>(signs[i]) << endl;
//     }
// }

//пункт 1.1

// void task1(){
//     cout << "=== ЗАДАЧА 1 ===" << endl;
//     char consonants[] = "бвгджзйклмнпрстфхцчшщbcdfghjklmnpqrstvwxz";
//     char line[101];
//     cout <<"Введите строку (< 100): ";
//     cin.getline(line, 101);
//     for (int i = 0; i < strlen(line); i++){
//         for (int j = 0; j < strlen(consonants); j++){
//             if (ToLower(line[i]) == consonants[j]){
//                 line[i] = ToUpper(line[i]);
//                 break;
//             }
//         }
//     }
//     cout << "Результат: " << line << endl;

// }

// пункт 2

void task2(){
    cout << "=== ЗАДАЧА 2 ===" << endl;

    ifstream in("../input.txt");
    if (!in) {
        cout << "Ошибка открытия файла input.txt" << endl;
        return;
    }
    
    int N;
    char letter1, letter2;
    in >> N >> letter1 >> letter2;
    in.close();

    cout << "Ищем " << N << " самых коротких слов, содержащих буквы '" << letter1 << "' и '" << letter2 << "'" << endl;
    letter1 = ToLower(letter1);
    letter2 = ToLower(letter2);
    
    ifstream textFile("../text.txt");
    if (!textFile) {
        cout << "Ошибка открытия файла text.txt" << endl;
        return;
    }
    char words[400][51];
    int wordCount = 0;
    char ch;
    char currentWord[51];
    int wordPos = 0;
    bool inWord = false;
    
    while (textFile.get(ch)) {
        if (isWordPart(ch)) {
            if (!inWord) {
                inWord = true;
                wordPos = 0;
            }
            if (wordPos < 50) {
                currentWord[wordPos++] = ToLower(ch);
            }
        }
        else if (inWord) {
            inWord = false;
            currentWord[wordPos] = '\0';


            bool hasLetter = false;
            for (int i = 0; i < wordPos; i++) {
                if (isLetter(currentWord[i])) {
                    hasLetter = true;
                    break;
                }
            }
            
            if (hasLetter) {
                bool hasLetter1 = false, hasLetter2 = false;
                for (int i = 0; i < wordPos; i++) {
                    if (currentWord[i] == letter1) hasLetter1 = true;
                    if (currentWord[i] == letter2) hasLetter2 = true;
                }
                
                if (hasLetter1 && hasLetter2) {
                    
                    bool found = false;
                    for (int i = 0; i < wordCount; i++) {
                        if (strcmp(words[i], currentWord) == 0) {
                            found = true;
                            break;
                        }
                    }
                    
                    if (!found) {
                        strcpy(words[wordCount], currentWord);
                        wordCount++;
                    }
                }
            }
        }
    }
    
    if (inWord && wordPos > 0) {
        currentWord[wordPos] = '\0';
        
        bool hasLetter = false;
        for (int i = 0; i < wordPos; i++) {
            if (isLetter(currentWord[i])) {
                hasLetter = true;
                break;
            }
        }
        
        if (hasLetter) {
            bool hasLetter1 = false, hasLetter2 = false;
            for (int i = 0; i < wordPos; i++) {
                if (currentWord[i] == letter1) hasLetter1 = true;
                if (currentWord[i] == letter2) hasLetter2 = true;
            }
            
            if (hasLetter1 && hasLetter2) {
                bool found = false;
                for (int i = 0; i < wordCount; i++) {
                    if (strcmp(words[i], currentWord) == 0) {
                        found = true;
                        break;
                    }
                }
                
                if (!found) {
                    strcpy(words[wordCount], currentWord);
                    wordCount++;
                }
            }
        }
    }
    
    textFile.close();
    
    cout << "Найдено слов, содержащих обе буквы: " << wordCount << endl;
    
    if (wordCount == 0) {
        cout << "Нет подходящих слов" << endl;
        return;
    }
    
    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = 0; j < wordCount - i - 1; j++) {
            if (strlen(words[j]) > strlen(words[j + 1])) {

                char temp[51];
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }
    
    
    ofstream result("result.txt");
    int limit = (N < wordCount) ? N : wordCount;
    
    cout <<"Короткие слова: " << endl;
    for (int i = 0; i < limit; i++) {
        cout << words[i] << " (длина: " << strlen(words[i]) << ")" << endl;
        result << words[i] << endl;
    }
    
    result.close();
    cout << "Результат сохранен в файл result.txt" << endl;


}



int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //PrintTable();
    //task1();
    task2();


}
