#include "../inc/my_lib.hpp"
#include "../auto.hpp" 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>



using str = std::string;
using vec = std::vector<str>;
using vec_pointer = std::vector<Car*>;

	bool Radio::operator==(const Radio& other) const {
        return (name == other.name) && (info == other.info) && (cost == other.cost);
    } 

    void Radio::print_radio(){
        std::cout << "Info:" << std::endl;
        std::cout << "Name:" << name <<  std::endl;
        std::cout << "Description:" << info <<  std::endl;
        std::cout << "Cost:" << cost <<  std::endl;
    }


	Garage::Garage() {
	address_ = "Default street";
	std::cout << "ctor default" << std::endl;
	}

	Garage::Garage(str address, std::vector<Radio> avaible_radio, vec_pointer auto_in_garage): address_(address), avaible_radio_(avaible_radio), auto_in_garage_(auto_in_garage){
		std::cout << "ctor param" << std::endl;
	}
	Garage::Garage(const Garage& p) : address_(p.address_), avaible_radio_(p.avaible_radio_), auto_in_garage_(p.auto_in_garage_) {
		std::cout << "ctor copy" << std::endl;
	}
	Garage::~Garage(){
		std::cerr << "dtor" << std::endl;
	}

	void Garage::attach_auto(Car& auto1) {
		if (auto1.get_GOS_number_().size() != 0){
			auto_in_garage_.push_back(&auto1);
		}
		else{
			std::cout << "Car is not exist" << std::endl;
		}
	}
	void Garage::set_radio_in_car(Radio& radio, Car& car1){
		auto is_radio = std::find(avaible_radio_.begin(), avaible_radio_.end(), radio);
		auto is_car = std::find(auto_in_garage_.begin(), auto_in_garage_.end(), &car1);
		if ((is_radio != avaible_radio_.end()) && 
			(is_car != auto_in_garage_.end())) {
                car1.set_radio(radio);
				avaible_radio_.erase(is_radio);
		}
		else{
			std::cout << "Radio can not be installed" << std::endl;
		}
	}
	void Garage::print_info_garage(){
        std::cout << "=============" << std::endl;
		std::cout << "Garage info:" << std::endl;
		std::cout <<"Address:" <<address_ << std::endl;
        std::cout <<"Avaible radios:"<< std::endl;
        for (int i = 0; i < avaible_radio_.size(); i++){
			std::cout<< i+1 << " " << avaible_radio_[i].name << " ";
		}
		std::cout << std::endl;
        std::cout <<"Autos in garage:" << std::endl;
		for (int i = 0; i < auto_in_garage_.size(); i++){
			std::cout<< i+1 << " " << auto_in_garage_[i]->get_car_name_() << " ";
		}
		std::cout << std::endl;
        std::cout << "=============" << std::endl;
	}
    void Garage::print_avaible_radios(){
        std::cout << "Avaible radios" << std::endl;
        for (int i = 0; i < avaible_radio_.size(); i++){
			std::cout<< i+1 << " " << avaible_radio_[i].name << " ";
		}
        std::cout << std::endl;
    }
    void Garage::print_autos_in_garage(){
        std::cout << "Autos in garage" << std::endl;
		for (int i = 0; i < auto_in_garage_.size(); i++){
			std::cout<< i+1 << " " << auto_in_garage_[i]->get_car_name_() << " ";
		}
		std::cout << std::endl;
    }

