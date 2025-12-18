#include <iostream>
#include <forward_list>


//Лекция 11

struct Node {
	int data;
	Node* next;
};

Node* MAKE(int value) {
	Node* p = new Node;
	p->data = value; // -> <=> *.
	return p; 
}

void ADD(Node* head, int value) {
	Node* p = MAKE(value);
	p->next = head->next;
	head->next = p;
}

void PRINT(Node* head) {
	Node* p = head->next;
	while (p != nullptr) {
		std::cout << p->data << std::endl;
		p = p->next;
	}
}

void DELETE_ODD(Node* head) {
	Node* p = head;
	while (p->next != nullptr) {
		if (p->next->data % 2 == 1) {
			Node* tmp = p->next;
			p->next = p->next->next;
			delete tmp;
		}
		else {
			p = p->next;
		}
	}
}

void CLEAR(Node* head) {
	Node* p = head;
	while (p->next != nullptr) {
		Node* tmp = p->next;
		p->next = p->next->next;
		delete tmp;
	}
}

void DUPLICATE_EVEN(Node* head) {
	Node* p = head->next;
	while (p != nullptr) {
		if (p->data % 2 == 0) {
			ADD(p, p->data);
			p = p->next;
		}
		p = p->next;
	}
}
int main(){
	Node head;
	head.next = nullptr; 
	ADD(&head, 1);
	ADD(&head, 2);
	ADD(&head, 3);
	ADD(&head, 4);
	ADD(&head, 5);
	DUPLICATE_EVEN(&head);
	PRINT(&head);
	DELETE_ODD(&head);
	PRINT(&head);
	CLEAR(&head);

	// Сложность алгоритма - это зависимость кол-ва операций от входных данных
	/*
	int n;
	std::cin >> n;
	int arr[100];

	// n = 10 -> O(n) - 10
	// n = 10 -> )O(n - 100   // O(n) - сложность алгоритма 
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	// O(n*n)
	for (int i = 0; i < n - 1; i++) //n-1
		for (int j = i + 1; j < n; j++) // n/2
			if (arr[i] < arr[j])
				std::swap(arr[i], arr[j]);

	// O(sqrt(n))
	for(int d = 2; d <= sqrt(x); d++) //  Простота числа 
		if (x % 2 == 0) {

		}

	// Удаление нечетн элементов( O(n))
	// 1 2 3 4 5
	int i = 0;
	int j = 0;
	while (i < n) {
		if (arr[i] % 2 == 0) {   
			arr[j] == arr[i];
			j++;
		}
		i++;
	}
	n = j;

	// Дублирование  O(n^2)
	// 1 2 3 4 5
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 1) {
			for (int j = n - 1; j >= i; j--)
				arr[j + 1] = arr[j];
			i++;
			n++;
		}
	}
		
	
	// n = 1000
	// M = 100'000'000 оп/cek
	// T1 = 1/100 cek - время работы алгоритма
	// n = 1'000'000 
	// T2 = 10'000 cek
	*/
	return 0;
}




