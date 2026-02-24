#include <iostream>
#include <set>
#include <string>
#include <iterator>
#include <algorithm>

int main() {
	using std::set;
	using std::string;
	using std::getline;
	using std::copy;
	using std::cin;
	using std::cout;
	using std::endl;
	
	string temp;
	set<string> Mat, Pat, MP;
	
	cout << "It's Mat turn.\nEnter the name (\"quit\" to finish): ";
	getline(cin, temp);
	while (temp != "quit") {
		Mat.insert(temp);
		cout << "Enter the next one (\"quit\" to finish): ";
		getline(cin, temp);
	 }
	cout << "It's Pat turn.\nEnter the name (\"quit\" to finish): ";
	getline(cin, temp);
	while (temp != "quit") {
		Pat.insert(temp);
		cout << "Enter the next one (\"quit\" to finish): ";
		getline(cin, temp);
	}

	cout << "Let combine Mat & Pat's list...\n";
	std::set_union (Mat.begin(), Mat.end(), Pat.begin(), Pat.end(), std::insert_iterator< set<string> >(MP, MP.begin()));
	
	std::ostream_iterator<string, char> out(cout, "\n");
	string mark = "--------------------";
	cout << mark << mark << "\nHere is Mat's list: \n";
	copy(Mat.begin(), Mat.end(), out);
	cout << mark << mark << "\nHere is Pat's list: \n";
	copy(Pat.begin(), Pat.end(), out);
	cout << mark << mark << "\nHere is M & P's list: \n";
	copy(MP.begin(), MP.end(), out);
	cout << mark << mark << endl;

	return 0;
}
