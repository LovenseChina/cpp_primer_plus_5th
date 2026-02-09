#include<iostream>
#include<new>
using namespace std;

struct chaff {
	char dross[20];
	int slag;
};

char buffer[256];

int main() {
	cout << "Way 1--new: \n";
	chaff *p1 = new chaff[2];
	for (int i = 0; i < 2; ++i) {
		cout << "Enter dross #" << (i + 1) << ": ";	// Use a char *input to get stdin string, and use strcpy(), but here is simplified.
		cin.getline(p1[i].dross, 20);
		cout << "Enter slag #" << (i + 1) << ": ";
		cin >> p1[i].slag;
		cin.get();
	}
	cout << "Echo input: \n";
	for (int i = 0; i < 2; ++i)
		cout << p1[i].dross << ", " << p1[i].slag << endl;
	delete []p1;

	cout << "Way 2--new placement: \n";
	chaff *p2 = new (buffer) chaff[2];
	for (int i = 0; i < 2; ++i) {
		cout << "Enter dross #" << (i + 1) << ": ";	// Use a char *input to get stdin string, and use strcpy(), but here is simplified.
		cin.getline(p2[i].dross, 20);
		cout << "Enter slag #" << (i + 1) << ": ";
		cin >> p2[i].slag;
		cin.get();
	}
	cout << "Echo input: \n";
	for (int i = 0; i < 2; ++i)
		cout << p2[i].dross << ", " << p2[i].slag << endl;

	return 0;
}
