#ifndef B_PLORG_H_
#define B_PLORG_H_

class Bplorg {
public:
	Bplorg();
	Bplorg(const char *n); // or Bplorg(const char *n, int ci = 50)
	void setCI(int ci);
	void showplorg() const;
private:
	static const int Len = 20;
	char name[Len];
	int CI;
};

#endif
