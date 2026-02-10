#include "stack.h"
#include <iostream>
using namespace std;

int main() {
	Stack s;
	customer cs[11] = {
		{"Sir. A", 100},
		{"Sir. B", 80},
		{"Sir. C", 25},
		{"Sir. D", 70},
		{"Sir. E", 120},
		{"Sir. F", 45},
		{"Sir. G", 185},
		{"Sir. H", 15},
		{"Sir. I", 35},
		{"Sir. J", 95},
		{"Sir. K", 105}
	};

	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);
	cout.precision(2);
	cout << "------------------------------\n";

	double total_pay = 0;
	for(int i = 0; s.push(cs[i++]);)
		cout << "Customer #" << i << " waiting to pay...\n";
	cout << "------------------------------\n";

	customer paid;
	while(s.pop(paid)) {
		cout << "Customer " << paid.fullname << " paid $" << paid.payment << endl;
		total_pay += paid.payment;
		cout << "Curently total $" << total_pay << endl;
	}
	cout << "------------------------------\n";
	return 0;
}
