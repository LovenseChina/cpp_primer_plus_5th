#include <iostream>
#include <string>
//#include "queuetp.h"
#include "15_5_queuetp.h"

int main() {
	using std::string;
	using std::cin;
	using std::cout;

	QueueTP<string> cs(5);
	string temp;

	while (!cs.isfull()) {
		cout << "Please Enter your name. You will be "
			"served in the order of arrival.\n"
			"name: ";
		getline(cin, temp);
		cs.enqueue(temp);
	}
	cout << "The queue is full. Processing begins!\n";

	while (!cs.isempty()) {
		cs.dequeue(temp);
		cout << "Now processing " << temp << "...\n";
	}
	return 0;
}
