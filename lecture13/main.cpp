#include <iostream>
#include <vector>
#include <algorithm>

// size_t - самый большой беззнаковый тип (unsigned long long)
//size_t fact(int n) {
//	if (n == 0)
//		return 1;
//	return fact(n - 1) * n;
//}
//size_t fibo(int n) {
//	if (n == 0)
//		return 0;
//	if (n == 1 || n == 2)
//		return 1;
//	return fibo(n - 2) + fibo(n - 1);
//}
int main(){
	//std::cout << fact(10) << std::endl;
	//// Посчитать число Фибоначчи
	//int fibo[100];
	//fibo[0] = 0;
	//fibo[1] = 1;
	//int n = 10;
	//for (int i = 2; i <= n; i++)
	//	fibo[i] = fibo[i - 1] + fibo[i - 2];
	//std::cout << fibo[n] << std::endl;
	std::vector<int> vec;
	std::sort(vec.begin(), vec.end(), std::less<int>()) // less - сортировка по возрастанию, greater - по убыванию ( по умолчанию стоит less)
	
	
	return 0;
}




