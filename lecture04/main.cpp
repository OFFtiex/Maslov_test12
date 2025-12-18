#include <iostream>
#include <numbers>


//Лекция 4

int main() {
	
	/*int x = 10; // 32 бита 0b000...1010
	x & (1<<3)											// Как выяснить чему равен определенный бит числа
	// & 0b000...1010
	//	 0b000...1000
	//   0b000...1000 != 0 == true  */


	/*
	int i = 1; // iterator (переменная-счетчик)
	while (i <= 10) { // проверка условия               // while
		std::cout << i << std::endl;
		++i; // инкремент счетчик
	} // в фигурных скобках - тело счетчика
	*/


	/*
	for (int i = 1; i <= 10; ++i) {						// for
		std::cout << i << std::endl;
	}


	for (int i = 1;; ++i) {                             // бесконечный for (условие должно быть пустым)
		std::cout << i << std::endl;
	}
	*/


	/*
	bool isPrime = true;
	int x = 4;
	if (x < 2) {
		std::cout << x << " is not prime" << std::endl;
	}
	else {
		for (int d = 2; d <= sqrt(x); ++d) {
			if (x % d == 0) {							// определение простоты числа
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			std::cout << x << " is prime" << std::endl;
		}
		else {
			std::cout << x << " is not prime" << std::endl;
		}
	}
	*/
return 0;
}



