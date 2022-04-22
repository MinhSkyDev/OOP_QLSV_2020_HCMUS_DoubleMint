#include "Student.h"

Student::Student() {
	name = " ";
}

Student::~Student() {
	name = " ";
}

Student::Student(Student& a) {
	this->name = a.name;
	this->schedule = a.schedule; // Remember dynamically allocated here !!
	//Should concentrate in memory using when work with Schedule Class
	//Update: Memory Leak problem or 2 pointers point to a same address is solved
}

void Student::operator=(Student& a)
{
	this->name = a.name;
	this->schedule = a.schedule;
}

void Student::setName(const string& name) {
	this->name = name;
}

void Student::setSchedule( Schedule& a) {
	this->schedule = a;
}

string Student::getName() {
	return this->name;
}

Schedule& Student::getSchedule() {
	Schedule a = this->schedule;
	return a;
}

void Student::addCourse(string course_name) {
	this->schedule.addCourse(course_name);
}

bool Student::isHaveCourse(string course_name) {
	int indexCourse = this->schedule.isStudentHaveCourse(course_name);
	if (indexCourse != -1)
		return true;
	else return false;
}

void Student::deleteCourse(string course_name)
{
	//Call the delete method of the Schedule class
	this->schedule.deleteCourse(course_name);
}

void Student::updateCourse(string course_name_source, string course_name_destination) 
{
	this->schedule.updateCourse(course_name_source, course_name_destination);

}


ostream& operator<<(ostream& out, Student& a)
{
	out << "Ten cua sinh vien la: " << a.name;
	out << a.schedule;
	return out;
}