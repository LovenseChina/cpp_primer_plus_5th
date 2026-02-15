#include <cstring>
#include <cctype>
#include "string2.h"
using std::cin;
using std::cout;

int String::num_strings = 0;

int String::HowMany() { return num_strings; }

String::String(const char *s) {
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	++num_strings;
}

String::String() {
	len = 0;
	str = new char[1];
	str[0] = '\0';
	++num_strings;
}

String::String(const String &st) {
	++num_strings;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
}

String::~String() {
	--num_strings;
	delete []str;
}

String &String::operator=(const String &st) {
	if (this == &st)
		return *this;
	delete []str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

String &String::operator=(const char* s) {
	delete []str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

char &String::operator[](int i) { return str[i]; }

const char &String::operator[](int i) const { return str[i]; }

bool operator<(const String &st1, const String &st2) { return std::strcmp(st1.str, st2.str) < 0; }

bool operator>(const String &st1, const String &st2) { return std::strcmp(st1.str, st2.str) > 0; }

bool operator==(const String &st1, const String &st2) { return std::strcmp(st1.str, st2.str) == 0; }

ostream &operator<<(ostream &os, const String &st) {
	os << st.str;
	return os;
}

istream &operator>>(istream &is, String &st) {
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while(is && is.get() != '\n')
		continue;
	return is;
}

const String operator+(const String &st1, const String &st2) {
	int total_len = st1.len + st2.len;
	char *s = new char[total_len + 1];
	int i = 0;
	for (; i < st1.len; ++i)
		s[i] = st1.str[i];
	for (; i < total_len; ++i)
		s[i] = st2.str[i - st1.len];
	s[total_len] = '\0';
	String ret(s);
	delete []s;
	return ret;
}

void String::stringlow() {
	for (int i = 0; i < len; ++i)
		str[i] = std::tolower(str[i]);
}

void String::stringup() {
	for (int i = 0; i < len; ++i)
		str[i] = std::toupper(str[i]);
}

int String::has(char c) const {
	int count = 0;
	for (int i = 0; i < len; ++i)
		count = c == str[i] ? count + 1 : count;
	return count;
}
