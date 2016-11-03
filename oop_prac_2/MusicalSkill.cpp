#include "MusicalSkill.h"
#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

void MusicalSkill::cpy(const MusicalSkill& other)
	{
		instrument = new char[strlen(other.instrument) + 1];
		assert(instrument != NULL);
		strcpy_s(instrument, strlen(other.instrument) + 1, other.instrument);

		skill = other.skill;
	}
void MusicalSkill::del()
{
	delete[] instrument;
}
MusicalSkill::MusicalSkill(char* instrument, int skill)
{
	this->instrument = new char[strlen(instrument) + 1];
	assert(this->instrument != NULL);
	strcpy_s(this->instrument, strlen(instrument) + 1, instrument);

	this->skill = skill;
}
MusicalSkill::MusicalSkill(const MusicalSkill& other)
{
	cpy(other);
}
MusicalSkill::~MusicalSkill()
{
	del();
}
MusicalSkill& MusicalSkill::operator=(const MusicalSkill& other)
{
	if (this != &other)
	{
		del();
		cpy(other);
	}
	return *this;
}
bool MusicalSkill::operator<(const MusicalSkill& other)
{
	return skill < other.skill;
}
int MusicalSkill::get_skill() const
{
	return skill;
}
void MusicalSkill::set_skill(int skill)
{
	this->skill = skill;
}
void MusicalSkill::print() const
{
	cout << "I play the " << instrument << " with the skill level of " << skill << "." << endl;
}
