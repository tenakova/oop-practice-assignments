#ifndef RockBand_h
#define RockBand_h
#include "Band.h"

class RockBand : virtual public Band
{
public:
	RockBand(char* = "/", Musician*[MAX_BAND_SIZE] = {}, int = 0);
	RockBand(const RockBand&);
	RockBand& operator=(const RockBand&);

	int get_faults_sum() const;

	virtual bool is_approved(Musician*) const;
	virtual double overall_assessment() const;
};

#endif 