#include <iostream>
#include <bitset>
#include <locale>

/*
Если i бит А равен 1 – показать результаты 3 - х последовательных битовых сдвигов вправо числа А.
Иначе – ввести число M с клавиатуры и сообщить результат сравнения M с 5 (“M больше 5 на 2”)

Ввести с клавиатуры N – номер дня недели, с помощью switch вывести его название.Предусмотреть обработку ошибочного ввода N.
*/

int main() {

    setlocale(LC_ALL, "Russian");

    // Задание 1 
    std::cout << "Task 1 " << std::endl;
    short A;
    std::cout << "Enter A " << std::endl;
    std::cin >> A;
    int i;
    std::cout << "Enter the number of the i bit" << std::endl;
    std::cin >> i;
    int bitA = (A >> i) & 1;
    std::cout << std::bitset<8>(A) << std::endl;

    if (bitA != 0) {
        std::cout << A << " = " <<  std::bitset<8>(A) << std::endl;
        std::cout << A << ">>1 = " << std::bitset<8>(A >> 1) << std::endl;
        std::cout << A << ">>2 = " << std::bitset<8>(A >> 2) << std::endl;
        std::cout << A << ">>3 = " << std::bitset<8>(A >> 3) << std::endl;
    }

    else {
        int M;
        std::cout << "Enter M " << std::endl;
        std::cin >> M;
        if (M > 5) {
            std::cout << "M is greater than 5 by " << (M - 5) << std::endl;
        }
        else if (M == 5) {
            std::cout << "M = 5" << std::endl;
        }
        else {
            std::cout << "M is less than 5 " << (5 - M) << std::endl;
        }
    }
  
    // Задание 2

    std::cout << "Task 2 " << std::endl;
    short dayNumber;
    std::cout << "Enter the day number " << std::endl;
    std::cin >> dayNumber;
    switch (dayNumber) {
    case 1:std::cout << "Monday"; break;
    case 2:std::cout << "Tuesday"; break;
    case 3:std::cout << "Wednesday"; break;
    case 4:std::cout << "Thursday"; break;
    case 5:std::cout << "Friday"; break;
    case 6:std::cout << "Saturday"; break;
    case 7:std::cout << "Sunday"; break;
    default:std::cout << "Unknown number"; break; 
    }
    

    return 0;
}

