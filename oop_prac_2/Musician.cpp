#include "Musician.h"
#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

void Musician::cpy(const Musician& other)
{
	name = new char[strlen(other.name) + 1];
	assert(name != NULL);
	strcpy_s(name, strlen(other.name) + 1, other.name);

	beauty = other.beauty;
	faults = other.faults;
	skill_size = other.skill_size;

	for (int i = 0; i < skill_size; i++)
	{
		skills[i] = other.skills[i];
	}
}
void Musician::del()
{
	delete[] name;
}
Musician::Musician(char* name, int beauty, int faults, MusicalSkill skills[], int skill_size)
{
	this->name = new char[strlen(name) + 1];
	assert(this->name != NULL);
	strcpy_s(this->name, strlen(name) + 1, name);

	this->beauty = beauty;
	this->faults = faults;
	this->skill_size = skill_size;

	for (int i = 0; i < skill_size; i++)
	{
		this->skills[i] = skills[i];
	}
}
Musician::Musician(const Musician& other)
{
	cpy(other);
}
Musician::~Musician()
{
	del();
}
Musician& Musician::operator=(const Musician& other)
{
	if (this != &other)
	{
		del();
		cpy(other);
	}
	return *this;
}
void Musician::set_name(char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	assert(this->name != NULL);
	strcpy_s(this->name, strlen(name) + 1, name);
}
char* Musician::get_name() const
{
	return name;
}
int Musician::get_faults() const
{
	return faults;
}
MusicalSkill* Musician::get_best_skills(int n)
{
	MusicalSkill* result = new MusicalSkill[n];
	sort_skills_in_descending_order();
	for (int i = 0; i < n; i++)
	{
		result[i] = skills[i];
	}

	return result;
}
void Musician::sort_skills_in_descending_order()
{
	bool is_not_sorted = true;
	while (is_not_sorted)
	{
		is_not_sorted = false;
		for (int i = 0; i < skill_size - 1; i++)
		{
			if (skills[i] < skills[i + 1])
			{
				MusicalSkill temp = skills[i];
				skills[i] = skills[i + 1];
				skills[i + 1] = temp;
				is_not_sorted = true;
			}
		}
	}
}
int Musician::get_skills_sum() const
{
	int skills_sum = 0;
	for (int i = 0; i < skill_size; i++)
	{
		skills_sum += skills[i].get_skill();
	}
	return skills_sum;
}
bool Musician::has_skill_of_less_than_10() const
{
	for (int i = 0; i < skill_size; i++)
	{
		if (skills[i].get_skill() < 10)
		{
			return true;
		}	
	}

	return false;
}
void Musician::print() const
{
	cout << "Hi, I am " << get_name() << ", I have beauty of " << get_beauty() << ", faults of " << get_faults()
		<< " and I play " << get_type() << "." << endl;
	for (int i = 0; i < skill_size; i++)
	{
		skills[i].print();
	}
	cout << endl;
}