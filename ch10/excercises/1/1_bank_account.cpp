#include "1_bank_account.h"
#include <iostream>
#include <cstring>

BankAccount::BankAccount(const std::string &n, const char *a, double m) {
	name = n;
	std::strncpy(account, a, ACCSIZE - 1);
	account[ACCSIZE - 1] = '\0';
	if(m < 0) {
		std::cerr << "Invalid, set to zero.\n";
		money = 0;
	} else
		money = m;
}

void BankAccount::show() const {
	std::cout << str;
	std::cout << "User name: " << name
		<< "\nAccount: " << account
		<< "\nMoney: " << money << std::endl;
	std::cout << str;
}

void BankAccount::deposit(double m) {
	std::cout << str;
	if (m < 0) 
		std::cerr << "Invalid deposit operation. Aborted.\n";
	else {
		money += m;
		std::cout << "You deposited $" << m << " and your account has $" << money << std::endl;
	}
	std::cout << str;
}

void BankAccount::withdraw(double m) {
	std::cout << str;
	if (m < 0 || m > money) 
		std::cerr << "Invalid withdraw operation. Aborted.\n";
	else {
		money -= m;
		std::cout << "You withdrawed $" << m << " and your account has $" << money << std::endl;
	}
	std::cout << str;
}
