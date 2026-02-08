#include<iostream>

inline double squre(double x) { return x * x; }

int main() {
	using namespace std;
	double a, b;
	double c = 13.0;

	a = squre(5.0);
	b = squre(4.5 + 7.5);
	cout << "a = " << a << ", b = " << b << "\n";
	cout << "c = " << c;
	cout << ", c squreed = " << squre(c++) << "\n";
	cout << "Now c = " << c << "\n";
	return 0;
}
