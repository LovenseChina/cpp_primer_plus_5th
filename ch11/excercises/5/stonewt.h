#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>

class Stonewt {
private:
	enum {Lbs_per_stn = 14, LBS = 0, STN = 1};
	int stone;
	double pds_left;
	double pounds;
	int state;
public:
	Stonewt(double lbs, int s = LBS);
	Stonewt(int stn, double lbs, int s = LBS);
	Stonewt();
	~Stonewt();
	//void show_lbs() const;
	//void show_stn() const;
	void changemode(int s) { state = s; }
	friend std::ostream &operator<<(std::ostream & os, const Stonewt &st);
};

#endif
