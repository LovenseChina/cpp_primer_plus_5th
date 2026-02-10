#include "move.h"
#include <iostream>

int main() {
	using namespace std;
	Move m1;
	cout << "Now position of m1:\n";
	m1.showmove();
	cout << "Set position of m1:\n";
	m1.reset(1.0, 2.0);
	m1.showmove();
	Move m2(-3.0, 4.0);
	cout << "Another position m2:\n";
	m2.showmove();
	Move m3 = m1.add(m2);
	cout << "m1 + m2 = m3:\n";
	m3.showmove();
	return 0;
}
