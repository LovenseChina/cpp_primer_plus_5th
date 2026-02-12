#include <iostream>
using std::cout;
#include "stonewt.h"

const int _LBS = 0;
const int _STN = 1;

void display(const Stonewt &st, int n);
int main() {
	Stonewt pavarotti = 260;
	Stonewt wolfe(287.5);
	Stonewt taft(21, 8, _LBS);

	cout << "The tenor weighed: ";
	//pavarotti.show_stn();
	pavarotti.changemode(_STN);
	cout << pavarotti;
	cout << "The detective weighed: ";
	wolfe.changemode(_STN);
	cout << wolfe;
	cout << "The President weighed: ";
	cout << taft;
	pavarotti = 265.8;
	taft = 325;
	cout << "After dinner, the tenor weighed: ";
	pavarotti.changemode(_STN);
	cout << pavarotti;
	cout << "After dinner, the President weighed: ";
	cout << taft;
	taft.changemode(_STN);
	display(taft, 2);
	cout << "The wrestler weighed even more.\n";
	display(422, 2);
	cout << "No stone left unearned\n";
	return 0;
}

void display(const Stonewt &st, int n) {
	for (int i = 0; i < n; ++i) {  
		cout << "Wow! ";
		cout << st;
	}
}
