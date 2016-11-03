#include <iostream>
#include <cassert>
#include <cstring>
#include "Programmer.h"
using namespace std;

void Programmer::cpy(const Programmer& other)
{
	name = new char[strlen(other.name) + 1];
	assert(name != NULL);
	strcpy_s(name, strlen(other.name) + 1, other.name);

	iq = other.iq;
	salary = other.salary;
}
void Programmer::del()
{
	delete[] name;
}
Programmer::Programmer(char* name, int iq, double salary)
{
	this->name = new char[strlen(name) + 1];
	assert(this->name != NULL);
	strcpy_s(this->name, strlen(name) + 1, name);

	this->iq = iq;
	this->salary = salary;
}
Programmer::Programmer(const Programmer& other)
{
	cpy(other);
}
Programmer::~Programmer()
{
	del();
}
Programmer& Programmer::operator=(const Programmer& other)
{
	if (this != &other)
	{
		del();
		cpy(other);
	}
	return *this;
}
void Programmer::set_name(char* name)
{
	this->name = new char[strlen(name) + 1];
	assert(this->name != NULL);
	strcpy_s(this->name, strlen(name) + 1, name);
}
void Programmer::set_iq(int iq)
{
	this->iq = iq;
}
void Programmer::set_salary(double salary)
{
	this->salary = salary;
}
char* Programmer::get_name() const
{
	return name;
}
int Programmer::get_iq() const
{
	return iq;
}
double Programmer::get_salary() const
{
	return salary;
}
bool Programmer::operator<(const Programmer& other) const
{
	return this->iq < other.get_iq();
}
bool Programmer::operator>(const Programmer& other) const
{
	return this->iq > other.get_iq();
}
bool Programmer::operator==(const Programmer& other) const
{
	return !strcmp(name, other.name);
}
void Programmer::print() const
{
	cout << this->name << " has iq of " << this->iq << " and earns " << salary << " dollars per month." << endl;
}