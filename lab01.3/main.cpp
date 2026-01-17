#include <iostream>
#include <string>

// Поля: марка, модель, номер кузова, гос. номер, пробег.
// Методы:  геттеры на все, сеттеры на гос номер и номер кузова, вывод всей информации, скручивание пробега на Х.

using str = std::string;

class Car {
	public:
	Car(str car_name = "BMW", str car_model = "X5", str body_number = "AFDDFR234", str GOS_number = "T123AA10", int mileage = 1234) : car_name_(car_name), car_model_(car_model), body_number_(body_number), GOS_number_(GOS_number), mileage_(mileage) {
		std::cerr << "ctor param" << std::endl;
	}
	Car(const Car &p)  : car_name_(p.car_name_), car_model_(p.car_model_), body_number_(p.body_number_), GOS_number_(p.GOS_number_), mileage_(p.mileage_){
		std::cerr << "ctor copy" << std::endl;	
	}
	~Car(){
		std::cerr << "dtor" << std::endl;
	}
	void set_body_number_(){
		str x;
		std::cout << "Enter body number:" << std::endl;
		std::cin >> x;
		if(x.length() > 12 || x.length() < 9 ){
			str error = "The length of body number have to be in the range from 9 to 12";
			throw error;
		}
		body_number_ = x;
	}
	void set_GOS_number_ (){
		str x;
		std::cout << "Enter GOS number:" << std::endl;
		std::cin >> x;
		if(x.length() != 10 ){
			str error = "The length of GOS number have to be in the range from 8 to 9";
			throw error;
		}
		GOS_number_  = x;
	}
	str get_car_name_() const {
		return car_name_;
	}
	str get_car_model_() const {
		return car_model_;
	}
	str get_body_number_() const {
		return body_number_;
	}
	str get_GOS_number_() const {
		return GOS_number_;
	}
	int get_mileage_() const {
		return mileage_;
	}
	void twisting_mileage(){
		int x;
		std::cout << "Enter X:" << std::endl;
		std::cin >> x;
		if(x < 1 ) {
			str error = "X have to be > 0";
			throw error;
		}
		mileage_ = mileage_ - x;
	}
	void print_info(){
		std::cout << "=============" << std::endl;
		std::cout << "Car info" << std::endl;
		std::cout << "Car name: " << car_name_ << std::endl;
		std::cout << "Car model: " << car_model_ << std::endl;
		std::cout << "Body number: " << body_number_ << std::endl;
		std::cout << "GOS number: " << GOS_number_ << std::endl;
		std::cout << "Milege: " << mileage_ << std::endl;
		std::cout << "=============" << std::endl;
	}
	private:
	str car_name_ ;
	str car_model_;
	str body_number_ ;
	str GOS_number_ ;
	int mileage_;
};

int main(){
	Car car{"Land Rover", "Defender", "ABCDE123456", "A123AA456", 2090};
	Car car1{car};
	Car car2;
	int n;
	do {
		std::cout << "=============" << std::endl;
		std::cout << "Menu:" << std::endl;
		std::cout << "1. Get car name" << std::endl;
		std::cout << "2. Get car model" << std::endl;
		std::cout << "3. Get body number" << std::endl;
		std::cout << "4. Get GOS number" << std::endl;
		std::cout << "5. Get car mileage" << std::endl;
		std::cout << "6. Set body number" << std::endl;
		std::cout << "7. Set GOS number" << std::endl;
		std::cout << "8. Twist mileage" << std::endl;
		std::cout << "9. Print info" << std::endl;

		std::cout << "=============" << std::endl;
		std::cout << "What you what to do?" << std::endl;
		std::cin >> n;
		switch(n){
			case 1:
				std::cout << car.get_car_name_() << std::endl;
				break;

			case 2:
				std::cout << car.get_car_model_() << std::endl;
				break;

			case 3:
				std::cout << car.get_body_number_() << std::endl;
				break;

			case 4:
				std::cout << car.get_GOS_number_() << std::endl;
				break;

			case 5:
				std::cout << car.get_mileage_() << std::endl;
				break;
				
			case 6:
				try {
					car.set_body_number_();
				} catch(str error) {
					std::cerr << error << std::endl;
				}
				break;

			case 7:
				try {
					car.set_GOS_number_();
				} catch(str error) {
					std::cerr << error << std::endl;
				}
				break;

			case 8:
				try {
				car.twisting_mileage();
				} catch ( str error){
					std::cerr << error << std::endl;
				}
				break;
			case 9:
				car.print_info();
				break;
				
			default:
				std::cout << "Invalid value" << std::endl;
				break;

		}
	} while (n !=0);
	return 0;
}

