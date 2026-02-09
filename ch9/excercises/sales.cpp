#include<iostream>
#include "sales.h"
using namespace std;
namespace SALES {

	void setSales(Sales &s, const double arr[], int n) {
		if(n <= 0 || n > QUARTERS) {
			for (int i = 0; i < QUARTERS; ++i)
				s.sales[i] = 0;
			s.average = s.min = s.max = 0;
			return;
		}
		int i = 1;
		s.sales[0] = arr[0];
		s.max = arr[0];
		s.min = arr[0];
		double sum = arr[0];
		for (; i < n; ++i) {
			s.sales[i] = arr[i];
			sum += arr[i];
			s.max = s.max > arr[i] ? s.max : arr[i];
			s.min = s.min < arr[i] ? s.min : arr[i];
		}
		for (; i < QUARTERS; ++i)
			s.sales[i] = 0;
		s.average = sum / (double)n;
	} 
	
	void setSales(Sales &s) {
		cout << "Enter sales (Enter q to terminate in advance): \n";
		int i = 0;
		cout << "#1: ";
		cin >> s.sales[0];
		s.min = s.max = s.sales[0];
		double sum = s.sales[0];
		while(cin && i < QUARTERS) {
			++i;
			if(i >= QUARTERS)
				break;
			cout << "#" << (i + 1) << ": ";
			cin >> s.sales[i];
			if (!cin)
				break;
			sum += s.sales[i];
			s.max = s.max > s.sales[i] ? s.max : s.sales[i];
			s.min = s.min < s.sales[i] ? s.min : s.sales[i];
		}

		if(i == 0) {
			for (int k = 0; k < QUARTERS; ++k)
				s.sales[k] = 0;
			s.average = s.min = s.max = 0;
			return;
		 }

		s.average = sum / (double)i;
		
		for (int j = i; j < QUARTERS; ++j)
			s.sales[j] = 0;
	} 

	void showSales(const Sales &s) {
		cout << "Four QUARTERS:\n";
		for (int i = 0; i < QUARTERS; ++i)
			cout << s.sales[i] << "\t";
		cout << endl;
		cout << "Average: " << s.average << endl;
		cout << "Max: " << s.max << endl;
		cout << "Min: " << s.min << endl;
		cout << "-------------------------\n";
	}

}
