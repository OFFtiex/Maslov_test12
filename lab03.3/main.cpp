#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include "auto.hpp"
#include "inc/my_lib.hpp"


using str = std::string;
using vec = std::vector<str>;
using vec_pointer = std::vector<Car*>;
void print_personal_assessment(){
		std::cout << "Interest: 9/10" << std::endl;
		std::cout << "Complexity: 8/10" << std::endl;
		std::cout << "Fullness: 7/10" << std::endl;
	}

int main() {

	srand(time(0));

	Radio radio1;
	radio1.name = "Aura";
	radio1.info = "The best radio in the world";
	radio1.cost = 7500;

	Radio radio2;
	radio2.name = "Muntz Wayfarer";
	radio2.info = "Famously installed in the cars of celebrities like Frank Sinatra";
	radio2.cost = 10000;

	Radio radio3;
	radio3.name = "Pioneer CT-F750";
	radio3.info = "The Pioneer CT-F750, housed in a distinctive wooden box, was a high-end component of its time ";
	radio3.cost = 4000;

	vec baggage1 = {"Bottle", "Cake", "Laptop","Jacket"};
	Car car1{"Range Rover", "Defender", "A123BC", baggage1};
	vec baggage2 = {"Jacket", "Cake", "Headphones", "Cake"};
	Car car2{"BMW", "X6", "M345VF", baggage2};

	Car car_result_plus = car1 + car2;
	Car car_result_minus = car1 - car2;
	Car car_result_division = car1 / car2;

	std::vector<Radio> avaible_radio = {radio1, radio2, radio3};
	vec_pointer auto_in_garage = {&car1};

	
	Garage main_garage{"Street Green 12", avaible_radio, auto_in_garage};
	int n;
	do {
		std::cout << "=============" << std::endl;
		std::cout << "Menu:" << std::endl;
		std::cout << "0. Exit" << std::endl;
		std::cout << "1. Get car name" << std::endl;
		std::cout << "2. Get car model" << std::endl;
		std::cout << "4. Get GOS number" << std::endl;
		std::cout << "7. Set GOS number" << std::endl;
		std::cout << "9. Print info" << std::endl;
		std::cout << "10. Set car name" << std::endl;
		std::cout << "11. Set car1 model" << std::endl;
		std::cout << "12. Show operator +" << std::endl;
		std::cout << "13. Show operator -" << std::endl;
		std::cout << "14. Show operator /" << std::endl;
		std::cout << "15. Print garage " << std::endl;
		std::cout << "16. Attacch auto in garage" << std::endl;
		std::cout << "17. Set radio in car" << std::endl;
		std::cout << "18. Print radio" << std::endl;
		std::cout << "19. Print personal assessment" << std::endl;
		std::cout << "=============" << std::endl;
		std::cout << "What you what to do?" << std::endl;
		std::cin >> n;
		str number;
		int radio;
		int car;
		switch (n) {
		case 0:
			break;
		case 1:
			std::cout << car1.get_car_name_() << std::endl;
			break;

		case 2:
			std::cout << car1.get_car_model_() << std::endl;
			break;
		case 4:
			std::cout << car1.get_GOS_number_() << std::endl;
			break;
		case 7:
			std::cout << "Enter GOS number:" << std::endl;
			std::cin >> number;
			try {
				car1.set_GOS_number_(number);
			}
			catch (str error) {
				std::cerr << error << std::endl;
			}
			break;
		case 9:
			std::cout << "1. Range Rover 2. BMW" << std::endl;
			std::cout << "Enter number of auto" << std::endl;
			std::cin >> car;
			if (car == 1){
				car1.print_info();
			}
			else if (car == 2){
				car2.print_info();
			}
			break;
		case 10:
			std::cout << "Enter car1 name:" << std::endl;
			std::cin >> number;
			try {
				car1.set_car_name(number);
			}
			catch (str error) {
				std::cerr << error << std::endl;
			}
			break;
		case 11:
			std::cout << "Enter car1 model:" << std::endl;
			std::cin >> number;
			try {
				car1.set_car_model(number);
			}
			catch (str error) {
				std::cerr << error << std::endl;
			}
			break;
		case 12:
			car1.print_info();
			std::cout << "+" << std::endl;
			car2.print_info();
			std::cout << "=" << std::endl;
			car_result_plus.print_info();
			break;
		case 13:
			car1.print_info();
			std::cout << "-" << std::endl;
			car2.print_info();
			std::cout << "=" << std::endl;
			car_result_minus.print_info();
			break;
		case 14:
			car1.print_info();
			std::cout << "/" << std::endl;
			car2.print_info();
			std::cout << "=" << std::endl;
			car_result_division.print_info();
			break;
		case 15:
			main_garage.print_info_garage();
			break;
		case 16:
			main_garage.attach_auto(car2);
			break;
		case 17:
			main_garage.print_avaible_radios();
			std::cout << "Enter number of the avaible radio" << std::endl;
			std::cin >> radio;
			main_garage.print_autos_in_garage();
			std::cout << "Enter number of the auto" << std::endl;
			std::cin >> car;
			if (radio == 1){
				if (car == 1){
					main_garage.set_radio_in_car(&radio1, car1);
				}
				else if (car == 2){
					main_garage.set_radio_in_car(&radio1, car2);
				}
			}
			if (radio == 2){
				if (car == 1){
					main_garage.set_radio_in_car(&radio2, car1);
				}
				else if (car == 2){
					main_garage.set_radio_in_car(&radio2, car2);
				}
			}
			if (radio == 3){
				if (car == 1){
					main_garage.set_radio_in_car(&radio3, car1);
				}
				else if (car == 2){
					main_garage.set_radio_in_car(&radio3, car2);
				}
			}
			break;
		case 18:
			std::cout << "1. Aura 2. Muntz Wayfarer 3. Pioneer CT-F750" << std::endl;
			std::cout << "Enter number of the radio" << std::endl;
			std::cin >> radio;
			if (radio == 1){
				radio1.print_radio();
			}
			else if (radio == 2){
				radio2.print_radio();
			}
			else if (radio == 3){
				radio3.print_radio();
			}
			break;
		case 19:
			print_personal_assessment();
			break;
		default:
			std::cout << "invalid value" << std::endl;
			break;
		}
	} while (n != 0);
	return 0;
}
