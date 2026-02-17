#include "bop.h"
#include <cstring>

Port::Port(const char *br, const char *st, int b): bottles(b) {
	brand = new char[strlen(br) + 1];
	strcpy(brand, br);
	strncpy(style, st, 19);
	style[19] = '\0';
}

Port::Port(const Port &p): bottles(p.bottles) {
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
}

Port &Port::operator=(const Port &p) {
	if (this == &p)
		return *this;
	if (brand)
		delete []brand;
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;
	return *this;
}

Port &Port::operator+=(int b) {
	bottles += b;
	return *this;
}

Port &Port::operator-=(int b) {
	if (bottles >= b)
		bottles -= b;
	else
		cerr << "ERROR-- invalid operand.\n";
	return *this;
}

void Port::Show() const { cout << "Brand: " << brand << "\nKind: " << style << "\nBottles: " << bottles << endl; }

ostream &operator<<(ostream &os, const Port &p) { 
	os << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}

VintagePort::VintagePort(): year(-1) {
	nickname = new char[5];
	strcpy(nickname, "none");
}

VintagePort::VintagePort(const char *br, const char *st, int b, const char *nn, int y): Port(br, st, b), year(y) {
	nickname = new char[strlen(nn) + 1];
	strcpy(nickname, nn);
}

VintagePort::VintagePort(const VintagePort &vp): Port(vp), year(vp.year) {
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
}

VintagePort &VintagePort::operator=(const VintagePort &vp) {
	if (this == &vp)
		return *this;
	Port::operator=(vp);
	if (nickname)
		delete []nickname;
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
	return *this;
}

void VintagePort::Show() const {
	Port::Show();
	cout << "Nickname: " << nickname << "\nYear: " << year << endl;
}

ostream &operator<<(ostream &os, const VintagePort &vp) {
	os << (const Port &)vp;
	os << ", " << vp.nickname << ", " << vp.year;
	return os;
}
