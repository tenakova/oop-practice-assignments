#include <iostream>
#include <cassert>
#include <cstring>
#include "Team.h"
using namespace std;

void Team::cpy(const Team& other)
{
	name = new char[strlen(other.name) + 1];
	assert(name != NULL);
	strcpy_s(name, strlen(other.name) + 1, other.name);

	size = other.size;
	capacity = other.capacity;

	programmers = new Programmer[capacity];
	assert(programmers != NULL);
	for (int i = 0; i < size; i++)
	{
		programmers[i] = other.programmers[i];
	}
}
void Team::del()
{
	delete[] name;
	delete[] programmers;
}
Team::Team(char* name, int capacity)
{
	this->name = new char[strlen(name) + 1];
	assert(this->name != NULL);
	strcpy_s(this->name, strlen(name) + 1, name);

	this->size = 0;
	this->capacity = capacity;

	programmers = new Programmer[capacity];
	assert(programmers != NULL);
}
Team::Team(const Team& other)
{
	cpy(other);
}
Team::~Team()
{
	del();
}
Team& Team::operator=(const Team& other)
{
	if (this != &other)
	{
		del();
		cpy(other);
	}
	return *this;
}
void Team::add_programmer(const Programmer& programmer)
{
	if (size == capacity)
	{
		Programmer* temp = new Programmer[capacity];
		assert(temp != NULL);
		for (int i = 0; i < size; i++)
		{
			temp[i] = programmers[i];
		}

		delete[] programmers;

		capacity *= 2;
		programmers = new Programmer[capacity];
		assert(programmers != NULL);
		for (int i = 0; i < size; i++)
		{
			programmers[i] = temp[i];
		}
		delete[] temp;
	}

	programmers[size++] = programmer;
}
void Team::remove_programmer(char* name)
{
	if (capacity > 2 * size)
	{
		Programmer* temp = new Programmer[size];
		assert(temp != NULL);
		for (int i = 0; i < size; i++)
		{
			temp[i] = programmers[i];
		}

		delete[] programmers;
		capacity /= 2;
		programmers = new Programmer[capacity];
		assert(programmers != NULL);
		for (int i = 0; i < size; i++)
		{
			programmers[i] = temp[i];
		}
		delete[] temp;
	}

	for (int i = 0; i < size; i++)
	{
		if (!strcmp(programmers[i].get_name(), name))
		{
			for (int j = i; j < size - 1; j++)
			{
				programmers[j] = programmers[j + 1];
			}
			size--;
			break;
		}
	}
}
Team& Team::operator-=(Team& other)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < other.size; j++)
		{
			if (programmers[i] == other.programmers[j])
			{
				remove_programmer(programmers[i].get_name());
				i--;
			}
		}
	}
	return *this;
}
Programmer& Team::get_programmer(char* name) const
{
	for (int i = 0; i < size; i++)
	{
		if (!strcmp(programmers[i].get_name(), name))
		{
			return programmers[i];
			break;
		}
	}
}
Programmer* Team::get_programmers() const
{
	return programmers;
}
int Team::get_size() const
{
	return size;
}
char* Team::get_name() const
{
	return name;
}
void Team::sort()
{
	quick_sort(programmers, 0, size-1);
}
void Team::quick_sort(Programmer* programmers, int left, int right)
{
	int i = left;
	int j = right;
	Programmer pivot = programmers[(left + right) / 2];

	while (i <= j)
	{
		while (programmers[i] < pivot)
		{
			i++;
		}
		while (programmers[j] > pivot)
		{
			j--;
		}
		if (i <= j)
		{
			Programmer temp = programmers[i];
			programmers[i] = programmers[j];
			programmers[j] = temp;
			i++;
			j--;
		}

		if (i < right) quick_sort(programmers, i, right);
		if (j > left) quick_sort(programmers, left, j);
	}
}
void Team::print() const
{
	cout << "Team name: " << name << endl;
	cout << "Team size: " << size << endl;
	cout << "Programmers: " << endl;
	for (int i = 0; i < size; i++)
	{
		programmers[i].print();
	}
	cout << "-------------" << endl;
}
