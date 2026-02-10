#include "b_plorg.h"

int main() {
	Bplorg b1;
	b1.showplorg();
	b1.setCI(10);
	b1.showplorg();

	Bplorg b2("123456789123456789123456789");
	b2.showplorg();

	return 0;
}
