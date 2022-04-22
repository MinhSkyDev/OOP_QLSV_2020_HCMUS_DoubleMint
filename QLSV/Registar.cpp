#include "Registar.h"

Registar::Registar()
{
	this->courses = nullptr;
	this->students = nullptr;
}

Registar::~Registar()
{
}

Registar::Registar(Registar& a)
{
}

void Registar::operator=(Registar& a)
{
}

void Registar::regSinhVien(Student& student, Courses& course)
{

}

void Registar::regSinhVien(int student_index, int course_index)
{
	this->regSinhVien(this->students[student_index], this->courses[course_index]);
}

void Registar::delCoursesFromStudent(Student& student, Courses del)
{
}

void Registar::printCoursesFromStudent(Student& student)
{
}


void Registar::printSubCourse(Courses& a)
{
	cout << a;
}

int Registar::isStudentInList(string name_input)
{
	return 0;
}

int Registar::isCourseInList(string name_input)
{
	return 0;
}

void Registar::printSubCourse(int course_index)
{
	this->printSubCourse(this->courses[course_index]);
}

void Registar::printStudentFromCourse(Courses& a)
{
}

int Registar::countStudentsInACourse(Courses a)
{
	return 0;
}

void Registar::updateSubCourseFromStudent(Student& student, Courses& course) {
	cout << endl;
	cout << "Danh sach cac lop hoc trong lop " << course.getName() << ": \n";
	cout << course;
	
	cout << "Xin moi nhap lop hoc ma ban muon thay doi: ";
	string name_courseSub;
	getline(cin, name_courseSub);
	cout << endl;
	while (course.isHaveRoster(name_courseSub) == false) {
		cout << "Ten lop ko hop le, xin moi nhap lai: ";
		getline(cin, name_courseSub);
		cout << endl;
	}
	string name_course_sub_dst;
	cout << "Xin moi nhap lop ban muon doi: ";
	getline(cin, name_course_sub_dst);
	course.updateRoster(name_courseSub, name_course_sub_dst);
}

void Registar::addOneStudent(string name_input)
{
}

void Registar::addOneCourse(string name_input)
{
}

Courses& Registar::getCourseIndex(int index)
{
	
	//Check legit index
	return courses[index];
}

Student& Registar::getStudentIndex(int index)
{
	//check legit index
	return students[index];
}
