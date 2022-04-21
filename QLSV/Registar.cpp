#include "Registar.h"

Registar::Registar()
{
	this->courses = nullptr;
	this->students = nullptr;
}

void Registar::regSinhVien(Student& student, Courses& course)
{

}

void Registar::regSinhVien(int student_index, int course_index)
{
	this->regSinhVien(this->students[student_index], this->courses[course_index]);
}