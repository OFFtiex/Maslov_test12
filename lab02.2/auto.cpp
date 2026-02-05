#include "auto.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>


using str = std::string;
using vec = std::vector<str>;




Car::Car() {
	baggage_ = {"Default item1", "Default item2", "Default item3"};
	car_name_ = "Default name";
	car_model_ = "Defaul model";
	GOS_number_ = "A111AA";
	std::cerr << "ctor default" << std::endl;
}
Car::Car(str car_name, str car_model, str GOS_number, vec baggage) : car_name_(car_name), car_model_(car_model), GOS_number_(GOS_number),
	baggage_(baggage) {
	std::cerr << "ctor param" << std::endl;
}
Car::Car(const Car& p) : car_name_(p.car_name_), car_model_(p.car_model_), GOS_number_(p.GOS_number_), baggage_(p.baggage_) {
	std::cerr << "ctor copy" << std::endl;
}
Car& Car::operator=(const Car& other){
	if (this != &other){
		car_name_ = other.car_name_;
		car_model_ = other.car_model_;
		GOS_number_ = other.GOS_number_;
		vec tmp = other.baggage_;
		baggage_ = tmp;
		tmp.clear();
		std::cout << "The operator= is called" << std::endl;
	}
	return *this;
}
Car::~Car() {
	baggage_.clear();
	std::cerr << "dtor" << std::endl;
}
Car Car::operator+(const Car& other) const{
	Car result;
	int rand_bool1 = rand()%2;
	if (rand_bool1){
		result.car_name_ = this->car_name_;
	}
	else{
		result.car_name_ = other.car_name_;
	}
	int rand_bool2= rand()%2;
	if (rand_bool2){
		result.car_model_ = this->car_model_;
	}
	else{
		result.car_model_ = other.car_model_;
	}
	const size_t Start_Digits= 48;
	const size_t End_Digits = 57; 
	const size_t Start_Letters = 65;
	const size_t End_Letters = 90;
	str new_gos_number;
	new_gos_number += static_cast<char>(rand()%(End_Letters - Start_Letters +1) + Start_Letters);
	new_gos_number += static_cast<char>(rand()%(End_Digits - Start_Digits +1) + Start_Digits);
	new_gos_number += static_cast<char>(rand()%(End_Digits - Start_Digits +1) + Start_Digits);
	new_gos_number += static_cast<char>(rand()%(End_Digits - Start_Digits +1) + Start_Digits);
	new_gos_number += static_cast<char>(rand()%(End_Letters - Start_Letters +1) + Start_Letters);
	new_gos_number += static_cast<char>(rand()%(End_Letters - Start_Letters +1) + Start_Letters);
	result.GOS_number_ = new_gos_number;
	if ((this->baggage_.size() != 0) || (other.baggage_.size() != 0)){
		result.baggage_ = this->baggage_;
		result.baggage_.reserve(this->baggage_.size() + other.baggage_.size());
		result.baggage_.insert(result.baggage_.end(), other.baggage_.begin(), other.baggage_.end());
		for(int i = 0; i < result.baggage_.size()-1; i++){
			for(int j = 1;j < result.baggage_.size();j++ ){
				if(result.baggage_[i] == result.baggage_[j])
					std::swap(result.baggage_[j],result.baggage_[i+1]);
			}
		}
	}
	else {
		result.baggage_ = {"Empty"};
	}
	return result;
}
Car Car::operator-(const Car& other) const{
	Car result;
	int rand_bool1 = rand()%2;
	if (rand_bool1){
		result.car_name_ = this->car_name_;
	}
	else{
		result.car_name_ = other.car_name_;
	}
	int rand_bool2= rand()%2;
	if (rand_bool2){
		result.car_model_ = this->car_model_;
	}
	else{
		result.car_model_ = other.car_model_;
	}
	const size_t Start_Digits= 48;
	const size_t End_Digits = 57;
	const size_t Start_Letters = 65;
	const size_t End_Letters = 90;
	str new_gos_number;
	new_gos_number += static_cast<char>(rand()%(End_Letters - Start_Letters +1) + Start_Letters);
	new_gos_number += static_cast<char>(rand()%(End_Digits - Start_Digits +1) + Start_Digits);
	new_gos_number += static_cast<char>(rand()%(End_Digits - Start_Digits +1) + Start_Digits);
	new_gos_number += static_cast<char>(rand()%(End_Digits - Start_Digits +1) + Start_Digits);
	new_gos_number += static_cast<char>(rand()%(End_Letters - Start_Letters +1) + Start_Letters);
	new_gos_number += static_cast<char>(rand()%(End_Letters - Start_Letters +1) + Start_Letters);
	result.GOS_number_ = new_gos_number;
	if ((this->baggage_.size() == 0) && (other.baggage_.size() == 0)){
		result.baggage_ = {"Empty"};
	}
	else {
		result.baggage_ = this->baggage_;
		result.baggage_.reserve(this->baggage_.size() + other.baggage_.size());
		result.baggage_.insert(result.baggage_.end(), other.baggage_.begin(), other.baggage_.end());
		for(int i = 0; i < result.baggage_.size()-1; i++){
			for(int j = 1;j < result.baggage_.size();j++ ){
				if(result.baggage_[i] == result.baggage_[j])
					std::swap(result.baggage_[j],result.baggage_[i+1]);
			}
		}
		auto last = std::unique(result.baggage_.begin(), result.baggage_.end());
		result.baggage_.erase(last,result.baggage_.end());
	}
	return result;
}
Car Car::operator/(const Car& other) const{
	Car result;
	int rand_bool1 = rand()%2;
	if (rand_bool1){
		result.car_name_ = this->car_name_;
	}
	else{
		result.car_name_ = other.car_name_;
	}
	int rand_bool2= rand()%2;
	if (rand_bool2){
		result.car_model_ = this->car_model_;
	}
	else{
		result.car_model_ = other.car_model_;
	}
	const size_t Start_Digits= 48;
	const size_t End_Digits = 57; 
	const size_t Start_Letters = 65;
	const size_t End_Letters = 90;
	str new_gos_number;
	new_gos_number += static_cast<char>(rand()%(End_Letters - Start_Letters +1) + Start_Letters);
	new_gos_number += static_cast<char>(rand()%(End_Digits - Start_Digits +1) + Start_Digits);
	new_gos_number += static_cast<char>(rand()%(End_Digits - Start_Digits +1) + Start_Digits);
	new_gos_number += static_cast<char>(rand()%(End_Digits - Start_Digits +1) + Start_Digits);
	new_gos_number += static_cast<char>(rand()%(End_Letters - Start_Letters +1) + Start_Letters);
	new_gos_number += static_cast<char>(rand()%(End_Letters - Start_Letters +1) + Start_Letters);
	result.GOS_number_ = new_gos_number;
	if ((this->baggage_.size() == 0) && (other.baggage_.size() == 0)){
		result.baggage_ = {"Empty"};
	}
	else {
		vec sorted_this = this->baggage_;
		vec sorted_other = other.baggage_;
		std::sort(sorted_this.begin(), sorted_this.end());
		std::sort(sorted_other.begin(), sorted_other.end());
		result.baggage_.clear();
		std::set_intersection(sorted_this.begin(), sorted_this.end(), sorted_other.begin(), sorted_other.end(), std::back_inserter(result.baggage_));
	}
	return result;
	}
void Car::set_GOS_number_(str number) {
	if (number.length() != 6) {
		str error = "The length of GOS number have to be 6";
		throw error;
	}
	str letters = "QWERTYUIOPASDFGHJKLZXCVBNM";
	str digits = "1234567890";
	str error = "Gos number must be: A123AA";
	if (letters.find(number[0]) == std::string::npos) {
		throw error;
	}
	if (digits.find(number[1]) == std::string::npos) {
		throw error;
	}
	if (digits.find(number[2]) == std::string::npos) {
		throw error;
	}
	if (digits.find(number[3]) == std::string::npos) {
		throw error;
	}
	if (letters.find(number[4]) == std::string::npos) {
		throw error;
	}
	if (letters.find(number[5]) == std::string::npos) {
		throw error;
	}
	GOS_number_ = number;
}
void Car::set_car_name(str number) {
	str alph = "WERTYUPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";
	for (int i = 0; i < number.length(); i++) {
		if (alph.find(number[i]) == std::string::npos) {
			str error = "Invalid symbol";
			throw error;
		}
	}
	car_name_ = number;
}
void Car::set_car_model(str number) {
	str alph = "WERTYUPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890";
	for (int i = 0; i < number.length(); i++) {
		if (alph.find(number[i]) == std::string::npos) {
			str error = "Invalid symbol";
			throw error;
		}
	}
	car_model_ = number;
}
str Car::get_car_name_() const {
	return car_name_;
}
str Car::get_car_model_() const {
	return car_model_;
}
str Car::get_GOS_number_() const {
	return GOS_number_;
}
void Car::print_info() {
	std::cout << "=============" << std::endl;
	std::cout << "Car info" << std::endl;
	std::cout << "Car name: " << car_name_ << std::endl;
	std::cout << "Car model: " << car_model_ << std::endl;
	std::cout << "GOS number: " << GOS_number_ << std::endl;
	std::cout << "Baggage: ";
	for(int i = 0; i < baggage_.size(); i++){
		std::cout << baggage_[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "=============" << std::endl;
}
