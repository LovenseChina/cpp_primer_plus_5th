#include<iostream>
#include<string>
using namespace std;

void toupper_string(string &s);

int main() {
	string buf;
	cout << "Enter a string (q to quit): ";
	getline(cin, buf);
	while (buf != "q") {
		toupper_string(buf);
		cout << buf << endl;
		cout << "Next string (q to quit): ";		
		getline(cin, buf);
	} 
	cout << "Bye.\n";
	return 0;
}

void toupper_string(string &s) {
	for (int i = 0; i < s.size();  ++i) 
		s[i] = toupper(s[i]);
}
