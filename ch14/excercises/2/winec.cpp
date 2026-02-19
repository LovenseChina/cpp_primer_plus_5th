#include <cstdlib>
#include "winec.h"

void Wine::GetBottles() {
	std::cout << "Enter " << (const string &)*this << " data for " << year << " year(s):\n";
	for (int i = 0; i < year; ++i) {
		std::cout << "Enter year: ";
		std::cin >> ((Pairs &)*this).first()[i];	//first(), second() is also member of Wine, so can just call "first()" and "second()"
		if (!std::cin)
			std::exit(EXIT_FAILURE);
		std::cout << "Enter bottles for that year: ";
		std::cin >> ((Pairs &)*this).second()[i];
		if (!std::cin)
			std::exit(EXIT_FAILURE);
	} 
}

void Wine::Show() const {
	std::cout << "Wine: " << (const string &)*this << std::endl
		<< "	Year	Bottles\n"; 
	for (int i = 0; i < year; ++i)
		std::cout << "	" << ((const Pairs &)*this).first()[i]
			<< "	" << ((const Pairs &)*this).second()[i] << std::endl;
}
