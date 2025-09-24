#include <iostream>



int main() {
    int k = 16;
    int m = 0;
    int l = std::pow(2, 16) - 1;
    std::cout << "unsigned short, занимает " << k << " бит, мин значение = " << m << " макс значение = " << l << std::endl;
    // высота < 256, основания <= 1000

    unsigned short height, base1, base2; // Выбираем unsigned short, т.к в него можно записать значения от 0 до 65535, что подходит для нашего условия

    std::cout << "Enter the height of the trapezoid: " << std::endl;
    std::cin >> height;

    std::cout << "Enter the first base of the trapezoid: " << std::endl;
    std::cin >> base1;

    std::cout << "Enter the second base of the trapezoid: " << std::endl;
    std::cin >> base2;


    float square = (base1 + base2) * height / 2.0; // 4 байта, 6-7 значащих чисел
    std::cout << "The square of the trapezoid:" << std::endl << square << std::endl;


    return 0;
}
 