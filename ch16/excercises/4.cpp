#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>

const int MAX = 20;

int reduce(long ar[], int n);
int main() {
	using std::cout;
	using std::endl;
	
	cout << "Generating random array[] in size 20\n\n";
	std::srand(std::time(0));
	long array[MAX] = {0};
	for (int i = 0; i < MAX; ++i)
		array[i] = std::rand() % 100;

	cout << "array[] before sort & unique:\n";
	int j;
	for (j = 0; j < MAX; ++j) {
		cout.width(2);
		cout << array[j] << ' ';
		if (j % 5 == 4)
			cout << endl;
	}
	if (j % 5 != 4)
		cout << endl;
	
	cout << "array[] after sort & unique:\n";
	int ar_size = reduce(array, MAX);
	int i;
	for (i = 0; i < ar_size;  ++i) {
		cout.width(2);
		cout << array[i] << ' ';
		if (i % 5 == 4)
			cout << endl;
	}
	if (i % 5 != 4)
		cout << endl;
	return 0;
}

int reduce(long ar[], int n) {
	std::set<long> s(ar, ar + n);
	std::set<long>::iterator it;
	int i = 0;
	for (it = s.begin(); it != s.end(); ++it)
		ar[i++] = *it;
	return s.size();
}
