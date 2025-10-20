#include <iostream>


int main() {
    
    // Задание 1

    int x[5];
    for (int i = 0; i < 5; ++i) {
        std::cout << "Enter the element of the array" << std::endl;
        std::cin >> x[i];
    }

    int sum = 0;
    int cnt2 = 0;
    for (int i = 0; i < 5; ++i) {
        int num = abs(x[i]);
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        if (sum > 25) {
            ++cnt2;
        }
        sum = 0;
    }

    if (cnt2 >= 2) {
        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 5; ++j) {                  // Упорядочивание массива
                if (x[i] > x[j]) {
                    std::swap(x[i], x[j]);
                }
            }
        }
    }
    for (int i = 0; i < 5; ++i) {
        std::cout << x[i] << std::endl;
    }
    std::cout << "The end" << std::endl;
    
    // Задание 2
    
    int f[3][4];

    for (int j = 0; j < 4; ++j) {
        for (int i = 0; i < 3; ++i) {
            std::cout << "Enter the element of the array" << std::endl;
            std::cin >> f[i][j];
        }
    }

    int cnt = 0;
    int cnt1 = -1;
    int numOfColumn = -1;
    for (int j = 0; j < 4; ++j) {
        for (int i = 0; i < 3; ++i) {
            if (f[i][j] <= 0) {
                ++cnt;
            }
        }
        if (cnt > cnt1) {
            cnt1 = cnt;
            numOfColumn = j;
        }
        cnt = 0;
    }
    std::cout << numOfColumn << std::endl;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << f[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < 3; ++i) {

        f[i][numOfColumn] = 100;
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << f[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
