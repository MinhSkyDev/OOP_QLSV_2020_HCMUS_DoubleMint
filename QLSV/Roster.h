#pragma once
#include <iostream>
#include <string>
#include <cstddef>
using namespace std;

// Lop hau to cua Course (VD: 20CTT2, 1, a...)
class Roster
{
private:
	string* roster;
	int numOfCourses;
public:
	// Default Constructor
	Roster();
	// Destructor
	~Roster();
	// Copy Constructor
	Roster(Roster& r);
	// Default assignment operator
	void operator=(Roster& r);

	string* getList();
	int getQuantity();
	// Kiem tra xem mot hau to co thuoc mot khoa hoc hay khong
	// Tra ve index cua hau to neu tim thay, -1 neu khong ton tai
	int isCourseHaveRoster(const string& roster_find);
	bool isRosterEmpty();

	// CRUD
	// Create: (add a new roster to the list)
	void addRoster(string roster_name);
	// Read:
	friend ostream& operator<<(ostream& out, Roster& r);
	// Update:
	void updateRoster(string roster_name_src, string roster_name_dst);
	// Delete:
	void deleteRoster(string roster_name);
};