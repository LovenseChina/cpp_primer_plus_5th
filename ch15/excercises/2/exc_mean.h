#include <iostream>
#include <stdexcept>

class bad_hmean: public std::logic_error {
public:
	bad_hmean(): std::logic_error::logic_error("hmean() error") {}
	const char *what() const throw() { return "hmean(a, b) invalid arguments: a = -b\n"; }
};

class bad_gmean: public std::logic_error {
public:
	bad_gmean(): std::logic_error::logic_error("gmean() error") {}
	const char *what() const throw() { return "gmean(a, b) invalid arguments: two of args must positive\n"; }
};
