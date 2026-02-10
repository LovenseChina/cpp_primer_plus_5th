#include <cstring>
#include <iostream>
#include "b_plorg.h"

Bplorg::Bplorg() {
	CI = 50;
	std::strcpy(name, "Plorga");
}

Bplorg::Bplorg(const char *n) {
	CI = 50;
	std::strncpy(name, n, Len - 1);
	name[Len - 1] = '\0';
}

void Bplorg::setCI(int ci) { CI = ci; }

void Bplorg::showplorg() const { std::cout << "Name: " << name << "\nCI = " << CI << std::endl; }
