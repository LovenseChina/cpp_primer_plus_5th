#include <iostream>
#include <string>
#include <iterator>

int main() {
	using namespace std;
	string example;
	bool flag;
	cout << "Enter a string (quit to quit): ";
	getline(cin, example);
	while (example != "quit") {
		flag = true;
		string reverse;
		copy(example.rbegin(), example.rend(), insert_iterator<string>(reverse, reverse.begin()));
		cout << "example: " << example << endl
			<< "reverse: " << reverse << endl;
		string::iterator it1, it2;
		for (it1 = example.begin(), it2 = reverse.begin(); it1 != example.end(); ++it1, ++it2)
			if (*it1 != *it2) {
				flag = false;
				break;
			}
		if (flag)
			cout << "TRUE\n";
		else
			cout << "FALSE\n";
		cout << "\n\nEnter next string: ";
		getline(cin, example);
	}
	cout << "Program terminated.\n";
	return 0;
}
