#pragma once
#include "Courses.h"
#include "Student.h"
class Registar
{
private:
	Student* student;
	Courses* courses;
public:

	Registar();
	~Registar();
	Registar(Registar& a);
	void operator=(Registar& a);

	//Input SinhVien
	void addOneStudent();

	//CRUD Create Read Update Delete
	void regSinhVien(Student& student, Courses& courses); // Dang ky SinhVien vao mot khoa hoc nao do
	void delCoursesFromStudent(Student& student, Courses del); // Xoa SinhVien khoi mot khoa hoc nao do
	void printCoursesFromStudent(Student& student); // In danh sach cac khoa hoc ma Sinh Vien nay dang theo hoc
	
	//In cac SinhVien nao ma hoc course dau vao
	void printStudentFromCourse(Courses& a);

	int countStudentsInACourse(Courses a);
	
};

