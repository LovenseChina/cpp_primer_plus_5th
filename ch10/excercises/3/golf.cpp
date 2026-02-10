#include <iostream>
#include <cstring>
#include "golf.h"

Golf::Golf(const char *fn, int hc) {
	std::strncpy(fullname, fn, Len - 1);
	fullname[Len - 1] = '\0';
	handicap = hc;
}

bool Golf::setgolf() {
	std::cout << "Enter full name (empty line to terminate this process): ";
	char temp[Len];
	temp[Len - 1] = '\0';
	std::cin.getline(temp, Len - 1);
	if(std::strcmp(temp, "") == 0)
		return false;
	else {
		std::strcpy(fullname, temp);
		std::cout << "Enter handicap level: ";
		std::cin >> handicap;
		std::cin.get();
		return true;
	}
}

void Golf::resethandicap(int hc) {
	handicap = hc;
}

void Golf::showgolf() const {
	std::cout << "--------------------\n"
		<< "Full name: " << fullname
		<< ", Handicap level: " << handicap << std::endl;
}
