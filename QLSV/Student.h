#pragma once
#include <iostream>
#include <string>
#include "Schedule.h"
using namespace std;
class Student
{
private:
	string name;
	Schedule schedule;
public:
	Student();
	~Student();
	Student(Student& a);
	void operator=(Student& a);

	//Setter getter
	void setName(const string& Name);
	void setSchedule( Schedule& a);
	string getName();
	Schedule getSchedule();


	//CRUD
	void addCourse(string course_name);
	bool isHaveCourse(string course_name);
	void deleteCourse(string course_name);
	void updateCourse(string course_name_source, string course_name_destination);

	//Output
	friend ostream& operator<<(ostream& out, Student& a);



};

