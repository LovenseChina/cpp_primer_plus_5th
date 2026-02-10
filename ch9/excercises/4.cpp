#include "sales.h"
//using namespace SALES;
int main() {
	using SALES::showSales;
	double mysale[SALES::QUARTERS] = {4, 3, 5, 6};
	SALES::Sales s1;
	SALES::setSales(s1, mysale, SALES::QUARTERS);
	showSales(s1);

	SALES::setSales(s1, mysale, 2);
	showSales(s1);

	SALES::Sales s2;
	SALES::setSales(s2);
	showSales(s2);

	return 0;
}
