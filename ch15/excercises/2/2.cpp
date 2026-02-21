#include <iostream>
#include <cmath>
#include "exc_mean.h"
//use -std=c++03 to complie

double hmean(double a, double b) throw(bad_hmean);
double gmean(double a, double b) throw(bad_gmean);

int main() {
	using std::cout;
	using std::cin;
	using std::endl;

	double x, y, z;

	cout << "Enter two numbers: ";
	while (cin >> x >> y) {
		try {
			z = hmean(x, y);
			cout << "Harmonic mean of " << x << " and " << y
				<< " is " << z << endl;
			z = gmean(x, y);
			cout << "Geometry mean of " << x << " and " << y
				<< " is " << z << endl;
		} catch (bad_hmean &bg) {
			cout << bg.what();
			cout << "Try again.\n";
			continue;
		} catch (bad_gmean &hg) {
			cout << hg.what();
			cout << "Sorry, you don't get to play any more.\n";
			break;
		}
	}
	cout << "Bye!\n";
	return 0;
}

double hmean(double a, double b) throw(bad_hmean) {
	if (a == -b)
		throw(bad_hmean());
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) throw(bad_gmean) {
	if (a < 0 || b < 0)
		throw(bad_gmean());
	return std::sqrt(a * b);
}
