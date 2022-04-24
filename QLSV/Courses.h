#pragma once
#include "Roster.h"

class Courses
{
private:
	string name;
	Roster roster;
public:
	Courses();
	~Courses();
	Courses(Courses& c);
	void operator=(Courses& c);

	void setName(const string& Name);
	void setRoster(Roster& r);
	string getName();
	Roster getRoster();		// tra ve roster
	//Roster getRoster(int index);	// tra ve roster[index]

	bool isCoursesEmpty();

	//CRUD
	void addRoster(string roster_name);
	bool isHaveRoster(string roster_name);
	void deleteRoster(string roster_name);
	void updateRoster(string roster_name_src, string rostere_name_dest);

	friend ostream& operator<<(ostream& out, Courses& c);		// Ghi ra mon hoc va danh sach cac lop cua mon hoc
	//friend operator[](ostream& out, Courses& c);	// Ghi ra cu the mot ten lop hoc dua vao index
};


