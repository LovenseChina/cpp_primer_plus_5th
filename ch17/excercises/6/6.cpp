#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "emp.h"

inline void ShowMenu() {
	std::cout << "Enter employee tag\n"
		"1: employee	2: manager\n3: fink	4: highfink\nq: quit\n> ";
}

inline void ShowEMP(const abstr_emp *pe) { pe->ShowAll(); }

class WriteEMP {
	std::ofstream &ofr;
public:
	WriteEMP(std::ofstream &ofs): ofr(ofs) {}
	void operator()(const abstr_emp *pe) { pe->WriteAll(ofr); }
};

int main(void) {
	using namespace std;

	cout << "Enter file name: ";
	char filename[128];
	cin.getline(filename, 128);
	ofstream fout(filename, ios_base::out | ios_base::binary);
	if (!fout.is_open()) { 
		cerr << "Can't create/open file: " << filename << "!\n";
		exit(EXIT_FAILURE);
	}
	
	ShowMenu();
	int choice;
	vector<abstr_emp *> abc_ptrs;
	abstr_emp *ptr;
	while (cin >> choice) {
		cin.get();
		switch (choice) {
			case EMP: ptr = new employee;
				break;
			case MAN: ptr = new manager;
				break;
			case FIN: ptr = new fink;
				break;
			case HFI: ptr = new highfink;
				break;
			default:
				cout << "Invalid choice!\n";
				continue;
		}
	ptr->SetAll();
	abc_ptrs.push_back(ptr);
	ShowMenu();
	}
	
	cout << "Here is the information you entered:\n";
	for_each(abc_ptrs.begin(), abc_ptrs.end(), ShowEMP);
	
	cout << "Writing into " << filename << "...\n";
	for_each(abc_ptrs.begin(), abc_ptrs.end(), WriteEMP(fout));
	vector<abstr_emp *>::iterator it;
	for (it = abc_ptrs.begin(); it != abc_ptrs.end(); ++it)
		delete *it;
	abc_ptrs.clear();
	fout.close();

	cout << "Read from " << filename << " and display all:\n";
	ifstream fin(filename, ios_base::in | ios_base::binary);
	if (!fin.is_open()) {
		cerr << filename << " open faild!\n";
		exit(EXIT_FAILURE);
	}
	ptr = nullptr;
	while (ptr = emp_creator(fin))
		abc_ptrs.push_back(ptr);
	for_each(abc_ptrs.begin(), abc_ptrs.end(), ShowEMP);
	for (it = abc_ptrs.begin(); it != abc_ptrs.end(); ++it)
		delete *it;
	abc_ptrs.clear();
	fin.close();

	return 0;
}
