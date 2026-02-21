#include "tv.h"
#include <iostream>

int main() {
	using std::cout;
	using std::endl;

	Tv t(Tv::On);
	Remote r;
	cout << "check Tv...\n";
	t.settings();
	cout << endl;
	cout << "check Remote...\n";
	r.show_state();
	cout << endl;
	cout << "change Remote state...\n";
	t.chanRstate(r);
	cout << "check Remote...\n";
	r.show_state();
	cout << endl;
	cout << "Tv off... and change Remote state...\n";
	r.onoff(t);
	t.chanRstate(r);
	cout << "check Tv...\n";
	t.settings();
	cout << endl;
	cout << "check Remote state...\n";
	r.show_state();
	cout << endl;
	return 0;
}
