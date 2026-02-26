#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char *argv[]) {
	if (argc != 3) {
		std::cout << "Usage: " << argv[0] << " filename1 filename2\nfilename1<src> filename2<dest>\n";
		return 0;
	}
	std::ifstream fin;
	fin.open(argv[1], std::ios_base::in | std::ios_base::binary);
	if (!fin.is_open()) {
		std::cerr << "Can't open file: filename1 -- " << argv[1] << std::endl;
		std::exit(EXIT_FAILURE);
	}
	std::ofstream fout;
	fout.open(argv[2], std::ios_base::out | std::ios_base::binary);
	if (!fout.is_open()) {
		std::cerr << "Can't open file: filename2 -- " << argv[2] << std::endl;
		std::exit(EXIT_FAILURE);
	}
	char byte;
	while (!fin.eof()) {
		fin.get(byte);
		if (fin.eof())
			break;
		fout.put(byte);
	}
	fin.close();
	fout.close();
	return 0;
}
