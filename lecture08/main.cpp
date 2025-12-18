#include <iostream>

//Лекция 8

int main() {
	// "Сырой" указатель  = raw pointer
	int x = 1000;
	int y = 1;
	// x = a*256^0 + b*256^1 + c*256*2 + d*256^3
	// a = (1000/256^0) % 256 = 232
	// b = (1000/256^1) % 256 = 3
	// c = (1000/256^2) % 256 = 0
	// d = (1000/256^3) % 256 = 0
	// 
	// указатенль - переменная, хранящая адрес и тип другой переменной (int*)
	// размер указателя - 8 байт (64-бит. система)
	int* px = &x;
	int* py = &y; // & - берем адрес переменной, перед которой стоит &

	// операция взятия адреса
	std::cout << &x << std::endl;
	std::cout << &y << std::endl;
	std::cout << &px << std::endl;
	std::cout << &py << std::endl;

	// разыменование
	std::cout << *px << std::endl; // из адреса берем значение переменной
	std::cout << *py << std::endl;

	// выделение памяти
	int* pz;
	pz = new int; // дай нам место под тип int
	*pz = 10;
	char* pc = (char*)pz; // Memory leak (утечка памяти)
	
	std::cout << &pz << std::endl;
	std::cout << pz << std::endl;
	delete pz;
	// some code
	// delete pz; // double free

	int* ptr = new int;
	*ptr = 2;
	std::cout << ptr << std::endl;
	std::cout << *ptr << std::endl; // undefined behavior 
	delete ptr;
	std::cout << ptr << std::endl;
	std::cout << *ptr << std::endl;

	std::cout << "Finish" << std::endl;
}



