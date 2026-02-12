#ifndef COMPLEX0_H_
#define COMPLEX0_H_
#include <iostream>

class complex{
public:
	complex(double, double);
	complex();
	complex operator+(const complex &) const;
	complex operator-(const complex &) const;
	complex operator*(const complex &) const;
	friend complex operator*(double, const complex &);
	complex operator~() const;
	friend std::istream &operator>>(std::istream &, complex &);
	friend std::ostream &operator<<(std::ostream &, const complex &);
private:
	double r, i;
};

#endif
