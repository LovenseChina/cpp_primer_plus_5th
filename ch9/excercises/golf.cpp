#include<iostream>
#include<cstring>
using namespace std;
#include "golf.h"

void setgolf(golf &g, const char *name, int hc) {
	strcpy(g.fullname, name);
	g.handicap = hc;
}

int setgolf(golf &g) {
	while(cin.get() != '\n')
		; 
	cout << "Enter fullname (empty line to ignore this): ";
	cin.getline(g.fullname, Len);
	if(strcmp(g .fullname, "") == 0) {
		g.handicap = 0;
		return 0;
	} else {
		cout << "Enter handicap: ";
		cin >> g.handicap;
		return 1;
	}
}

void handicap(golf &g, int hc) {
	g.handicap = hc;
}

void showgolf(const golf &g) {
	cout << "Fullname: " << g.fullname << ". Handicap: " << g.handicap << ".\n";
}
