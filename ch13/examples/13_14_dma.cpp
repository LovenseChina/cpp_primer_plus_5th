//#include "dma.h"
#include "13_13_dma.h"
#include <cstring>

baseDMA::baseDMA(const char *l, int r) {
	lable = new char[std::strlen(l) + 1];
	std::strcpy(lable, l);
	rating = r;
}

baseDMA::baseDMA(const baseDMA &rs) {
	lable = new char[std::strlen(rs.lable) + 1];
	std::strcpy(lable, rs.lable);
	rating = rs.rating;
}

baseDMA::~baseDMA() {
	if (lable)
		delete []lable;
}

baseDMA &baseDMA::operator=(const baseDMA &rs) {
	if (this == &rs)
		return *this;
	if (lable)
		delete []lable;
	lable = new char[std::strlen(rs.lable) + 1];
	std::strcpy(lable, rs.lable);
	rating = rs.rating;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const baseDMA &rs) {
	os << "Lable: " << rs.lable << std::endl;
	os << "Rating: " << rs.rating << std::endl;
	return os;
}

lacksDMA::lacksDMA(const char *c, const char *l, int r): baseDMA(l, r) {
	std::strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}

lacksDMA::lacksDMA(const char *c, const baseDMA &rs): baseDMA(rs) {
	std::strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}

std::ostream &operator<<(std::ostream &os, const lacksDMA &rs) {
	os << (const baseDMA&)rs;
	os << "Color: " << rs.color << std::endl;
	return os;
}

hasDMA::hasDMA(const char *s, const char *l, int r): baseDMA(l, r) {
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}

hasDMA::hasDMA(const char *s, const baseDMA &rs): baseDMA(rs) {
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA &rs): baseDMA(rs) {
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
	baseDMA::operator=(rs); // *this = rs; It means that but cannot take an effect.
	style = new char[std::strlen(rs.style) + 1];
	std::strcpy(style, rs.style);
	return *this;
}

std::ostream &operator<<(std::ostream &os, const hasDMA &rs) {
	os << (const baseDMA &)rs;
	os << "Style: " << rs.style << std::endl;
	return os;	
}
