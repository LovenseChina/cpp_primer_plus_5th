#include <iostream>
#include "cow.h"

int main() {
	using namespace std;
	Cow c1;
	Cow c2("Jessie", "Gangbang, basketball, anal sex, milking...", 100.0);
	Cow c3 = c1;
	Cow c4 = Cow(c2);
	c1 = Cow("Jasmine", "play games...", 95.0);

	cout << "c1 information:\n";
	c1.ShowCow();
	cout << "c2 information:\n";
	c2.ShowCow();
	cout << "c3 information:\n";
	c3.ShowCow();
	cout << "c4 information:\n";
	c4.ShowCow();
	return 0;
}
