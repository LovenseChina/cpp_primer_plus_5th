#include "qtemp.h"
#include "workermi.h"
#include <iostream>

int main() {
	using std::cin;
	using std::cout;
	using std::endl;
	Queue<Worker *, 4> wq;
	Worker *ptr = nullptr;
	
	while (!wq.isfull()) {
		cout << "Enter worker category: \n"
			<< "waiter(w), singer(s) or singing waiter(c): ";
		char choices;
		cin >> choices;
		cin.get();
		switch  (choices) {
			case 'w':
			case 'W':
				ptr = new Waiter;
				ptr->Set();
				break;
			case 's':
			case 'S':
				ptr = new Singer;
				ptr->Set();
				break;
			case 'c':
			case 'C':
				ptr = new SingingWaiter;
				ptr->Set();
				break;
			default:
				continue;
		}
		wq.enqueue(ptr);
		ptr = nullptr;
	}
	std::cout << std::endl;
	while (!wq.isempty()) {
		wq.dequeue(ptr);
		ptr->Show();
		delete ptr;
		ptr = nullptr;
		std::cout << std::endl;
	}
	return 0;
}
