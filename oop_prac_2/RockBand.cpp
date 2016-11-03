#include "RockBand.h"
#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

RockBand::RockBand(char* name, Musician* musicians[MAX_BAND_SIZE], int band_size) : Band(name, musicians, band_size) {}

RockBand::RockBand(const RockBand& other) : Band(other) {}

RockBand& RockBand::operator=(const RockBand& other)
{
	if (this != &other)
	{
		Band::operator=(other);
	}
	return *this;
}
bool RockBand::is_approved(Musician* musician) const
{
	int best_skill = musician->get_best_skills(1)[0].get_skill();
	return (!strcmp(musician->get_type(), "rock") || best_skill > 100);
}
double RockBand::overall_assessment() const
{
	return get_musical_skill_sum() - get_faults_sum();
}
int RockBand::get_faults_sum() const
{
	int faults_sum = 0;
	for (int i = 0; i < band_size; i++)
	{
		faults_sum += musicians[i]->get_faults();
	}

	return faults_sum;
}