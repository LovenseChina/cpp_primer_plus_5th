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

//layout: or <base_layout>
//<int len_f><fname>
//<int len_l><lname>
//<int len_j><job>
void abstr_emp::WriteAll(std::ofstream &ofs) const {
	int len_f = fname.size(),
		len_l = lname.size(),
		len_j = job.size();

	ofs.write((char *)&len_f, sizeof(int));
	ofs.write(fname.c_str(), len_f);

	ofs.write((char *)&len_l, sizeof(int));
	ofs.write(lname.c_str(), len_l);

	ofs.write((char *)&len_j, sizeof(int));
	ofs.write(job.c_str(), len_j);
}

abstr_emp::~abstr_emp() {}

employee::employee() {}

employee::employee(const string &fn, const string &ln, const string &j):
	abstr_emp(fn, ln, j) {}

void employee::ShowAll() const { abstr_emp::ShowAll(); }

void employee::SetAll() { abstr_emp::SetAll(); }

void employee::WriteAll(std::ofstream &ofs) const {
	int tag = EMP;
	ofs.write((char *)&tag, sizeof(int));

	abstr_emp::WriteAll(ofs);
}

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

//layout:
//<int tag>
//<int inchargeof>
//<base_layout>
void manager::WriteAll(std::ofstream &ofs) const {
	int tag = MAN;
	ofs.write((char *)&tag, sizeof(int));

	ofs.write((char *)&inchargeof, sizeof(int));
	
	abstr_emp::WriteAll(ofs);
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

//layout:
//<int tag>
//<len_r><reportsto>
//<base_layout>
void fink::WriteAll(std::ofstream &ofs) const {
	int tag = FIN;
	ofs.write((char *)&tag, sizeof(int));
	
	int len_r = reportsto.size();
	ofs.write((char *)&len_r, sizeof(int));
	ofs.write(reportsto.c_str(), len_r);

	abstr_emp::WriteAll(ofs);
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

//layout:
//<int tag>
//<int inchargeof>
//<int len_r><reportsto>
//<base_layout>
void highfink::WriteAll(std::ofstream &ofs) const {
	int tag = HFI;
	ofs.write((char *)&tag, sizeof(int));

	int ico = InChargeOf();
	ofs.write((char *)&ico, sizeof(int));

	std::string rpt = ReportsTo();
	int len_r = rpt.size();
	ofs.write((char *)&len_r, sizeof(int));
	ofs.write(rpt.c_str(), len_r);

	abstr_emp::WriteAll(ofs);
}

abstr_emp *emp_creator(std::ifstream &ifs) {
	if (!ifs)
		return nullptr;
	int tag, ico, len_r, len_f, len_l, len_j;
	std::string reportsto, fname, lname, job;
	
	if (!ifs.read((char *)&tag, sizeof(int))) //read eof and just return nullptr
		return nullptr;
	switch (tag) {
		case EMP:
			ifs.read((char *)&len_f, sizeof(int));
			for (int i = 0; i < len_f; ++i)
				fname += ifs.get();
			
			ifs.read((char *)&len_l, sizeof(int));
			for (int i = 0; i < len_l; ++i)
				lname += ifs.get();

			ifs.read((char *)&len_j, sizeof(int));
			for (int i = 0; i < len_j; ++i)
				job += ifs.get();

			return new employee(fname, lname, job);
		case MAN:
			ifs.read((char *)&ico, sizeof(int));

			ifs.read((char *)&len_f, sizeof(int));
			for (int i = 0; i < len_f; ++i)
				fname += ifs.get();

			ifs.read((char *)&len_l, sizeof(int));
			for (int i = 0; i < len_l; ++i)
				lname += ifs.get();

			ifs.read((char *)&len_j, sizeof(int));
			for (int i = 0; i < len_j; ++i)
				job += ifs.get();

			return new manager(fname, lname, job, ico);
		case FIN:
			ifs.read((char *)&len_r, sizeof(int));
			for (int i = 0; i < len_r; ++i)
				reportsto += ifs.get();

			ifs.read((char *)&len_f, sizeof(int));
			for (int i = 0; i < len_f; ++i)
				fname += ifs.get();

			ifs.read((char *)&len_l, sizeof(int));
			for (int i = 0; i < len_l; ++i)
				lname += ifs.get();

			ifs.read((char *)&len_j, sizeof(int));
			for (int i = 0; i < len_j; ++i)
				job += ifs.get();
			return new fink(fname, lname, job, reportsto);
		case HFI:
			ifs.read((char *)&ico, sizeof(int));

			ifs.read((char *)&len_r, sizeof(int));
			for (int i = 0; i < len_r; ++i)
				reportsto += ifs.get();

			ifs.read((char *)&len_f, sizeof(int));
			for (int i = 0; i < len_f; ++i)
				fname += ifs.get();

			ifs.read((char *)&len_l, sizeof(int));
			for (int i = 0; i < len_l; ++i)
				lname += ifs.get();

			ifs.read((char *)&len_j, sizeof(int));
			for (int i = 0; i < len_j; ++i)
				job += ifs.get();

			return new highfink(fname, lname, job, reportsto, ico);
		default:
			return nullptr;
	}
}
