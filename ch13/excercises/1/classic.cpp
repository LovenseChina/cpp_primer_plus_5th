#include <iostream>
#include <cstring>
#include "classic.h"

Cd::Cd(const char *s1, const char *s2, int n, double x): selections(n), playtime(x) {
	std::strncpy(performers, s1, 49);
	performers[49] = '\0';
	std::strncpy(lable, s2, 19);
	lable[19] = '\0';
}

Cd::Cd(const Cd &d): selections(d.selections), playtime(d.playtime) {
	std::strcpy(performers, d.performers);
	std::strcpy(lable, d.lable);
}

Cd::Cd() {
	std::strcpy(performers, "Nullbody");
	std::strcpy(lable, "None");
	selections = 0;
	playtime = 0.0;
}

Cd::~Cd() {}

void Cd::Report() const {
	std::cout << "Performers: " << performers << std::endl;
	std::cout << "Lable: " << lable << std::endl;
	std::cout << "Selections: " << selections << std::endl;
	std::cout << "Playtime: " << playtime << std::endl;
}

Cd &Cd::operator=(const Cd &d) {
	if (this == &d)
		return *this;
	std::strcpy(performers, d.performers);
	std::strcpy(lable, d.lable);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}

Classic::Classic(const char *s0, const char *s1, const char *s2, int n, double x):
	Cd(s1, s2, n, x) {
	std::strncpy(mainWorks, s0, 49);
	mainWorks[49] = '\0';	
}

Classic::Classic(const Classic &c): Cd(c) { std::strcpy(mainWorks, c.mainWorks); }

Classic::Classic(): Cd() { std::strcpy(mainWorks, "Null"); }

Classic::~Classic() {}

void Classic::Report() const {
	Cd::Report();
	std::cout << "Main Works: " << mainWorks << std::endl;
}

Classic &Classic::operator=(const Classic &c) {
	if (this == &c)
		return *this;
	Cd::operator=(c);
	std::strcpy(mainWorks, c.mainWorks);
	return *this;
}
