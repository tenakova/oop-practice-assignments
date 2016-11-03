#include "FolkBand.h"
#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

FolkBand::FolkBand(char* name, Musician* musicians[MAX_BAND_SIZE], int band_size) : Band(name, musicians, band_size) {}

FolkBand::FolkBand(const FolkBand& other) : Band(other) {}

FolkBand& FolkBand::operator=(const FolkBand& other)
{
	if (this != &other)
	{
		Band::operator=(other);
	}
	return *this;
}

bool FolkBand::is_approved(Musician* musician) const
{
	return (!strcmp(musician->get_type(), "rock_tack") || musician->has_skill_of_less_than_10());
}
double FolkBand::overall_assessment() const
{
	return get_musical_skill_sum() + get_beauty_sum();
}


