#include "1_bank_account.h"

int main() {
	BankAccount ba[4] = {
		BankAccount("Andy", "00000000000000000001"),
		BankAccount("Jack", "00000000000000000002", 200.0),
		BankAccount("Jane", "00000000000000000003", 300.0),
		BankAccount("Christ Jesus", "00000000000000000004", 2000.0)
	};
	for (int i = 0; i < 4; ++i)
		ba[i].show();

	ba[0].deposit(-1.0);
	ba[0].deposit(100.0);
	ba[0].show();

	ba[1].withdraw(300.0);
	ba[1].withdraw(150.0);
	ba[1].show();

	return 0;
}
