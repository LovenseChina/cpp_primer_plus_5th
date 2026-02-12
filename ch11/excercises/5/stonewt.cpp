#include "stonewt.h"

Stonewt::Stonewt(double lbs, int s) {
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - (int)lbs;
	pounds = lbs;
	state = s;
}

Stonewt::Stonewt(int stn, double lbs, int s) {
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
	state = s;
}

Stonewt::Stonewt() { stone = pds_left = pounds = state = 0; }

Stonewt::~Stonewt() {}
/*
void Stonewt::show_stn() const { cout << stone << " stone, " << pds_left << " pounds\n"; }

void Stonewt::show_lbs() const { cout << pounds << " pounds\n"; }
*/

std::ostream &operator<<(std::ostream &os, const Stonewt &st) {
	if(st.state == Stonewt::LBS)
		os << st.pounds << " pounds\n";
	else
		os << st.stone << " stone, " << st.pds_left << " pounds\n";
	return os;
}
