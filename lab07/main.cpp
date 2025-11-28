#include <iostream>
#include <vector>
#include <array>
#include <algorithm>


using Vector = std::vector<int>;
using Array = std::array<int, 10>;
// Пункт 1 

void sort1(Array arr) {
	int n = 10;
	 for(int i = 0; i < n-1; i++)
		 for(int j = i+1; j < n; j++)
			 if (arr[i] > arr[j]) {
				 std::swap(arr[i], arr[j]);
			 }
	//std::sort(arr.begin(), arr.end());
	//std::cout << "Addres in the function: " << &arr << std::endl;
}
void sort2(Array& arr) {
	int n = 10;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] > arr[j]) {
				std::swap(arr[i], arr[j]);
			}
	//std::sort(arr.begin(), arr.end());
	//std::cout << "Addres in the function: " << &arr << std::endl;
}
void sort3(Array* arr) {
	int n = 10;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if ((*arr)[i] > (*arr)[j]) {
				std::swap((*arr)[i], (*arr)[j]);
			}
	/*std::sort((*arr).begin(), (*arr).end()); */
	//std::cout << "Addres in the function: " << arr << std::endl;
}





/*
void null() {
	std::cout << "Finish" << std::endl;
}
void first(const Vector& vec) {
	std::cout << "Vector: [ ";
	for (int i = 0;  i < vec.size(); i++) {
		std::cout << vec[i]  << " ";
	}
	std::cout << "]" << std::endl;
}
void second(Vector& vec) {
	int x;
	std::cout << "Enter the element of vector: " << std::endl;
	std::cin >> x;
	vec.insert(vec.begin(), x);
}
void third(Vector& vec) {
	int x;
	std::cout << "Enter the element of vector: " << std::endl;
	std::cin >> x;
	vec.push_back(x);
}
void fourth(Vector& vec) {
	vec.clear();
}
void fifth(Vector& vec) {
	int x;
	std::cout << "Enter the index of the element of vector: " << std::endl;
	std::cin >> x;
	if (x >= vec.size()) {
		std::cout << "Incorrect index" << std::endl;
	}
	else {
		std::cout << vec[x] << std::endl;
	}
}
void sixth(Vector& vec) {
	first(vec);
	if (vec.size() % 2 == 0) {
		vec.erase(vec.begin());
	}
	else {
		if (vec.size() >= 4) {
			vec.erase(vec.end() - 4, vec.end());
		}
		else {
			vec.erase(vec.end() - vec.size(), vec.end());
		}
	}
	first(vec);
}
*/

int main() {
	/*
	int num;
	Vector vec;
	vec.reserve(100'000);

	do {
		std::cout << "Menu" << std::endl;
		std::cout << "0 - Exit" << std::endl;
		std::cout << "1 - Show a vector" << std::endl;
		std::cout << "2 - Add element in the start of the vector" << std::endl;
		std::cout << "3 - Add element in the end of the vector" << std::endl;
		std::cout << "4 - Clear the vector" << std::endl;
		std::cout << "5 - Find the element" << std::endl;
		std::cout << "6 - Delete elements" << std::endl;
		std::cout << "Number: " << std::endl;
		std::cin >> num;

		switch (num) {
		case 0: 
			break;
		case 1:
			int i;
			first(vec);
			break;
		case 2:
			second(vec);
			break;
		case 3:
			third(vec);
			break;
		case 4:
			fourth(vec);
			break;
		case 5:
			fifth(vec);
			break;
		case 6:
			sixth(vec);
			break;
		default:
			std::cout << "Inccorect command" << std::endl;
		}
	} while (num != 0);
	
	null();
	*/

	// Пункт 2

	Array arr = { 0, 3, 5, 9, 4, 1, 6, 8, 7, 2 };

	std::cout << "Array:" << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;


	sort1(arr);
	std::cout << "Sorted Array by value(-):" << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	arr = { 0, 3, 5, 9, 4, 1, 6, 8, 7, 2 };

	std::cout << "Array:" << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;


	sort2(arr);
	std::cout << "Sorted Array by link(+):" << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	arr = { 0, 3, 5, 9, 4, 1, 6, 8, 7, 2 };

	std::cout << "Array:" << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;


	sort3(&arr);
	std::cout << "Sorted Array by pointer(+):" << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;



	return 0;
}

