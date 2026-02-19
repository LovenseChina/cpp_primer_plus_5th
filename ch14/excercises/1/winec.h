#ifndef WINEC_H_
#define WINEC_H_
#include <iostream>
#include <string>
#include <valarray>

class Wine {
private:
	std::string lable;
	class Pair {
	public:
		Pair() {}
		Pair(int y, const int yr[], const int bot[]);
		Pair(int y);
		std::valarray<int> &first() { return years; }
		std::valarray<int> &second() { return bottles; }
		const std::valarray<int> &first() const { return years; }
		const std::valarray<int> &second() const { return bottles; }
	private:
		std::valarray<int> years;
		std::valarray<int> bottles;
	};
	Pair p;
	int year;
public:
	Wine() {}
	Wine(const char *l, int y, const int yr[], const int bot[]):
		lable(l), p(y, yr, bot), year(y) {}
	Wine(const char *l, int y):
		lable(l), p(y), year(y) {}
	void GetBottles();
	const std::string &Lable() const { return lable; }
	int sum() const { return p.second().sum(); }
	void Show() const;
};

#endif
