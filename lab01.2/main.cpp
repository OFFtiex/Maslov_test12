/*
#include <iostream>



int main() {

    setlocale(LC_ALL, "Russian");

    // высота < 256, основания <= 1000

    unsigned short height, base1, base2;
    
      //Выбираем unsigned short, т.к в него можно записать значения от 0 до 65535, что подходит для нашего условия
    
    std::cout << "Enter the height of the trapezoid: " << std::endl;
    std::cin >> height;

    std::cout << "Enter the first base of the trapezoid: " << std::endl;
    std::cin >> base1;

    std::cout << "Enter the second base of the trapezoid: " << std::endl;
    std::cin >> base2;


    float square = (base1 + base2) * height / 2.0; // 4 байта, 6-7 значащих чисел
    std::cout << "The square of the trapezoid (float):" << std::endl << square << std::endl;
    std::cout << "unsigned short: занимает " << sizeof(unsigned short) * 8 << " бит, мин значение = " << "0" << " макс значение = " << pow(2,16) -1 << std::endl;
    std::cout << "float: занимает " << sizeof(float) * 8 << " бит, мин значение = " << std::numeric_limits<float>::lowest() << " макс значение = " << std::numeric_limits<float>::max() << std::endl;
    

    
    


    return 0;
}
*/
#include <iostream>
#include <vector>


float secondaryFunction(int n1, int n2) {
    std::cout << "The function of average value of two numbers " << std::endl;
    float avg = 0;
    avg = (n1 + n2) / 2.f;
    return avg;
}

float secondaryFunction(int n1, int n2, int n3) {
    std::cout << "The function of average value of three numbers" << std::endl;
    float avg = 0;
    avg = (n1 + n2 + n3) / 3.f;
    return avg;
}

float mainFunction(int num1, int num2, int num3) {
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
        return secondaryFunction(nonZeroNumbers[0], nonZeroNumbers[1]);
    }
    else if (nonZeroNumbers.size() == 3) {
        return secondaryFunction(nonZeroNumbers[0], nonZeroNumbers[1], nonZeroNumbers[2]);
    }
    else {
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

void task2(int x) {

    float x_rec = 1 / (float)x; // находим обратное числу x, 4 байта, 6-7 значащих чисел
    // выбираем fload, потому что значение 1/x получится число дробное с плавающей точкой

    int x_2 = std::pow(x, 2);  // возведение x в 2 степень
    // выбираем int, потому что значение x_2 получится число целое

    int x_5 = std::pow(x, 5); // возведение x в 5 степень
    // выбираем int, потому что значение x_5 получится число целое

    // вывод результатов 
    std::cout << "x_rec(float)= " << x_rec << std::endl;
    std::cout << "x_2(int)= " << x_2 << std::endl;
    std::cout << "x_5(int)= " << x_5 << std::endl;

    std::cout << "int: занимает " << sizeof(int) * 8 << " бит, мин. значение = " << std::numeric_limits<int>::lowest() <<
        " макс. значение = " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "float: занимает " << sizeof(float) * 8 << " бит, мин. значение = "
        << std::numeric_limits<float>::lowest() << " макс. значение = " << std::numeric_limits<float>::max() << std::endl;
}

int main() {
    bool flag;
    std::cout << "Enter the task (task 1 - 0, task 2 - 1)" << std::endl;
    std::cin >> flag;
    if (flag) {
        int x; // 4 байта
        // выбираем int, потому что x число целое

        std::cout << "x: " << std::endl;
        std::cin >> x; // ввод x с клавиатуры
        task2(x);
    }
    else {
        task1();
    }

    return 0;
}



