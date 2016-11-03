#include "RockMusician.h"
#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

RockMusician::RockMusician(char* name, int beauty, int faults, MusicalSkill skills[], int skill_size)
	: Musician(name, beauty, faults, skills, skill_size) {}

RockMusician::RockMusician(const RockMusician& other) : Musician(other) {}

RockMusician& RockMusician::operator=(const RockMusician& other)
{
	if (this != &other)
	{
		Musician::operator=(other);
	}
	return *this;
}
double RockMusician::get_beauty() const
{
	return beauty*beauty + get_skills_sum() - faults * 3 * PI;
}
char* RockMusician::get_type() const
{
	return "rock";
}
void RockMusician::print() const
{
	Musician::print();
}
