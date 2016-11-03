#include "FolkRockBand.h"
#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

FolkRockBand::FolkRockBand(char* name, Musician* musicians[MAX_BAND_SIZE], int band_size) : Band(name, musicians, band_size) {}

FolkRockBand::FolkRockBand(FolkRockBand &other) : Band(other) {}

FolkRockBand& FolkRockBand::operator=(FolkRockBand& other)
{
	if (this != &other)
	{
		Band::operator=(other);
	}
	return *this;
}
bool FolkRockBand::is_approved(Musician* musician) const
{
	return RockBand::is_approved(musician) || FolkBand::is_approved(musician);
}
double FolkRockBand::overall_assessment() const
{
	return get_musical_skill_sum() - get_type_switches();
}
int FolkRockBand::get_type_switches() const
{
	int switches = 0;
	for (int i = 0; i < band_size-1; i++)
	{
		char* type = musicians[i]->get_type();
		char* next_type = musicians[i + 1]->get_type();
		if (strcmp(type, next_type)) switches += 1;
	}

	return switches;
}