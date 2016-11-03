#include <iostream>
#include <cassert>
#include <cstring>
#include "Company.h"
using namespace std;

void Company::cpy(const Company& other)
{
	size = other.size;

	teams = new Team[size];
	assert(teams != NULL);
	for (int i = 0; i < size; i++)
	{
		teams[i] = other.teams[i];
	}
}
void Company::del()
{
	delete [] teams;
}
Company::Company()
{
	this->size = 0;

	teams = new Team[size];
	assert(teams != NULL);
}
Company::Company(Team* teams, int size)
{
	this->size = size;

	this->teams = new Team[size];
	assert(teams != NULL);
	for (int i = 0; i < size; i++)
	{
		this->teams[i] = teams[i];
	}
}
Company::Company(const Company& other)
{
	cpy(other);
}
Company::~Company()
{
	del();
}
Company& Company::operator=(const Company& other)
{
	if (this != &other)
	{
		del();
		cpy(other);
	}
	return *this;
}
double Company::get_average_iq() const
{
	double average_iq = 0;
	int total_worker_amount = 0;
	for (int i = 0; i < size; i++)
	{
		int team_size = teams[i].get_size();
		total_worker_amount += team_size;
		Programmer* team_programmers = teams[i].get_programmers();
		for (int j = 0; j < team_size; j++)
		{
			average_iq += team_programmers[j].get_iq();
		}
	}
	return average_iq / total_worker_amount;
}
void Company::print()
{
	cout << "Company: " << endl;
	for (int i = 0; i < size; i++)
	{
		teams[i].print();
	}
}