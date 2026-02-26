#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main() {
	std::cout << "Specify a file name: ";
	std::string filename;
	std::getline(std::cin, filename);
	std::ofstream fout(filename.c_str(), std::ios_base::out);
	if (!fout.is_open()) {
		std::cerr << "Error! Can't open file " << filename << "\nProgram terminated!\n";
		std::exit(EXIT_FAILURE);
	}
	std::cout << "Now enter something and this program will put it in that file (<Ctrl + D> to finish).\n";
	char ch;
	while (std::cin.get(ch) && !std::cin.eof())
		fout.put(ch);
	fout.close();
	return 0;
}
