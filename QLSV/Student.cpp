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

Schedule Student::getSchedule() {
	return this->schedule;
}