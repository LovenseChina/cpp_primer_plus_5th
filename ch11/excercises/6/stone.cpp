#include <iostream>
using std::cout;
using std::cin;
#include "stonewt.h"
void display(const Stonewt &st, int n);
int main() {
/*
	Stonewt pavarotti = 260;
	Stonewt wolfe(287.5);
	Stonewt taft(21, 8);

	cout << "The tenor weighed: ";
	pavarotti.show_stn();
	cout << "The detective weighed: ";
	wolfe.show_stn();
	cout << "The President weighed: ";
	taft.show_lbs();
	pavarotti = 265.8;
	taft = 325;
	cout << "After dinner, the tenor weighed: ";
	pavarotti.show_stn();
	cout << "After dinner, the President weighed: ";
	taft.show_lbs();
	display(taft, 2);
	cout << "The wrestler weighed even more.\n";
	display(422, 2);
	cout << "No stone left unearned\n";
*/
	Stonewt base(11, 0);
	Stonewt s[6] = {
		Stonewt(12, 5.5),
		Stonewt(7, 2.1),
		Stonewt(120.0)
	};
	for(int i = 3; i < 6; ++i) {
		int choose;
		cout << "Now what's the format you choose? (0: LBS, 1: STN)";
		cin >> choose;
		 if (!choose) {
			cout << "Enter pounds: ";
			double p;
			cin >> p;
			s[i] = Stonewt(p);
		} else {
			cout << "Enter stone: ";
			int st;
			cin >> st;
			cout << "Enter lbs left: ";
			double l;
			cin >> l;
			s[i] = Stonewt(st, l);
		}
	} 

	cout << "----------Now the answers----------\n";
	for (int i =  0; i < 6; ++i) {
		if(s[i] > base) {
			s[i].show_lbs();
			cout << "heavier than\n";
			base.show_lbs();
		} else {
			s[i].show_lbs();
			cout << "lighter than\n";
			base.show_lbs();
		}
		cout << "----------SPLIT----------\n";
	}
	cout << "----------END----------\n";
	return 0;
}

void display(const Stonewt &st, int n) {
	for (int i = 0; i < n; ++i) {
		cout << "Wow! ";
		st.show_stn();
	} 
}
