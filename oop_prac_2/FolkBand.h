#ifndef FolkBand_h
#define FolkBand_h
#include "Band.h"

class FolkBand : virtual public Band
{
public:
	FolkBand(char* name = "/", Musician*[MAX_BAND_SIZE] = {}, int = 0);
	FolkBand(const FolkBand&);
	FolkBand& operator=(const FolkBand&);

	virtual bool is_approved(Musician*) const;
	virtual double overall_assessment() const;
};



#endif