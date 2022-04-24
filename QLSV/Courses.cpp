#include "Courses.h"
#include <iostream>
#include <string>

using namespace std;

Courses::Courses() {
	name = "";
}

Courses::~Courses() {
	name = "";
}

Courses::Courses(Courses& c) {
	name = c.name;
	roster = c.roster;		// Definition in roster.cpp
}

void Courses::operator=(Courses& c) {
	name = c.name;
	roster = c.roster;		// Definition in roster.cpp
}

string Courses::getName() {
	return name;
}

Roster Courses::getRoster() {
	return roster;
}

bool Courses::isCoursesEmpty()
{
	return (this->roster.isRosterEmpty());
}

void Courses::setName(const string& Name) {
	name = Name;
}

void Courses::setRoster(Roster& r) {
	roster = r;		// Definition in roster.cpp
}

void Courses::addRoster(string roster_name) {
	roster.addRoster(roster_name);
}

bool Courses::isHaveRoster(string roster_name) {
	if (roster.isCourseHaveRoster(roster_name) == -1)
		return false;
	return true;
}

void Courses::deleteRoster(string roster_name) {
	roster.deleteRoster(roster_name);
}

void Courses::updateRoster(string roster_name_src, string rostere_name_dest) {
	roster.updateRoster(roster_name_src, rostere_name_dest);
}

ostream& operator<<(ostream& out, Courses& c) {
	out << "Mon hoc: " << c.name << '\n';
	out << c.roster << '\n';
	return out;
}
