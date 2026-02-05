#pragma once
#include <vector>
#include <string>

using str = std::string;
using vec = std::vector<str>;

class Car {
protected:
	str car_model_;
	str car_name_;
private:
	str GOS_number_;
	vec baggage_;
public:
	Car();
	Car(str car_name, str car_model, str GOS_number, vec baggage);
	Car(const Car& p);
		
	Car& operator=(const Car& other);
	~Car();
	Car operator+(const Car& other) const;
	Car operator-(const Car& other) const;
	Car operator/(const Car& other) const;
	void set_GOS_number_(str number);
	void set_car_name(str number);
	void set_car_model(str number);
	str get_car_name_() const;
	str get_car_model_() const;
	str get_GOS_number_() const;
	void print_info();
	};