#include "FolkMusician.h"
#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

FolkMusician::FolkMusician(char* name, int beauty, int faults, MusicalSkill skills[], int skill_size, bool race)
	: Musician(name, beauty, faults, skills, skill_size)
{
	this->race = race;
}
FolkMusician::FolkMusician(const FolkMusician& other) : Musician(other)
{
	race = other.race;
}
FolkMusician& FolkMusician::operator=(const FolkMusician& other)
{
	if (this != &other)
	{
		Musician::operator=(other);
		race = other.race;
	}
	return *this;
}
double FolkMusician::get_beauty() const
{
	return pow(beauty, 5) + faults + race * PI;
}
char* FolkMusician::get_type() const
{
	return "rock_tack";
}
void FolkMusician::print() const
{
	Musician::print();
	race ? cout << "I have a tendency to like this music!" << endl : cout << "But I don't have a tendency for this music." << endl;
}