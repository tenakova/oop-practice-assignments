#ifndef RockMusician_h
#define RockMusician_h
#include "Musician.h"

class RockMusician : public Musician
{
public:
	RockMusician(char* = "None", int = 0, int = 0, MusicalSkill[] = {}, int = 0);
	RockMusician(const RockMusician&);
	RockMusician& operator=(const RockMusician&);

	virtual double get_beauty() const;
	virtual char* get_type() const;

	virtual void print() const;
};

#endif