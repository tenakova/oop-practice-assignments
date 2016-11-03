#ifndef Musician_h
#define Musician_h
#include "MusicalSkill.h"

const int MAX_SKILLSET = 5;
const double PI = 3.1415;

class Musician
{
private:
	void cpy(const Musician&);
	void del();
protected:
	char* name;
	int beauty;
	int faults;
	MusicalSkill skills[MAX_SKILLSET];
	int skill_size;
public:
	Musician(char* = "None", int = 0, int = 0, MusicalSkill [] = {}, int = 0);
	Musician(const Musician&);
	virtual ~Musician();
	Musician& operator=(const Musician&);

	void set_name(char*);
	char* get_name() const;
	int get_faults() const;
	MusicalSkill* get_best_skills(int);
	void sort_skills_in_descending_order();
	int get_skills_sum() const;
	bool has_skill_of_less_than_10() const;

	virtual double get_beauty() const = 0;	
	virtual char* get_type() const = 0;

	virtual void print() const;
};

#endif