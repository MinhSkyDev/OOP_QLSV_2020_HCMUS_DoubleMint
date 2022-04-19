#pragma once
#include <iostream>
#include <string>
using namespace std;
class Schedule
{
private:
	string* courses;
	int quantity;
public:
	Schedule();
	~Schedule();
	Schedule(Schedule& a);
	void operator=(Schedule& a);

	//CRUD
	void addCourse(string course_name);
	void updateCouse(string course_name);
	void deleteCourse(string course_name);
	void updateCourse(string course_name);

	//input output

};

