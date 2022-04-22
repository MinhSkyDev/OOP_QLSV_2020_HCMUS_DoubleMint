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
	void operator=(Schedule a);

	//Check if student has a specific Courses
	//return the index, if index = -1 then the course is not exist
	int isStudentHaveCourse(const string& course_find);

	//CRUD
	void addCourse(string course_name);
	void deleteCourse(string course_name);
	void updateCourse(string course_name_src, string course_name_dst);

	string* getCourses();
	int getQuantity();
	
	
	//input output
	//Ko can istream vi ta se dang ky thong qua cac method addCourse
	friend ostream& operator<<(ostream& out, Schedule& a);

};

