#include <iostream>
#include <numbers>


//Лекция 5

int main() {
	// Массивы
	int x[5];
	x[0] = 5;
	x[1] = 1;
	x[2] = 2;
	x[3] = 50;
	x[4] = 10;
	
	for (int i = 0; i < 4; ++i) {
		for (int j = i + 1 ; j < 5; ++j) {
			if (x[i] > x[j]) {
				std::swap(x[i], x[j]);
			}
		}
	}
	for (int n = 0; n < 5; ++n) {
		std::cout << x[n] << std::endl;
	}

	
return 0;
}



