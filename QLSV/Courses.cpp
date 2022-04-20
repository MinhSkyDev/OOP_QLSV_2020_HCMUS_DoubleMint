#include "Courses.h"

Courses::Courses()
{
}

Courses::~Courses()
{
}

Courses::Courses(Courses& c)
{
}

void Courses::operator=(Courses& c)
{
}

void Courses::setName(const string& Name)
{
}

void Courses::setRoster(Roster& r)
{
}

string Courses::getName()
{
	return string();
}

Roster Courses::getRoster()
{
	
}

void Courses::addRoster(string roster_name)
{
}

bool Courses::isHaveRoster(string roster_name)
{
	return false;
}

void Courses::deleteRoster(string roster_name)
{
}

void Courses::updateRoster(string roster_name_src, string rostere_name_dest)
{
}

ostream& operator<<(ostream& out, Courses& c)
{
	// // O: insert return statement here
}
