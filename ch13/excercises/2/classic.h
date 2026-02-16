#ifndef CLASSIC_H_
#define CLASSIC_H_
class Cd {
private:
	char *performers;
	char *lable;
	int selections;
	double playtime;
public:
	Cd(const char *s1, const char *s2, int n, double x);
	Cd(const Cd &d);
	Cd();
	virtual ~Cd();
	virtual void Report() const;
	Cd &operator=(const Cd &d);
};

class Classic: public Cd {
private:
	char *mainWorks;
public:
	Classic(const char *s0, const char *s1, const char *s2, int n, double x);
	Classic(const Classic &c);
	Classic();
	~Classic();
	void Report() const;
	Classic &operator=(const Classic &c);
};
#endif
