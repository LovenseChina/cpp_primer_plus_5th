#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "vector.h"
int main() {
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	
	fstream fout;
	fout.open("file", ios::out);
	if(!fout) {
		cerr << "File open failed! Abort." << endl;
		return 1;
	}
	cout << "Enter target distance (q to quit): ";
	while (cin >> target) {
		cout << "Enter step length: ";
		if(!(cin >> dstep))
			break;
		while (result.magval() < target) {
			direction = rand() % 360;
			step.set(dstep, direction, 'p');
			result = result + step;
			++steps;
		}
		fout << "After " << steps << " steps, the subject "
			<< "has the following location: \n";
		fout << result << endl;
		result.polar_mode();
		fout << " or\n" << result << endl;
		fout << "Average outward distance per step = "
			<< result.magval() / steps << endl;
		steps = 0;
		result.set(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";
	fout.close();
	return 0;
}
