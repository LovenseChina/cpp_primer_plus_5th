#include "dma.h"
#include <cstring>

abcDMA::abcDMA(const char *l, int r) {
	lable = new char[std::strlen(l) + 1];
	std::strcpy(lable, l);
	rating = r;
}

abcDMA::abcDMA(const abcDMA &rs) {
	lable = new char[std::strlen(rs.lable) + 1];
	std::strcpy(lable, rs.lable);
	rating = rs.rating;
}

abcDMA::~abcDMA() {
	if (lable)
		delete []lable;
}

abcDMA &abcDMA::operator=(const abcDMA &rs) {
	if (this == &rs)
		return *this;
	if (lable)
		delete []lable;
	lable = new char[std::strlen(rs.lable) + 1];
	std::strcpy(lable, rs.lable);
	rating = rs.rating;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const abcDMA &rs) {
	os << "Lable: " << rs.lable << std::endl;
	os << "Rating: " << rs.rating << std::endl;
	return os;
}

baseDMA &baseDMA::operator=(const baseDMA &rs) {
	abcDMA::operator=(rs);
	return *this;
}

std::ostream &operator<<(std::ostream &os, const baseDMA &rs) {
	os << (const abcDMA &)rs;
	return os;
}

void baseDMA::Show() const { std::cout << *this; }

lacksDMA::lacksDMA(const char *c, const char *l, int r): abcDMA(l, r) {
	std::strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}

lacksDMA::lacksDMA(const char *c, const baseDMA &rs): abcDMA(rs) {
	std::strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}

std::ostream &operator<<(std::ostream &os, const lacksDMA &rs) {
	os << (const abcDMA&)rs;
	os << "Color: " << rs.color << std::endl;
	return os;
}

void lacksDMA::Show() const { std::cout << *this; }

hasDMA::hasDMA(const char *s, const char *l, int r): abcDMA(l, r) {
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}

hasDMA::hasDMA(const char *s, const baseDMA &rs): abcDMA(rs) {
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA &rs): abcDMA(rs) {
	style = new char[std::strlen(rs.style) + 1];
	std::strcpy(style, rs.style);
}

hasDMA::~hasDMA() {
	if (style)
		delete []style;
}

hasDMA &hasDMA::operator=(const hasDMA &rs) {
	if (this == &rs)
		return *this;
	abcDMA::operator=(rs); // *this = rs; It means that but cannot take an effect.
	style = new char[std::strlen(rs.style) + 1];
	std::strcpy(style, rs.style);
	return *this;
}

std::ostream &operator<<(std::ostream &os, const hasDMA &rs) {
	os << (const abcDMA &)rs;
	os << "Style: " << rs.style << std::endl;
	return os;	
}

void hasDMA::Show() const { std::cout << *this; }
