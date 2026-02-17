#include "bop.h"
int main() {
	Port p;
	VintagePort vp;
	cout << "Test cout:\np--" << p << "\nvp-- " << vp << endl;
	cout << "---------------**---------------\n";
	Port *ptr = &p;
	ptr->Show();
	cout << endl;
	ptr = &vp;
	ptr->Show();
	cout << endl;
	VintagePort vp1("Gallo", "tanwy", 20, "Old Velvet", 1982);
	vp = vp1;
	ptr->Show();
	cout << endl;
	p = (vp1 -= 10);
	ptr = &p;
	ptr->Show();
	cout << endl;
	ptr = &vp1;
	ptr->Show();
	cout << endl;
	return 0;
}
