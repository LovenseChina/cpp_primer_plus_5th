#include <iostream>
#include "golf.h"

int main() {
	using namespace std;

	int n;
	cout << "Enter a number to specify number of structure golf: ";
	cin >> n;
	//cin.get();
	golf *pg = new golf[n];
	//int flag = 1;
	for (int i  = 0; i < n; ++i) {
		//if(!flag)
		//	while(cin.get() != '\n');
		//flag = setgolf(pg[i]);
		setgolf(pg[i]);
	}
	cout << "Here's you just entered:\n";
	for (int i = 0; i < n; ++i) {
		cout << "#" << (i + 1) << ": ";
		showgolf(pg[i]);
	}
	cout << "This is hard coded information: \n";
	golf ann;
	setgolf(ann, "Ann Birdfree", 24);
	showgolf(ann);
	handicap(ann, 5);
	cout << "Reset handicap:\n";
	showgolf(ann);
	delete []pg;
	return 0;	
}
