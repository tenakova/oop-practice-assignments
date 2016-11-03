#ifndef MusicalSkill_h
#define MusicalSkill_h

class MusicalSkill
{
private:
	char* instrument;
	int skill;
	void cpy(const MusicalSkill&);
	void del();
public:
	MusicalSkill(char* = "/", int = 0);
	MusicalSkill(const MusicalSkill&);
	~MusicalSkill();
	MusicalSkill& operator=(const MusicalSkill&);
	bool operator<(const MusicalSkill&);

	int get_skill() const;
	void set_skill(int);

	void print() const;

};

#endif

