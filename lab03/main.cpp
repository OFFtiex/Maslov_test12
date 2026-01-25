#include <iostream>

int main() {
    
    
    
    // Задание 1
    
    std::cout << "Enter N" << std::endl;
    int n;
    std::cin >> n;
    int numCnt = 0;
    int minNumCnt = -1;
    int sum = 0;
    int max = -2147483647;
    for (n; n > 0; --n) {
        ++numCnt;
        std::cout << "Enter the " << numCnt << " number" << std::endl;
        int num;
        std::cin >> num;
        if (abs(num) % 10 == 2) {
            sum += num;
            if (num >= max) {
                max = num;
                minNumCnt = numCnt;
            }

        }
    }
    if (minNumCnt != -1) {
        std::cout << "The sum of numbers = " << sum << std::endl;
        std::cout << "The max element = " << max << std::endl;
        std::cout << "The number of the max element = " << minNumCnt << std::endl;
        std::cout << "The end" << std::endl;
    }
    else {
        std::cout << "There are no suitable numbers" << std::endl;
        std::cout << "The end" << std::endl;
    }
/*

    // Задание 2

    std::cout << "Enter the number " << std::endl;
    
    short num;
    int sum = 0;
    std::cin >> num;

    short num1;
    num1 = abs(num);
    if (num1 > 1000) {
        std::cout << "Error: |x| > 1000" << std::endl;
    }
    else {
        while (num1 > 0) {
            sum += num1 % 10;
            num1 /= 10;
        }
        std::cout << "The sum of the figits of the number = " << sum << std::endl;
        std::cout << "The end" << std::endl;
    }
    */
    return 0;
}
