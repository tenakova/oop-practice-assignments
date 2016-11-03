#ifndef Programmer_h
#define Programmer_h

class Programmer
{
private:
	char* name;
	int iq;
	double salary;

	void cpy(const Programmer&);
	void del();

public:
	Programmer(char* = "/", int = 0, double = 0);
	Programmer(const Programmer&);
	~Programmer();
	Programmer& operator=(const Programmer&);

	void set_name(char*);
	void set_iq(int);
	void set_salary(double salary);
	char* get_name() const;
	int get_iq() const;
	double get_salary() const;

	bool operator<(const Programmer&) const;
	bool operator>(const Programmer&) const;
	bool operator==(const Programmer&) const;

	void print() const;
};

#endif