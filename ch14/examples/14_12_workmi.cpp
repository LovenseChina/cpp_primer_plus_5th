#include <iostream>
#include <cstring>
//#include "workermi.h"
#include "14_10_workermi.h"
const int SIZE = 5;

int main() {
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;

	Worker *lolas[SIZE];
	int ct;
	for (ct = 0; ct < SIZE; ++ct) {
		char choices;
		cout << "Enter the employee category:\n"
			<< "w: waiter	s: singer	"
			<< "t: singing waiter	q: quit\n";
		cin >> choices;
		while (strchr("wstq", choices) == nullptr) {
			cout << "Please enter a w, s, t or q: ";
			cin >> choices;
		}
		if (choices == 'q')
			break;
		switch (choices) {
			case 'w': lolas[ct] = new Waiter;
				break;
			case 's': lolas[ct] = new Singer;
				break;
			case 't': lolas[ct] = new SingingWaiter;
				break;
		}
		cin.get();
		lolas[ct]->Set();
	}

	cout << "\nHere is your staff:\n";
	int i;
	for (i = 0; i < ct; ++i) {
		cout << endl;
		lolas[i]->Show();
	}
	for (i = 0; i < ct; ++i)
		delete lolas[i];
	cout << "Bye.\n";
	return 0;
}
