#include <iostream>
#include <set>
#include <string>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <cstdlib>

int main() {
	using std::set;
	using std::string;
	using std::getline;
	using std::copy;
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ifstream;
	using std::ofstream;
	using std::ios_base;
	using std::exit;
	using std::cerr;
	
	string temp;
	set<string> Mat, Pat, MP;
	ifstream iMat("mat.dat", ios_base::in),
		iPat("pat.dat", ios_base::in);
	ofstream oMatnPat("matnpat.dat", ios_base::out);
	
	cout << "Reading from \"mat.dat\"...\n";
	while (getline(iMat, temp))
		Mat.insert(temp);
	if (!iMat.eof()) { 
		cerr << "Read from \"mat.dat\" failed!\n";
		exit(EXIT_FAILURE);
	} else
		iMat.clear();
	cout << "Read \"mat.dat\" complete\n";
	
	cout << "Reading from \"pat.dat\"...\n";
	while (getline(iPat, temp)) 
		Pat.insert(temp);
	if (!iPat.eof()) {
		cerr << "Read from \"pat.dat\" failed!\n";
		exit(EXIT_FAILURE);
	} else
		iPat.clear();
	cout << "Read \"pat.dat\" complete\n";

	cout << "Union \"mat.dat\" & \"pat.dat\" into \"matnpat.dat\"...\n";
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
	
	cout << "Write into \"matnpat.dat\"...\n";
	set<string>::iterator it;
	for (it = MP.begin(); it != MP.end(); ++it) {
		temp = *it;
		oMatnPat << temp << endl;
	}

	iMat.close();
	iPat.close();
	oMatnPat.close();
	cout << "Program executed.\n";
	return 0;
}
