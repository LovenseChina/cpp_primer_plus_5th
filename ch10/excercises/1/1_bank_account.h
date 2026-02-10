#ifndef BANK_ACCOUNT_H_
#define BANK_ACCOUNT_H_
#include<string>

const char str[] = "\n--------------------\n";

class BankAccount {
	static const int ACCSIZE = 21;
	std::string name;
	char account[ACCSIZE];
	double money;
public:
	BankAccount(const std::string &n, const char *a, double m = 0.0);
	void show() const;
	void deposit(double m);
	void withdraw(double m);
};

#endif
