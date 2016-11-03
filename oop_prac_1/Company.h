#ifndef Company_h
#define Company_h
#include "Team.h"

class Company
{
private:
	Team* teams;
	int size;
	int capacity;

	void cpy(const Company&);
	void del();

public:
	Company();
	Company(Team*, int);
	Company(const Company&);
	~Company();
	Company& operator=(const Company&);

	double  get_average_iq() const;
	void print();
};
#endif