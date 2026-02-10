#include "move.h"
#include <iostream>

Move::Move(double a, double b) {
	x = a;
	y = b;
}

void Move::showmove() const {
	std::cout << "(x, y) = (" << x << ", " << y << ")\n";
}

Move Move::add(const Move &m) const {
	Move ret(x + m.x, y + m.y);
	return ret;
}

void Move::reset(double a, double b) {
	x = a;
	y = b;
}
