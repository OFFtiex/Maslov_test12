#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include "auto.hpp"
//Поля: марка, модель, гос. номер, вектор вещей в багажнике.

using str = std::string;
using vec = std::vector<str>;


int main() {
	srand(time(0));
	vec baggage1 = {"Bottle", "Cake", "Laptop","Jacket"};
	Car car{"Range Rover", "Defender", "A123BC", baggage1};
	vec baggage2 = {"Jacket", "Cake", "Headphones", "Cake"};
	Car car1{"BMW", "X6", "M345VF", baggage2};
	Car car_result_plus = car + car1;
	Car car_result_minus = car - car1;
	Car car_result_division = car / car1;
	int n;
	do {
		std::cout << "=============" << std::endl;
		std::cout << "Menu:" << std::endl;
		std::cout << "0. Exit" << std::endl;
		std::cout << "1. Get car name" << std::endl;
		std::cout << "2. Get car model" << std::endl;
		std::cout << "2. Get car model" << std::endl;
		std::cout << "4. Get GOS number" << std::endl;
		std::cout << "7. Set GOS number" << std::endl;
		std::cout << "9. Print info" << std::endl;
		std::cout << "10. Set car name" << std::endl;
		std::cout << "11. Set car model" << std::endl;
		std::cout << "12. Show operator +" << std::endl;
		std::cout << "13. Show operator -" << std::endl;
		std::cout << "14. Show operator /" << std::endl;
		std::cout << "=============" << std::endl;
		std::cout << "What you what to do?" << std::endl;
		std::cin >> n;
		str number;
		switch (n) {
		case 0:
			break;
		case 1:
			std::cout << car.get_car_name_() << std::endl;
			break;

		case 2:
			std::cout << car.get_car_model_() << std::endl;
			break;
		case 4:
			std::cout << car.get_GOS_number_() << std::endl;
			break;
		case 7:
			std::cout << "Enter GOS number:" << std::endl;
			std::cin >> number;
			try {
				car.set_GOS_number_(number);
			}
			catch (str error) {
				std::cerr << error << std::endl;
			}
			break;
		case 9:
			car.print_info();
			break;
		case 10:
			std::cout << "Enter car name:" << std::endl;
			std::cin >> number;
			try {
				car.set_car_name(number);
			}
			catch (str error) {
				std::cerr << error << std::endl;
			}
			break;
		case 11:
			std::cout << "Enter car model:" << std::endl;
			std::cin >> number;
			try {
				car.set_car_model(number);
			}
			catch (str error) {
				std::cerr << error << std::endl;
			}
			break;
		case 12:
			car.print_info();
			std::cout << "+" << std::endl;
			car1.print_info();
			std::cout << "=" << std::endl;
			car_result_plus.print_info();
			break;
		case 13:
			car.print_info();
			std::cout << "-" << std::endl;
			car1.print_info();
			std::cout << "=" << std::endl;
			car_result_minus.print_info();
			break;
		case 14:
			car.print_info();
			std::cout << "/" << std::endl;
			car1.print_info();
			std::cout << "=" << std::endl;
			car_result_division.print_info();
			break;
		default:
			std::cout << "invalid value" << std::endl;
			break;
		}
	} while (n != 0);
	return 0;
}