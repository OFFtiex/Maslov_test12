#include <iostream>
#include <vector>

//Лекция 10
void foo(int& x) {
	x = 15;
}
void bar(int* x) {
	*x = 15;
}
//array-to-pointer-castr
void alpha(int* arr) {
	std::cout << sizeof(arr) << std::endl;
}
int main() {

	/*
	const int N = 10; // Константа

	const int x = 15;
	const int* px = &x; // Указатель на константу(Нельзя меять значение, можно менять адрес)

	int y = 5;
	int* const py = &y; // Константный указатель(Нельзя менять адрес, можно менять значение)

	const int* const pz = &x; // Константный указатель на констатнту(Нельзя менять значение, нельзя менять адрес)
	*/

	/*
	int x = 10;
	bar(&x);          // Способ как передать значаение внутрь функции и поменять его
	std::cout << x << std::endl;
	*/
	/*
	int x = 10;
	int& rx = x; // ссылка(другое имя для переменной x)
	const int y = 5;
	const int& ry = y; // Ссылка на конснтанту, а говорят - константная ссылка 
	foo(rx);  // Способ как передать значаение внутрь функции и поменять его
	std::cout << rx << std::endl;
	*/
	/*
	// Массив фиксированной длины
	int arr[20] = { 1, 2, 3, 4, 5, 6 };
	std::cout << *arr << std::endl; // первый элемент массива arr[0]
	std::cout << *(arr+1) << std::endl; // второй элемент массива arr[1]
	std::cout << sizeof(arr) << std::endl;
	alpha(arr); // передача массива в функцию

	// Динамический массив 
	int* arr_dyn = new int[20];
	*(arr_dyn+1) = 0; // arr_dyn[0] = 0
	alpha(arr_dyn);
	delete[] arr_dyn;
	*/

	// Вектор(динамич. массив)

	using Vector = std::vector <int>;
	Vector vec(20); // стек 24/32 байта, хип
	vec.reserve(100'000);
	vec.reserve(1000'0000);
	vec[1] = 10;
	vec[2] = 12;
}




