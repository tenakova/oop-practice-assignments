#ifndef FolkMusician_h
#define FolkMusician_h
#include "Musician.h"

class FolkMusician : public Musician
{
private:
	bool race;
public:
	FolkMusician(char* = "None", int = 0, int = 0, MusicalSkill[] = {}, int = 0, bool = 1);
	FolkMusician(const FolkMusician&);
	FolkMusician& operator=(const FolkMusician&);

	virtual double get_beauty() const;
	virtual char* get_type() const;

	virtual void print() const;
};

#endif