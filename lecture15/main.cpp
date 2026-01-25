#include <iostream>




// ООП
// 1 принцип - Абстракция 
// 2 прицип - Инкапсуляция
// x, y
// struct - хранение
// class - хранение, описывает поведения 

class Car {

public:

	
	Car(int n) :arr_(new int[n_]), n_(n) {
		std::cerr << "ctor" << std::endl; 
	}
	~Car() {
		delete[] arr_;
		std::cerr << "dtor" << std::endl;
	}
	
	Car(int x, int y, float r) : x_(x), y_(y), r_(r) { // 
		std::cerr << "ctor param" << std::endl;

	}
	// Метод
	void move() {
		x_ += 10;
		y_ += 10;
	}
	
	// Сеттер 
	void set_r(float r) {
		
		if (r < 0.01) {
			throw std::invalid_argument("Radius have to be positive");
		}
		r_ = r;
	}
	int get_x() const { return x_; }
private:
	bool is_radius_valid(float r) {
		if (r < 0.01) {
			throw std::invalid_argument("Radius have to be positive");
		}
	}
private:
	int x_ = 10; // Поле
	int y_;
	float r_;
	int n_;
	int* arr_;
};

void intersect(const Car& c1, const Car& c2) {
	c1.get_x();
}

int main() {
	try {

		//Car car(100); // объект/экземпляр класса 
		//std::cerr << "===" << std::endl;
		//car.set_r(10);
		//std::cerr << "===" << std::endl
		Car* car = new Car(100);
		delete car;
	} catch (const std::invalid_argument& ex) {
		std::cerr << ex.what() << std::endl;
		}


}
