#include <iostream>
#include "dma.h"
int main() {
	using std::cout;
	using std::endl;

	baseDMA shirt("Portabelly", 8);
	lacksDMA ballon("red", "Blimpo", 4);
	hasDMA map("Mercator", "Buffalo Keys", 5);
	cout << shirt << endl;
	cout << ballon << endl;
	cout << map << endl;
	lacksDMA ballon2(ballon);
	hasDMA map2;
	map2 = map;
	cout << ballon2 << endl;
	cout << map2 << endl;
	cout << "----------use abcBase pointer arr[]----------\n";
	abcDMA *arr[5] = {
		&shirt,
		&ballon,
		&map,
		&ballon2,
		&map2
	};
	for (int i = 0; i < 5; ++i) {
		(*(arr + i))->Show();
		cout << endl;
	}
	cout << "------------------TEST END------------------\n";
	return 0;
}
