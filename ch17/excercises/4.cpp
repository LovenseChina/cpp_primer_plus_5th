#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

int main(int argc, char *argv[]) {
	if (argc != 4) {
		std::cout << "Usage: " << argv[0] << " filename1 filename2 filename3\nfilename1<src1> filename2<src2> filename3<dest>\n";
		return 0;
	}
	std::ifstream fin1(argv[1], std::ios_base::in | std::ios_base::binary),
		fin2(argv[2], std::ios_base::in | std::ios_base::binary);
	if (!fin1.is_open()) {
		std::cerr << argv[1] << " can't be open!\n";
		std::exit(EXIT_FAILURE);
	}
	if (!fin2.is_open()) {
		std::cerr << argv[2] << " can't be open!\n";
		std::exit(EXIT_FAILURE);
	}
	std::ofstream fout(argv[3], std::ios_base::out | std::ios_base::binary);
	if (!fout.is_open()) {
		std::cerr << argv[3] << " can't be open!\n";
		std::exit(EXIT_FAILURE);
	}
	
	std::string line1, line2;
	std::cout << "Processing file merge...\n";
	while (!fin1.eof() && !fin2.eof()) {
		std::getline(fin1, line1);
		std::getline(fin2, line2);
		fout << line1 << " " << line2 << std::endl;
	}
	while (!fin1.eof()) {
		std::getline(fin1, line1);
		fout << line1 << std::endl;
	}
	while (!fin2.eof()) {
		std::getline(fin2, line2);
		fout << line2 << std::endl;
	}
	if (!fin1.eof()) {
		std::cerr << argv[1] << " read error!\n";
		std::exit(EXIT_FAILURE);
	}
	if (!fin2.eof()) {
		std::cerr << argv[2] << " read error!\n";
		std::exit(EXIT_FAILURE);
	}
	std::cout << "Merge done.\n";
	return 0;
}
