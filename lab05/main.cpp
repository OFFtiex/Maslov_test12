#include <iostream>
#include <vector>


int functionForTwoNumbers(int n1, int n2) {
    std::cout << "The function of summing two numbers" << std::endl;
    int sum = 0;
    while (n1 > 0) {
        sum += abs(n1) % 10;
        n1 /= 10;
    }
    while (n2 > 0) {
        sum += abs(n2) % 10;
        n2 /= 10;
    }
    return sum;
}


int functionForThreeNumbers(int a, int b, int c) {
    std::cout << "The function of maximum numbers and 25" << std::endl;
    int max_value = std::max({ a, b, c });
    return std::max(max_value, 25);
}

int mainFunction(int num1, int num2, int num3) {
    std::vector<int> nonZeroNumbers;

    if (num1 != 0) {
        nonZeroNumbers.push_back(num1);
    }
    if (num2 != 0) {
        nonZeroNumbers.push_back(num2);
    }
    if (num3 != 0) {
        nonZeroNumbers.push_back(num3);
    }

    if (nonZeroNumbers.size() == 2) {
        return functionForTwoNumbers(nonZeroNumbers[0], nonZeroNumbers[1]);
    }
    if (nonZeroNumbers.size() == 3) {
        return functionForThreeNumbers(nonZeroNumbers[0], nonZeroNumbers[1], nonZeroNumbers[2]);
    }
    if (nonZeroNumbers.size() < 2) {
        std::cout << "Incorrect number input" << std::endl;
        return 0;
    }

}

void task1() {
    int a, b, c;
    std::cout << "Enter three numbers ";
    std::cin >> a >> b >> c;
    std::cout << mainFunction(a, b, c) << std::endl;
}
void task2(unsigned short  height, unsigned short base1, unsigned short base2) {

    float square = (base1 + base2) * height / 2.0; 
    std::cout << "The square of the trapezoid (float):" << std::endl << square << std::endl;
    std::cout << "unsigned short: занимает " << sizeof(unsigned short) * 8 << " бит, мин значение = " << "0" << " макс значение = " << pow(2, 16) - 1 << std::endl;
    std::cout << "float: занимает " << sizeof(float) * 8 << " бит, мин значение = " << std::numeric_limits<float>::lowest() << " макс значение = " << std::numeric_limits<float>::max() << std::endl;
}

int main() {
    bool flag;
    std::cout << "Enter the task (task 1 - 0, task 2 - 1)" << std::endl;
    std::cin >> flag;
    if (flag) {
        unsigned short height_, base1_, base2_;

        std::cout << "Enter the height of the trapezoid: " << std::endl;
        std::cin >> height_;

        std::cout << "Enter the first base of the trapezoid: " << std::endl;
        std::cin >> base1_;

        std::cout << "Enter the second base of the trapezoid: " << std::endl;
        std::cin >> base2_;
        task2(height_, base1_, base2_);
    }
    else {
        task1();
    }
}
