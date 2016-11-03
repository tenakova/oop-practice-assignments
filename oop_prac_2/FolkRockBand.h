#ifndef FolkRockBand_h
#define FolkRockBand_h
#include "RockBand.h"
#include "FolkBand.h"


class FolkRockBand : public RockBand, public FolkBand
{
public:
	FolkRockBand(char* = "/", Musician*[MAX_BAND_SIZE] = {}, int = 0);
	FolkRockBand(FolkRockBand&);
	FolkRockBand& operator=(FolkRockBand&);

	int get_type_switches() const;
	
	virtual bool is_approved(Musician*) const;
	virtual double overall_assessment() const;
};

#endif