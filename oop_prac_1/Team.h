#ifndef Team_h
#define Team_h
#include "Programmer.h"

class Team
{
private:
	char* name;
	Programmer* programmers;
	int size;
	int capacity;

	void cpy(const Team&);
	void del();

public:
	Team(char* = "/", int = 1);
	Team(const Team&);
	~Team();
	Team& operator=(const Team&);

	void add_programmer(const Programmer&);
	void remove_programmer(char*);
	Team& operator-=(Team&);
	Programmer& get_programmer(char*) const;
	Programmer* get_programmers() const;
	int get_size() const;
	char* get_name() const;
	void sort();
	void quick_sort(Programmer*, int, int);
	void print() const;
};

#endif