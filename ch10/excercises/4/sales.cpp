#include <iostream>
#include "sales.h"

SALES::Sales::Sales() {
	std::cout << "Enter 4 quarters sales (q to terminate in advance):\n ";

	int i = 0;
	double sum;
	std::cout << "Enter first quarter sale.\n";
	while (std::cin >> sales[i] && i < QUARTERS) {
		if (i == 0)
			sum = max = min = sales[0];
		else {
			sum +=  sales[i];
			max = max > sales[i] ? max : sales[i];
			min = min < sales[i] ? min : sales[i];
		}
		++i;
		if (i == 4)
			break;
		std::cout << "Enter next quarter sale.\n";
	}
	if (i > 0)
		average = sum / i;
	else
		average = max = min = 0;
	for (; i < QUARTERS; ++i)
		sales[i] = 0;
}

SALES::Sales::Sales(const double ar[], int n) {
	int i = 0;
	double sum;
	while (i < n && i < QUARTERS) {
		sales[i] = ar[i];
		if (i == 0)
			sum = max = min = sales[0];
		else {
			sum += sales[i];
			max = max > sales[i] ? max : sales[i];
			min = min < sales[i] ? min : sales[i];
	 	}
		++i;
	}
	if (i > 0)
		average = sum / i;
	else
		average = max = min = 0;
	for (; i < QUARTERS; ++i)
		sales[i] = 0;
}

void SALES::Sales::showSales() const {
	std::cout << "4 quarters sales information:\n";
	for (int i = 0; i < QUARTERS; ++i)
		std::cout << sales[i] << "\t";
	std::cout << std::endl;
	std::cout << "Average: " << average << std::endl;
	std::cout << "Max: " << max << std::endl;
	std::cout << "Min: " << min << std::endl;
}
