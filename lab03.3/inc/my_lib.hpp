#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include "..\auto.hpp"


using str = std::string;
using vec = std::vector<str>;
using vec_pointer = std::vector<Car*>;
struct Radio {
	str name;
	str info;
	int cost;
	bool operator==(const Radio& other) const;
    void print_radio();
	};
class Garage{
public:
	Garage();
	Garage(str address, std::vector<Radio> avaible_radio, vec_pointer auto_in_garage);
	Garage(const Garage& p);
	~Garage();

	void attach_auto(Car& auto1);
	void set_radio_in_car(Radio& radio, Car& car1);
	void print_info_garage();
    void print_avaible_radios();
    void print_autos_in_garage();
private:
	str address_;
protected:
	std::vector<Radio> avaible_radio_;
	vec_pointer auto_in_garage_ ;
};