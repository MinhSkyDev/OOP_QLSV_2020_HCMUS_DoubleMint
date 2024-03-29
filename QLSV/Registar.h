#pragma once
#include "Courses.h"
#include "Student.h"
class Registar
{
private:
	Student* students;
	Courses* courses;
	int nStudents;
	int nCourses;
public:

	Registar();
	~Registar();
	Registar(Registar& a);
	void operator=(Registar& a);

	//Input SinhVien,Khoa Hoc
	void addOneStudent(string name_input);
	void addOneCourse(string name_input);
	void deleteCourse(int indexCourse);
	void deleteStudent(int indexStudent);


	//Getter Setter
	Courses& getCourseIndex(int index);
	Student& getStudentIndex(int index);

	//CRUD Create Read Update Delete
	void regSinhVien(Student& student, Courses& course); // Dang ky SinhVien vao mot khoa hoc nao do
	void regSinhVien(int student_index, int course_index);
	void delCoursesFromStudent(Student& student, string del); // Xoa SinhVien khoi mot khoa hoc nao do
	void delCoursesFromStudent(Courses& course); // Xoa tat cac cac sinh vien theo hoc lop nay
	void printCoursesFromStudent(Student& student); // In danh sach cac khoa hoc ma Sinh Vien nay dang theo hoc
	void updateSubCourseFromStudent(Student& student, Courses& a); //Update lop hoc ma Sinh Vien Dang ky
	void addSubCourseIntoCourse(Courses& course); //Them mot lop vao mot khoa hoc
	void updateSubCourseFormCourse(Courses& course); // Update mot lop trong khoa hoc

	//Check
	int isStudentInList(string name_input);
	int isCourseInList(string name_input);
	bool isStudentEmpty();
	bool isCourseEmpty();
	
	//In cac SinhVien nao ma hoc course dau vao
	void printStudentFromCourse(Courses& a);
	int countStudentsInACourse(string a);
	void printSubCourse(Courses& a);
	void printSubCourse(int course_index);


	//Print all name Students
	void printAllStudents();
	//print all name Courses
	void printAllCourses();
	//Print all Students data
	void printAllStudentsData();
	//Print all Course Data
	void printAllCoursesData();

	int countCoursesFromStudent(Student& a);


};




