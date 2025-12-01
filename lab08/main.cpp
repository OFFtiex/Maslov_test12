#include <iostream>
#include <forward_list>
#include <string>
#include <vector>


using str = std::string;

struct Books {
	str Author;
	str Title;
	int Number;
	int Pages;
	Books* next;
};

Books* MAKE(str author, str title, int number, int pages) {
	Books* p = new Books;
	p->Author = author;
	p->Title = title;
	p->Number = number;
	p->Pages = pages;
	return p;
}

void ADD(Books* head, str author, str title, int number, int pages) {
	Books* p = MAKE( author, title, number, pages);
	p->next = head->next;
	head->next = p;
}

void PRINT(Books* head) {
	Books* p = head->next;
	while (p != nullptr) {
		std::cout << "Book:" << std::endl;
		std::cout << "Author - " << p->Author << std::endl;
		std::cout << "Title - " << p->Title << std::endl;
		std::cout << "Tome - " << p->Number << std::endl;
		std::cout << "Pages - " << p->Pages << std::endl;
		p = p->next;
	}
}

void FINDMAX(Books* head, str author, str n) {
	Books* p = head->next;
	Books* maxBook = nullptr;
	if (n == "max") {
		int maxPages = -1;
		while (p != nullptr) {
			if (p->Author == author && p->Pages > maxPages) {
				maxPages = p->Pages;
				maxBook = p;
			}
			p = p->next;
		}
	}
	else{
		int minPages = 1000000;
		while (p != nullptr) {
			if (p->Author == author && p->Pages < minPages) {
				minPages = p->Pages;
				maxBook = p;
			}
			p = p->next;
		}
	}
	if (maxBook != nullptr) {
		std::cout << maxBook->Title << " " << maxBook->Number << " " << maxBook->Pages << std::endl;
	}
}

void ADDCRTN(Books* head, str author, str title, int number, int pages) {
	Books* new1 = MAKE(author, title, number, pages);
	Books* p1 = head->next;
	if (head->next == nullptr) {
		return;
	}

	while (p1 != nullptr) {
		if (p1->Author == author && p1->Number == number) {
			std::cout << "The book has already been added" << std::endl;
			delete new1;
			return;
		}
		p1 = p1->next;
	}
	if (head->next->Author == author && head->next->Number > number) {
		new1->next = head->next;
		head->next = new1;
		return;
	}
	Books* p = head->next;
	while (p->next != nullptr) {
		if (p->next->Author == author && p->next->Number > number) {
			new1->next = p->next;
			p->next = new1;
			return;
		}
		p = p->next;
	}
	p->next = new1;
}

void SUMMERQUEUE(Books* head) {

	std::vector<Books*> allBooks;
	Books* p = head->next;
	while (p != nullptr) {
		allBooks.push_back(p);
		p = p->next;
	}
	int n;
	std::vector<Books*> summerBooks;
	do {
		std::cout << "Enter the number of the book (Enter 0 to exit)" << std::endl;
		std::cin >> n;
		if (n != 0)
			summerBooks.push_back(allBooks[n - 1]);
	} while (n != 0);
	std::cout << "Books in the summer queue:" << std::endl;
	for (int i = 0; i < summerBooks.size(); i++) {
		Books* book = summerBooks[i];
		std::cout << i+1 << ". " << book->Author << " " << book->Title << " " << book->Number << std::endl;
	}
}
void null() {
	std::cout << "Finish" << std::endl;
}

int main() {
	Books head;
	head.next = nullptr;
	ADD(&head, "Tolstoy", "War and Peace", 4, 202);
	ADD(&head, "Tolstoy", "War and Peace", 2, 322);
	ADD(&head, "Tolstoy", "War and Peace", 1, 308);
	ADD(&head, "Sholokhov", "The Silent Don", 4, 427);
	ADD(&head, "Sholokhov", "The Silent Don", 1, 386);
	ADD(&head, "Rowling", "Harry Potter", 6, 607);
	ADD(&head, "Rowling", "Harry Potter", 3, 317);
	ADD(&head, "Sapkowski", "The Witcher", 5, 416);
	ADD(&head, "Sapkowski", "The Witcher", 2, 384);

	int num;
	do {
		std::cout << "Menu" << std::endl;
		std::cout << "0 - Exit" << std::endl;
		std::cout << "1 - Show books" << std::endl;
		std::cout << "2 - Add element " << std::endl;
		std::cout << "3 - Find the most difficult/the easiest book" << std::endl;;
		std::cout << "4 - Add the certain book " << std::endl;
		std::cout << "5 - Create a summer queue " << std::endl;
		std::cin >> num;
		str author, title, name, n;
		int number, pages;

		switch (num) {
		case 0:
			break;
		case 1:
			PRINT(&head);
			break;
		case 2:
			std::cout << "Enter info:" << std::endl;
			std::cin >> author >> title >> number >> pages;
			ADD(&head, author, title, number, pages);
			break;
		case 3:

			std::cout << "Enter author and max or min you need to find: " << std::endl;
			std::cin >> name >> n;
			FINDMAX(&head, name, n);
			break;
		case 4:
			std::cout << "Enter info:" << std::endl;
			std::cin >> author >> title >> number >> pages;
			ADDCRTN(&head, author, title, number, pages);
			break;
		case 5:
			SUMMERQUEUE(&head);
			break;
		default:
			std::cout << "Inccorect command" << std::endl;
		}
	} while (num != 0);
	null();


	return 0;
}

