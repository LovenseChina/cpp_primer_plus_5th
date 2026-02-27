#include "definations.h"

void Store::operator()(const std::string &s) {
	int len = s.size();
	ofr.write((char *)&len, INTLEN);	// Write by byte.
	ofr.write(s.c_str(), len);
}

void GetStrs(std::ifstream &ifs, std::vector<std::string> &ves) {
	int len;
	char ch;
	std::string temp;
	while (ifs.read((char *)&len, INTLEN)) {
		temp.clear();
		for  (int i = 0; i < len; ++i) {
			ifs.get(ch);
			temp += ch;
		}
		ves.push_back(temp);
 	}
}
