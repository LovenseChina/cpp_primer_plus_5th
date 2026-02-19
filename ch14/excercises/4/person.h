#ifndef PERSON_H_
#define PERSON_H_
#include <string>
#include <iostream>
#include <cstdlib>

class Person {
public:
	Person(const std::string & fn, const std::string ln): firstname(fn), lastname(ln) {}
	virtual ~Person() {}
	virtual void Show() const { std::cout << "Name: " << lastname << " " << firstname << '\n'; }
private:
	std::string firstname, lastname;
};

class Gunslinger: virtual public Person {
public:
	Gunslinger(const std::string &fn, const std::string &ln, double gt):
		Person(fn, ln), gun_time(gt) {}
	virtual ~Gunslinger() {}
	double Draw() const { return gun_time; }
	void Show() const;
private:
	double gun_time;
};

class PokerPlayer: virtual public Person {
public:
	PokerPlayer(const std::string &fn, const std::string &ln): Person(fn, ln) {}
	virtual ~PokerPlayer() {}
	int Draw() const { return std::rand() % 52 + 1; }
	void Show() const;
};

class BadDude: public Gunslinger, public PokerPlayer {
public:
	BadDude(const std::string &fn, const std::string &ln, double gt):
		Person(fn, ln), Gunslinger(fn, ln, gt), PokerPlayer(fn, ln) {}
	double Gdraw() const { return Gunslinger::Draw(); }
	int Cdraw() const { return PokerPlayer::Draw(); }
	void Show() const;
};

#endif
