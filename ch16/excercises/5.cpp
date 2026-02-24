#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <set>

const int MAX = 20;

template <class T>
int reduce(T ar[], int n);
int main() {
	using std::cout;
	using std::endl;
	using std::string;

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
	cout << "\n\nString test:\n\n";
	string strs[] = {
		"basket", "basketball", "soccor", "player",
		"galaxy", "can", "bruise", "network", "player",
		"gasoline", "basket", "romance", "kindom"
	};
	cout << "Before sort & unique:\n\n";
	for (int i = 0; i < 13; ++i)
		cout << strs[i] << endl;
	int strs_size = reduce(strs, 13);
	cout << "\n\n\nAfter sort & unique:\n\n";
	for (int i = 0; i < strs_size; ++i)
		cout << strs[i] << endl;
	return 0;
}

template <class T>
int reduce(T ar[], int n) {
	std::set<T> s(ar, ar + n);
	typename std::set<T>::iterator it;
	int i = 0;
	for (it = s.begin(); it != s.end(); ++it)
		ar[i++] = *it;
	return s.size();
}
