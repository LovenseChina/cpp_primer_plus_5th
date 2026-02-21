#include <iostream>
#include <stdexcept>

class bad_hmean: public std::logic_error {
private:
	double v1;
	double v2;
public:
	bad_hmean(double a = 0, double b = 0):
		v1(a), v2(b), std::logic_error::logic_error("heam(a, b) ") {}
	void report() const {
		std::cout << what() << "error, arguments invalid: a = -b\n"
			"Here is the parameters: " << v1 << ", " << v2 << std::endl;
	}
};

class bad_gmean: public std::logic_error {
public:
	double v1;
	double v2;
	bad_gmean(double a = 0, double b = 0):
		v1(a), v2(b), std::logic_error::logic_error("gmean(a, b) ") {}
	void report() const {
		std::cout << what() << "error, arguments invalid: a < 0 or b < 0\n"
			"Here is the parameters: " << v1 << ", " << v2 << std::endl;
	}
};
