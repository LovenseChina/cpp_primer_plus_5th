#include <iostream>
#include <cstring>
#include "cow.h"

Cow::Cow() {
	std::strcpy(name, "NONE");
	hobby = new char[5];
	std::strcpy(hobby, "NONE");
	weight = 0;
}

Cow::Cow(const char *nm, const char *ho, double wt) {
	if (std::strlen(nm) > 19) {
		std::strncpy(name, nm, 19);
		name[19] = '\0';
	} else
		std::strcpy(name, nm);
	hobby = new char[std::strlen(ho) + 1];
	std::strcpy(hobby, ho);
	weight = wt;
}

Cow::Cow(const Cow &c) {
	std::strcpy(name, c.name);
	//if (hobby)
	//	delete hobby;
	hobby = new char[std::strlen(c.hobby) + 1];
	std::strcpy(hobby, c.hobby);
	weight = c.weight;
}

Cow::~Cow() {
	if (hobby)
		delete []hobby;
}

Cow &Cow::operator=(const Cow &c) {
	if (&c == this)
		return *this;
	std::strcpy(name, c.name);
	if (hobby)
		delete []hobby;
	hobby = new char[std::strlen(c.hobby) + 1];
	std::strcpy(hobby, c.hobby);
	weight = c.weight;
	return *this;
}

void Cow::ShowCow() const {
	std::cout << "Name: " << name
		<< "\nHobby: " << hobby
		<< "\nWeight: " << weight << "kg\n";
}
