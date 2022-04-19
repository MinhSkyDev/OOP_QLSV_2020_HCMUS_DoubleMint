#pragma once
#include "Courses.h"
#include "Student.h"
class Registar
{
private:
	Student* student;
	Courses* courses;
public:

	

	//CRUD Create Read Update Delete
	void regSinhVien(Student& student, Courses& courses); // Dang ky SinhVien vao mot khoa hoc nao do
	void delCoursesFromSinhVien(Student& student, Courses del); // Xoa SinhVien khoi mot khoa hoc nao do
	void printCoursesFromSinhVien(Student& student); // In danh sach cac khoa hoc ma Sinh Vien nay dang theo hoc
	void printSinhVienFromCourse(Courses& a);

	//
	
};

