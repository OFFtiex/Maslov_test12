#include "func.hpp"
#include <cmath>
namespace mt {
	bool isPrime(int x) {
		if (x <= 1) {
			return false;
		}
		for (int d = 2; d <= sqrt(x); ++d) {                    // Функция определение простоты числа
			if (x % d == 0) {
				return false;
			}
		}
		return true;
	}
} // mt