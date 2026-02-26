#include <iostream>
const int LIM = 128;
int main() {
	std::cout << "Enter a line, and this program will count characters number in front of the first $ (empty line to quit).\n"
		"Now, enter the line: ";
	long ct = 0;
	char ch;
	while (std::cin.peek() != '$') {
		std::cin.get(ch);
		++ct;
	}
	std::cout << "Total: " << ct << "\nNext character: " << (char)std::cin.get() << std::endl;
}
