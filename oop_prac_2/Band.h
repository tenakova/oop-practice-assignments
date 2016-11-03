#ifndef Band_h
#define Band_h
#include "Musician.h"

const int MAX_BAND_SIZE = 10;

class Band
{
protected:
	char* name;
	Musician* musicians[MAX_BAND_SIZE];
	int band_size;
	void cpy(const Band&);
	void del();
public:
	Band(char* = "/", Musician*[MAX_BAND_SIZE] = {}, int = 0);
	Band(const Band&);
	virtual ~Band();
	Band& operator=(const Band&);

	void add_musician(Musician*);
	void remove_musician(char*);
	int get_musical_skill_sum() const;
	double get_average_beauty() const;
	double get_beauty_sum() const;
	void print() const;

	virtual bool is_approved(Musician*) const = 0;
	virtual double overall_assessment() const = 0;
};

#endif