#include <iostream>
#include "golf.h"
using namespace std;

int main() {
	Golf g[4] = {
		{"Andy", 1},
		{"Maya", 2},
		{"Lucy", 3},
		{"Jack", 4}
	};
	for (int i = 0; i < 4; ++i)
		g[i].showgolf();
	cout << "Now you can reset these information upon.\n";
	for (int i = 0; i < 4; ++i)
		if(!g[i].setgolf())
			break;
	for (int i = 0; i < 4; ++i)
		g[i].showgolf();
	cout << "Now reset g[1].handicap: ";
	int hc;
	cin >> hc;
	g[1].resethandicap(hc);
	g[1].showgolf();
	return 0;
}
