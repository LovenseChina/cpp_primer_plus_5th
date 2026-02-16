#include <iostream>
#include <cstring>
#include "classic.h"

Cd::Cd(const char *s1, const char *s2, int n, double x): selections(n), playtime(x) {
	performers = new char[std::strlen(s1) + 1];
	std::strcpy(performers, s1);
	lable = new char[std::strlen(s2) + 1];
	std::strcpy(lable, s2);
}

Cd::Cd(const Cd &d): selections(d.selections), playtime(d.playtime) {
	performers = new char[std::strlen(d.performers) + 1];
	std::strcpy(performers, d.performers);
	lable = new char[std::strlen(d.lable) + 1];
	std::strcpy(lable, d.lable);
}

Cd::Cd() {
	performers = new char[9];
	std::strcpy(performers, "Nullbody");
	lable = new char[5];
	std::strcpy(lable, "None");
	selections = 0;
	playtime = 0.0;
}

Cd::~Cd() {
	if (performers)
		delete []performers;
	if (lable)
		delete []lable;
}

void Cd::Report() const {
	std::cout << "Performers: " << performers << std::endl;
	std::cout << "Lable: " << lable << std::endl;
	std::cout << "Selections: " << selections << std::endl;
	std::cout << "Playtime: " << playtime << std::endl;
}

Cd &Cd::operator=(const Cd &d) {
	if (this == &d)
		return *this;
	if (performers)
		delete []performers;
	performers = new char[std::strlen(d.performers) + 1];
	std::strcpy(performers, d.performers);
	if (lable)
		delete []lable;
	lable = new char[std::strlen(d.lable) + 1];
	std::strcpy(lable, d.lable);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}

Classic::Classic(const char *s0, const char *s1, const char *s2, int n, double x):
	Cd(s1, s2, n, x) {
	mainWorks = new char[std::strlen(s0) + 1];
	std::strcpy(mainWorks, s0);
}

Classic::Classic(const Classic &c): Cd(c) {
	mainWorks = new char[std::strlen(c.mainWorks) + 1];
	std::strcpy(mainWorks, c.mainWorks);
}

Classic::Classic(): Cd() {
	mainWorks = new char[5];
	std::strcpy(mainWorks, "Null");
}

Classic::~Classic() {
	if (mainWorks)
		delete []mainWorks;
}

void Classic::Report() const {
	Cd::Report();
	std::cout << "Main Works: " << mainWorks << std::endl;
}

Classic &Classic::operator=(const Classic &c) {
	if (this == &c)
		return *this;
	Cd::operator=(c);
	if (mainWorks)
		delete []mainWorks;
	mainWorks = new char[std::strlen(c.mainWorks) + 1];
	std::strcpy(mainWorks, c.mainWorks);
	return *this;
}
