#include <iostream>
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
	
	int sim_times;
	double total_steps = 0;
	unsigned long max_steps;
	unsigned long min_steps;
	Vector max_result;
	Vector min_result;
	cout << "Enter simulation times: ";
	cin >> sim_times;
	cout << "Enter target distance: ";
	cin >> target;
	cout << "Enter step length: ";
	cin >> dstep;
	for (int i = 0; i < sim_times; ++i) {
		while (result.magval() < target) { // this while() is for simulation
			direction = rand() % 360;
			step.set(dstep, direction, 'p');
			result = result + step;
			++steps;
		}
		/*
		cout << "After " << steps << " steps, the subject "
			<< "has the following location: \n";
		cout << result << endl;
		result.polar_mode();
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = "
			<< result.magval() / steps << endl;
		*/
		if (i == 0) {
			min_steps = max_steps = steps;
			min_result = max_result = result;
		} else {
			if (steps > max_steps) {
				max_steps = steps;
				max_result = result;
			}
			if (steps < min_steps) {
				min_steps = steps;
				min_result = result;
			}
		}
		total_steps += steps;
		steps = 0;
		result.set(0.0, 0.0);
	}
	
	cout << sim_times << " times simulation stats:\n";
	cout << "Total steps: " << total_steps << ". Average steps: " << total_steps / sim_times << endl;
	cout << "After Max steps " << max_steps << " steps, the subject "
		<< "has the following location: \n";
	cout << max_result << endl;
	max_result.polar_mode();
	cout << " or\n" << max_result << endl;
	cout << "Average outward distance per step = "
		<< max_result.magval() / max_steps << endl;
	cout << "After Min steps " << min_steps << " steps, the subject "
		<< "has the following location: \n";
	cout << min_result << endl;
	min_result.polar_mode();
	cout << " or\n" << min_result << endl;
	cout << "Average outward distance per step = "
		<< min_result.magval() / min_steps << endl;

	cout << "Bye!\n";

	return 0;
}
