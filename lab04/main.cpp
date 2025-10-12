#include <iostream>


int main() {
    
    // Задание 1
    int x[5];
    for (int i = 0; i < 5; ++i) {
        std::cout << "Enter the element of the array" << std::endl;
        std::cin >> x[i];
    }

    int sum = 0;
    int cnt = 0;
    for (int i1 = 0; i1 < 5; ++i1) {
        int num = abs(x[i1]);
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        if (sum > 25) {
            ++cnt;
        }
        sum = 0;
    }

    if (cnt >= 2) {
        for (int i3 = 0; i3 < 4; ++i3) {
            for (int j = i3 + 1; j < 5; ++j) {
                if (x[i3] > x[j]) {
                    std::swap(x[i3], x[j]);
                }
            }
        }
    }
    for (int i4 = 0; i4 < 5; ++i4) {
        std::cout << x[i4] << std::endl;
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

        f[i][numOfColumn] = 0;
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << f[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

