#include "winec.h"
#include "cstdlib"
//Here can be replaced by class template

Wine::Pair::Pair(int y, const int yr[], const int bot[]):
	years(yr, y), bottles(bot, y) {}

Wine::Pair::Pair(int y): years(y), bottles(y) {}

void Wine::GetBottles() {
	std::cout << "Enter " << lable << " data for " << year << " year(s):\n";
	for (int i = 0; i < year; ++i) {
		std::cout << "Enter year: ";
		std::cin >> p.first()[i];
		if (!std::cin)
			std::exit(EXIT_FAILURE);
		std::cout << "Enter bottles for that year: ";
		std::cin >> p.second()[i];
		if (!std::cin)
			std::exit(EXIT_FAILURE);
	}
}

void Wine::Show() const {
	std::cout << "Wine: " << lable << std::endl;
	std::cout << "	Year	Bottles\n";
	for (int i = 0; i < year; ++i)
		std::cout << "	" << p.first()[i] << "	" << p.second()[i] << std::endl;
}
