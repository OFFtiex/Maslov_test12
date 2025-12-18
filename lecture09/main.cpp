#include <iostream>

//Лекция 8

int main() {
	// new/delete
	int* p = new int(10);
	std::cout << *p << std::endl;
	delete p;
}



