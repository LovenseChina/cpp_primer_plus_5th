#ifndef DEFINATIONS_H_
#define DEFINATIONS_H_
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

const int INTLEN = 4;

inline void ShowStr(const std::string &s) { std::cout << s << std::endl; }

class Store {
	std::ofstream & ofr;
public:
	Store(std::ofstream &ofs): ofr(ofs) {}
	void operator()(const std::string &s);
};

void GetStrs(std::ifstream &ifs, std::vector<std::string> &ves);
#endif
