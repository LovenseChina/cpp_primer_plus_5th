#include <iostream>
#include <cstring>
#include "stock2.h"

Stock::Stock() {
	company = new char[8];
	std::strcpy(company, "no name");
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const Stock &s) {
	company = new char[std::strlen(s.company) + 1];
	std::strcpy(company, s.company);
	shares = s.shares;
	share_val = s.share_val;
	total_val = s.total_val;
}

Stock &Stock::operator=(const Stock &s) {
	if (&s == this)
		return *this;
	if (company)
		delete []company;
	company = new char[std::strlen(s.company) + 1];
	std::strcpy(company, s.company);
	shares = s.shares;
	share_val = s.share_val;
	total_val = s.total_val;
	return *this;
}

Stock::Stock(const char *co, int n, double pr) {
	company = new char[std::strlen(co) + 1];
	std::strcpy(company, co);
	if(n < 0) {
		std::cerr << "Number of shares can't be negative; "
			<< company << " share set to 0.\n";
		shares = 0;
	} else
		shares = n;
	share_val = pr;
	set_tot();
}

Stock::~Stock() {
	if (company)
		delete []company;
}

void Stock::buy(int num, double price) {
	if (num < 0) {
		std::cerr << "Number of shares purchased can't be negative. "
			<< "Transacetion is aborted.\n";
	} else {
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(int num, double price) {
	using std::cerr;
	if (num < 0) {
		cerr << "Number of shares sold can't be negative. "
			<< "Transaction is aborted.\n";
	} else if (num > shares) {
		cerr << "You can't sell more than you have! "
			<< "Transaction is aborted.\n";
	} else {
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price) {
	share_val = price;
	set_tot();
}

std::ostream &operator<<(std::ostream &os, const Stock &s) {
	using std::endl;
	os << "Company: " << s.company
		<< "	Shares: " << s.shares << endl
		<< "	Share Price: " << s.share_val
		<< "	Total Worth: " << s.total_val << endl;
	return os;
}

const Stock &Stock::topval(const Stock &s) const {
	if (s.total_val > total_val)
		return s;
	else
		return *this;
}
