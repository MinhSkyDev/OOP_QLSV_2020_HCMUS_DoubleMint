#pragma once
#include "Roster.h"
#include <string>
#include <iostream>
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
	Roster getRoster();

	//CRUD
	void addRoster(string roster_name);
	bool isHaveRoster(string roster_name);
	void deleteRoster(string roster_name);
	void updateRoster(string roster_name_src, string rostere_name_dest);

	friend ostream& operator<<(ostream& out, Courses& c);
};


