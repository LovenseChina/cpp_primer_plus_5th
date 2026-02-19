#ifndef WINEC_H_
#define WINEC_H_
#include <iostream>
#include <string>
#include <valarray>

template <class T1, class T2>
class Pair{
public:
	Pair() {}
	Pair(const T1 &aval,const T2 &bval): a(aval), b(bval) {}
	T1 first() const { return a; }
	T2 second() const { return b; }
	T1 &first() { return a; }
	T2 &second() { return b; }
private:
	T1 a;
	T2 b;
};

typedef std::valarray<int> ArrInt;
typedef Pair<ArrInt, ArrInt> Pairs;
typedef std::string string;

class Wine: private Pairs, private string {
private:
	int year;
public:
	Wine(): year(-1) {}
	Wine(const char *l, int y, const int yr[], const int bot[]):
		Pairs(ArrInt(yr, y), ArrInt(bot, y)), string(l), year(y) {}
	Wine(const char *l, int y) :
		Pairs(ArrInt(y), ArrInt(y)), string(l), year(y) {}
	void GetBottles();
	const string & Lable() const { return (const string &)*this; }
	int sum() const { return ((const Pairs &)*this).second().sum(); }
	void Show() const;
};
#endif
