#include "sales.h"
using namespace SALES;
int main() {
	double mysale[QUARTERS] = {4, 3, 5, 6};
	Sales s1;
	setSales(s1, mysale, QUARTERS);
	showSales(s1);

	setSales(s1, mysale, 2);
	showSales(s1);

	Sales s2;
	setSales(s2);
	showSales(s2);

	return 0;
}
