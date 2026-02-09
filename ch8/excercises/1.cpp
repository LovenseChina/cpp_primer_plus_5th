#include<iostream>
using namespace std;
int Called = 0;
void Show_msg(const char *Msg, int call = 0);

int main() {
	const char *msg = "Call function.\n";
	cout << "Call function with one argument.\n";
	Show_msg(msg);
	cout << "Try again.\n";
	Show_msg(msg);
	cout << "Cal function with two arguments.\n";
	Show_msg(msg, 1);
	return 0;
}

void Show_msg(const char *Msg, int call) {
	if (call == 0)
		cout << Msg;
	else {
		for (int i = 0; i < Called; ++i)
				cout << Msg;
	}
	++Called;
};
