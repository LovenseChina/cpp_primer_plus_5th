#include<iostream>
#include<cstring>
using namespace std;

struct CandyBar {
	char brand[20];
	double weight;
	int caloire;
};

void SetInfo(CandyBar &cb, const char * b = "Millennium Munch", double w = 2.85, int c = 350);
void ShowInfo(const CandyBar &);

int main() {
	CandyBar cb;
	SetInfo(cb);
	ShowInfo(cb);
	return 0;
}

void SetInfo(CandyBar &cb, const char *b, double w, int c) {
	strcpy(cb.brand, b);
	cb.weight = w;
	cb.caloire = c;
}

void ShowInfo(const CandyBar &cb) {
	cout << "Candy bar information:\n";
	cout << "Brand: " << cb.brand << endl;
	cout << "Weight: " << cb.weight << endl;
	cout << "Caloire: " << cb.caloire << endl;
}
