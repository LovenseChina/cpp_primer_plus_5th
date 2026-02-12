#include "complex0.h"

complex::complex(double real, double imag) {
	r = real;
	i = imag;
}

complex::complex() { r = i = 0.0; }

complex complex::operator+(const complex &c) const { return complex(r + c.r, i + c.i); }

complex complex::operator-(const complex &c) const { return complex(r - c.r, i - c.i); }

complex complex::operator*(const complex &c) const {
	double real = r * c.r - i * c.i,
		imag = r * c.i + i * c.r;
	return complex(real, imag);
}

complex operator*(double x, const complex &c) { return complex(x * c.r, x * c.i); }

complex complex::operator~() const { return complex(r, -i); }

std::istream &operator>>(std::istream &is, complex &c) {
	std::cout << "real: ";
	is >> c.r;
	std::cout << "imaginary: ";
	is >> c.i;
	return is;
}

std::ostream &operator<<(std::ostream &os, const complex &c) {
	os << "(" << c.r << ", " << c.i << "i)";
	return os;
}
