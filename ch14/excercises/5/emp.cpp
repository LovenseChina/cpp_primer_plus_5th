#include "emp.h"

typedef std::string string;

abstr_emp::abstr_emp(): fname("none"), lname("none"), job("none") {}

abstr_emp::abstr_emp(const string &fn, const string &ln, const string &j):
	fname(fn), lname(ln), job(j) {}

void abstr_emp::ShowAll() const {
	std::cout << "Name: " << lname << " " << fname << std::endl;
	std::cout << "Job: " << job << std::endl;
}

void abstr_emp::SetAll() {
	std::cout << "Enter first name: ";
	std::getline(std::cin, fname);
	std::cout << "Enter last name: ";
	std::getline(std::cin, lname);
	std::cout << "Enter job: ";
	std::getline(std::cin, job);
}

std::ostream &operator<<(std::ostream &os, const abstr_emp &e) {
	os << e.lname << " " << e.fname << ", " << e.job << '\n';
	return os;
}

abstr_emp::~abstr_emp() {}

employee::employee() {}

employee::employee(const string &fn, const string &ln, const string &j):
	abstr_emp(fn, ln, j) {}

void employee::ShowAll() const { abstr_emp::ShowAll(); }

void employee::SetAll() { abstr_emp::SetAll(); }

manager::manager(): inchargeof(-1) {}

manager::manager(const string &fn, const string &ln, const string &j, int ico):
	abstr_emp(fn, ln, j), inchargeof(ico) {}

manager::manager(const abstr_emp &e, int ico): abstr_emp(e), inchargeof(ico) {}

void manager::ShowAll() const {
	abstr_emp::ShowAll();
	std::cout << "In Charge Of: " << inchargeof << '\n';
}

void manager::SetAll() {
	abstr_emp::SetAll();
	std::cout << "Enter how many people in charge of: ";
	std::cin >> inchargeof;
	std::cin.get();
}

fink::fink(): reportsto("none") {}

fink::fink(const string &fn, const string &ln, const string &j, const string &rpo):
	abstr_emp(fn, ln, j), reportsto(rpo) {}

fink::fink(const abstr_emp &e, const string &rpo): abstr_emp(e), reportsto(rpo) {}

fink::fink(const fink &e): abstr_emp(e) { reportsto = e.reportsto; }

void fink::ShowAll() const {
	abstr_emp::ShowAll();
	std::cout << "Who To Report: " << reportsto << std::endl;
}

void fink::SetAll() {
	abstr_emp::SetAll();
	std::cout << "Enter who to report: ";
	std::getline(std::cin, reportsto);
}

highfink::highfink() {}

highfink::highfink(const string &fn, const string &ln, const string &j, const string &rpo, int ico):
	abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {}

highfink::highfink(const abstr_emp &e, const string &rpo, int ico):
	abstr_emp(e), manager(e, ico), fink(e, rpo) {}

highfink::highfink(const fink &f, int ico):
	abstr_emp(f), manager((const abstr_emp &)f, ico), fink(f) {}

highfink::highfink(const manager &m, const string &rpo):
	abstr_emp(m), manager(m), fink((const abstr_emp &)m, rpo) {}

highfink::highfink(const highfink &h):
	abstr_emp(h), manager(h), fink(h) {}

void highfink::ShowAll() const{
	abstr_emp::ShowAll();
	std::cout << "In Charge Of: " << InChargeOf() << '\n';
	std::cout << "Who To Report: " << ReportsTo() << '\n';
}

void highfink::SetAll() {
	abstr_emp::SetAll();
	std::cout << "Enter how many people in charge of: ";
	std::cin >> InChargeOf();
	std::cin.get();
	std::cout << "Enter who to report: ";
	std::getline(std::cin, ReportsTo());
}
