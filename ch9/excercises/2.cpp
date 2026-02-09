#include<iostream>
//const int ArSize = 10;

//void strcount(const char *str);

#include<string>
using namespace std;
void strcount(const string &);
int main() {
	//using namespace std;
	//char input[ArSize];
	//char next;
	string input;
	cout << "Enter a line: \n";
	//cin.get(input, ArSize);
	getline(cin, input);
	//while(cin) {
	//	cin.get(next);
	//	while (next != '\n')
	//		cin.get(next);
	//	strcount(input);
	//	cout << "Enter next line (empty line to quit): \n";
	//	cin.get(input, ArSize);
	//}
	while(input != "") {
		strcount(input);
		cout << "Enter next line (empty to quit): \n";
		getline(cin, input);
	}
	cout << "Bye\n";
	return 0;
}

/*
void strcount(const char *str) {
	using namespace std;
	static int total = 0;
	int count = 0;

	cout << "\"" << str << "\" contains ";
	while(*str++)
		++count;
	total += count;
	cout << count << " characters\n";
	cout << total << " characters total\n";
}
*/

void strcount(const string &s) {
	static int total = 0;
	cout << "\"" << s << "\" contains " << s.size()
		<< " characters\n";
	total += s.size();
	cout << total << " characters total\n";
}
