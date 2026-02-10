#include "person.h"
#include <cstring>
#include <iostream>

Person::Person(const string &ln, const char *fn) {
	lname = ln;
	strncpy(fname, fn, LIMIT - 1);
	fname[LIMIT - 1] = '\0';
}

void Person::Show() const {
	cout << fname << " " << lname << endl;	
}

void Person::FormalShow() const {
	cout << lname << ", " << fname << endl;
}
