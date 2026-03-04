#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include "auto.hpp"


using str = std::string;
using vec = std::vector<str>;
using vec_pointer = std::vector<Car*>;
struct Radio {
	str name;
	str info;
	int cost;
	bool operator==(const Radio& other) const {
        return name == other.name && info == other.info && cost == other.cost;
    } 
	};
class Garage{
public:
	Garage() {
	address_ = "Default street";
	std::cerr << "ctor default" << std::endl;
	}

	Garage(str address, std::vector<Radio> avaible_radio, vec_pointer auto_in_garage): address_(address), avaible_radio_(avaible_radio), auto_in_garage_(auto_in_garage){
		std::cerr << "ctor param" << std::endl;
	}
	Garage(const Garage& p) : address_(p.address_), avaible_radio_(p.avaible_radio_), auto_in_garage_(p.auto_in_garage_) {
		std::cerr << "ctor copy" << std::endl;
	}
	~Garage(){
		std::cerr << "dtor" << std::endl;
	}

	void attach_auto(Car& auto1) {
		if (auto1.get_GOS_number_().size() != 0){
			auto_in_garage_.push_back(&auto1);
		}
		else{
			std::cout << "Car is not exist" << std::endl;
		}
	}
	void set_radio_in_car(Radio& radio, Car& car1){
		auto is_radio = std::find(avaible_radio_.begin(), avaible_radio_.end(), radio);
		auto is_car = std::find(auto_in_garage_.begin(), auto_in_garage_.end(), &car1);
		if ((is_radio != avaible_radio_.end()) && 
			(is_car != auto_in_garage_.end())) {
				avaible_radio_.erase(is_radio);
		}
		else{
			std::cout << "Radio can not be installed" << std::endl;
		}
	}
	void print_info_garage(){
		std::cout << "Garage info:" << std::endl;
		std::cout <<"Address:" <<address_ << std::endl;
		for (int i = 0; i < avaible_radio_.size(); i++){
			std::cout<< avaible_radio_[i].name << " ";
		}
		std::cout << std::endl;
		for (int i = 0; i < auto_in_garage_.size(); i++){
			std::cout<< auto_in_garage_[i]->get_car_name_() << " ";
		}
		std::cout << std::endl;
	}
private:
	str address_;
protected:
	std::vector<Radio> avaible_radio_;
	vec_pointer auto_in_garage_ ;
};

int main() {
	srand(time(0));

	Radio radio1;
	radio1.name = "Aura";
	radio1.info = "The best radio";
	radio1.cost = 7500;

	vec baggage1 = {"Bottle", "Cake", "Laptop","Jacket"};
	Car car1{"Range Rover", "Defender", "A123BC", baggage1};
	vec baggage2 = {"Jacket", "Cake", "Headphones", "Cake"};
	Car car2{"BMW", "X6", "M345VF", baggage2};

	Car car_result_plus = car1 + car2;
	Car car_result_minus = car1 - car2;
	Car car_result_division = car1 / car2;

	std::vector<Radio> avaible_radio = {radio1};
	vec_pointer auto_in_garage = {&car1};

	
	Garage main_garage{"Street Green 12", avaible_radio, auto_in_garage};
	main_garage.print_info_garage();
	// int n;
	// do {
	// 	std::cout << "=============" << std::endl;
	// 	std::cout << "Menu:" << std::endl;
	// 	std::cout << "0. Exit" << std::endl;
	// 	std::cout << "1. Get car1 name" << std::endl;
	// 	std::cout << "2. Get car1 model" << std::endl;
	// 	std::cout << "2. Get car1 model" << std::endl;
	// 	std::cout << "4. Get GOS number" << std::endl;
	// 	std::cout << "7. Set GOS number" << std::endl;
	// 	std::cout << "9. Print info" << std::endl;
	// 	std::cout << "10. Set car1 name" << std::endl;
	// 	std::cout << "11. Set car1 model" << std::endl;
	// 	std::cout << "12. Show operator +" << std::endl;
	// 	std::cout << "13. Show operator -" << std::endl;
	// 	std::cout << "14. Show operator /" << std::endl;
	// 	std::cout << "=============" << std::endl;
	// 	std::cout << "What you what to do?" << std::endl;
	// 	std::cin >> n;
	// 	str number;
	// 	switch (n) {
	// 	case 0:
	// 		break;
	// 	case 1:
	// 		std::cout << car1.get_car_name_() << std::endl;
	// 		break;

	// 	case 2:
	// 		std::cout << car1.get_car_model_() << std::endl;
	// 		break;
	// 	case 4:
	// 		std::cout << car1.get_GOS_number_() << std::endl;
	// 		break;
	// 	case 7:
	// 		std::cout << "Enter GOS number:" << std::endl;
	// 		std::cin >> number;
	// 		try {
	// 			car1.set_GOS_number_(number);
	// 		}
	// 		catch (str error) {
	// 			std::cerr << error << std::endl;
	// 		}
	// 		break;
	// 	case 9:
	// 		car1.print_info();
	// 		break;
	// 	case 10:
	// 		std::cout << "Enter car1 name:" << std::endl;
	// 		std::cin >> number;
	// 		try {
	// 			car1.set_car_name(number);
	// 		}
	// 		catch (str error) {
	// 			std::cerr << error << std::endl;
	// 		}
	// 		break;
	// 	case 11:
	// 		std::cout << "Enter car1 model:" << std::endl;
	// 		std::cin >> number;
	// 		try {
	// 			car1.set_car_model(number);
	// 		}
	// 		catch (str error) {
	// 			std::cerr << error << std::endl;
	// 		}
	// 		break;
	// 	case 12:
	// 		car1.print_info();
	// 		std::cout << "+" << std::endl;
	// 		car2.print_info();
	// 		std::cout << "=" << std::endl;
	// 		car_result_plus.print_info();
	// 		break;
	// 	case 13:
	// 		car1.print_info();
	// 		std::cout << "-" << std::endl;
	// 		car2.print_info();
	// 		std::cout << "=" << std::endl;
	// 		car_result_minus.print_info();
	// 		break;
	// 	case 14:
	// 		car1.print_info();
	// 		std::cout << "/" << std::endl;
	// 		car2.print_info();
	// 		std::cout << "=" << std::endl;
	// 		car_result_division.print_info();
	// 		break;
	// 	default:
	// 		std::cout << "invalid value" << std::endl;
	// 		break;
	// 	}
	// } while (n != 0);
	return 0;
}