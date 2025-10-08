#include <iostream>


int main() {
    
    // Задание 1

    std::cout << "Enter N" << std::endl;
    int n;
    std::cin >>  n;
    int numCnt = 0;
    int minNumCnt = 0;
    int product = 1;
    int min = 100'000'000;
    for(n; n > 0; --n){
        ++numCnt;
        std::cout << "Enter the "  << numCnt << " number" << std::endl;
        int num;
        std::cin >> num;
        //--n;
        if (num % 10 == 3) {
            product =  product * num ;
            if (num < min) {
                min = num;
                minNumCnt = numCnt;
            }

        }
    }
    if (product != 1) {
        std::cout << "The product of numbers = " << product << std::endl;
        std::cout << "The min element = " << min << std::endl;
        std::cout << "The number of the min element = " << minNumCnt << std::endl;
        std::cout << "The end" << std::endl;
    }
    else {
        std::cout << "There are no suitable numbers" << std::endl;
        std::cout << "The end" << std::endl;
    }
    
    // Задание 2
    
    std::cout << "Enter the number " << std::endl;
    short num;
    int sum = 0;
    std::cin >> num;

    short num1;
    num1 = abs(num);

    while (num1 > 0) {
        sum += num1 % 10;
        num1 /= 10;
    }
    std::cout << "The sum of the figits of the number = " << sum << std::endl;
    std::cout << "The end" << std::endl;
    

   

    return 0;
}

