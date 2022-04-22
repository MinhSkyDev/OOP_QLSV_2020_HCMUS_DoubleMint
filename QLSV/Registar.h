#pragma once
#include "Courses.h"
#include "Student.h"
class Registar
{
private:
	Student* students;
	Courses* courses;
public:

	Registar();
	~Registar();
	Registar(Registar& a);
	void operator=(Registar& a);

	//Input SinhVien,Khoa Hoc
	void addOneStudent(string name_input);
	void addOneCourse(string name_input);

	//Getter Setter
	Courses& getCourseIndex(int index);
	Student& getStudentIndex(int index);

	//CRUD Create Read Update Delete
	void regSinhVien(Student& student, Courses& course); // Dang ky SinhVien vao mot khoa hoc nao do
	void regSinhVien(int student_index, int course_index);
	void delCoursesFromStudent(Student& student, string del); // Xoa SinhVien khoi mot khoa hoc nao do
	void printCoursesFromStudent(Student& student); // In danh sach cac khoa hoc ma Sinh Vien nay dang theo hoc
	void updateSubCourseFromStudent(Student& student, Courses& a); //Update lop hoc ma Sinh Vien Dang ky


	//Check
	int isStudentInList(string name_input);
	int isCourseInList(string name_input);
	
	//In cac SinhVien nao ma hoc course dau vao
	void printStudentFromCourse(Courses& a);
	int countStudentsInACourse(Courses a);
	void printSubCourse(Courses& a);
	void printSubCourse(int course_index);



};




