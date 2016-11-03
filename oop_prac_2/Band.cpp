#include "Band.h"
#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

void Band::cpy(const Band& other)
{
	name = new char[strlen(other.name) + 1];
	assert(name != NULL);
	strcpy_s(name, strlen(other.name) + 1, other.name);

	band_size = other.band_size;

	for (int i = 0; i < band_size; i++)
	{
		musicians[i] = other.musicians[i];
	}
}
void Band::del()
{
	delete[] name;
}
Band::Band(char* name, Musician* musicians[MAX_BAND_SIZE], int band_size)
{
	this->name = new char[strlen(name) + 1];
	assert(this->name != NULL);
	strcpy_s(this->name, strlen(name) + 1, name);

	this->band_size = band_size;

	for (int i = 0; i < band_size; i++)
	{
		this->musicians[i] = musicians[i];
	}
}
Band::Band(const Band& other)
{
	cpy(other);
}
Band::~Band()
{
	del();
}
Band& Band::operator=(const Band& other)
{
	if (this != &other)
	{
		del();
		cpy(other);
	}
	return *this;
}
int Band::get_musical_skill_sum() const
{
	int musical_skill_sum = 0;
	for (int i = 0; i < band_size; i++)
	{
		musicians[i]->get_skills_sum();
	}
	return musical_skill_sum;
}
void Band::remove_musician(char* name)
{
	for (int i = 0; i < band_size; i++)
	{
		if (!strcmp(musicians[i]->get_name(), name))
		{
			for (int j = i; j < band_size - 1; j++)
			{
				musicians[j] = musicians[j + 1];
			}
			band_size--;
			break;
		}
	}
}
void Band::add_musician(Musician* musician)
{
	if (band_size >= MAX_BAND_SIZE)
	{
		cout << "Band is full!" << endl;
		return;
	}

	else if(is_approved(musician)) musicians[band_size++] = musician;
}
double Band::get_average_beauty() const
{
	return get_beauty_sum() / band_size;
}
double Band::get_beauty_sum() const
{
	double beauty_sum = 0;
	for (int i = 0; i < band_size; i++)
	{
		beauty_sum += musicians[i]->get_beauty();
	}
	return beauty_sum;
}
void Band::print() const
{
	cout << "We are the " << name << "!" << endl;
	cout << "These are our " << band_size << " members:" << endl;
	for (int i = 0; i < band_size; i++)
	{
		musicians[i]->print();
	}
}