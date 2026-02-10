#include "sales.h"

int main() {
	using SALES::Sales;

	double ar[4] = {3.5, 2.8, 1.5, 4.4};
	Sales s1(ar, 4);
	s1.showSales();
	Sales s2(ar, 2);
	s2.showSales();
	Sales s3;
	s3.showSales();
	return 0;
}
