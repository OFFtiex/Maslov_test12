#include <iostream>
#include "func.hpp"


//Лекция 7

int main() {
	std::cout << mt::isPrime(11) << std::endl;
	return 0;
}



/*
void swap(int& a, int& b) {		// & - означает, что если переменная изменена внутри функции, то она будет изменена и в не ее
	int tmp = a;
	a = b;
	b = tmp;												// Функция swap													
}

void swap(float& a, float& b) {
	float tmp = a;
	a = b;
	b = tmp;												// Функция swap			
}
// Перегрузка функций - две функции названы одинаково, но тип аргумента различается (РАЗЛИЧИЕ ИДЕТ ЧЕРЕЗ АРГУМЕНТЫ)
*/


