#include "Registar.h"
#include "Function.h"
#include <sstream>

Registar::Registar() {
	this->courses = nullptr;
	this->students = nullptr;
}

Registar::~Registar() {
	if (courses != nullptr) {
		delete[] courses;
		courses = nullptr;
	}
	if (students != nullptr) {
		delete[] students;
		students = nullptr;
	}
}

Registar::Registar(Registar& a) {
	if (courses != nullptr) {
		delete[] courses;
		courses = nullptr;
	}
	courses = a.courses;
	if (students != nullptr) {
		delete[] students;
		students = nullptr;
	}
	students = a.students;
}

void Registar::operator=(Registar& a) {
	if (courses != nullptr) {
		delete[] courses;
		courses = nullptr;
	}
	courses = a.courses;
	if (students != nullptr) {
		delete[] students;
		students = nullptr;
	}
	students = a.students;
}

void Registar::regSinhVien(Student& student, Courses& course) {
	// Ghi ra danh sach cac lop hoc cua mon course
	// Nguoi dung nhap vao lop muon dang ky
	// Kiem tra lop do co ton tai hay khong
	// Neu co goi student.addCourse(ten lop hoc day du, vi du OOP_CTT2)
	// Phat sinh van de gop chuoi course + subcourse
	cout << "Danh sach cac lop hoc cua mon " << course.getName() << '\n';
	cout << course << '\n';
	cout << "Nhap vao ten lop muon dang ki, vi du: CTT2 (Hoa thuong deu duoc): ";
	string rosterName;
	getline(cin, rosterName);
	normalizeString(rosterName);
	if (course.isHaveRoster(rosterName) == -1)
		cout << "Khong ton tai lop hoc ten " << rosterName << " trong mon " << course.getName() << "!\n";
	else
		student.addCourse(course.getName() + "_" + rosterName);
}

void Registar::regSinhVien(int student_index, int course_index) {
	this->regSinhVien(this->students[student_index], this->courses[course_index]);
}

// Sinh vien huy dang ky mon hoc
void Registar::delCoursesFromStudent(Student& student, string del) {
	// del la ten mot mon hoc, vi du: OOP
	normalizeString(del);

	Schedule Sch = student.getSchedule();
	string* temp = Sch.getCourses();
	int n = Sch.getQuantity();
	for (int i = 0; i < n; i++) {
		istringstream ss(temp[i]);
		string token;
		getline(ss, token, '_');
		if (token == del) {
			student.deleteCourse(temp[i]);
			return;
		}
	}
}

void Registar::printCoursesFromStudent(Student& student) {
	cout << student;
}


void Registar::printSubCourse(Courses& a) {
	cout << a;
}

int Registar::isStudentInList(string name_input) {
	
}

int Registar::isCourseInList(string name_input) {
	return 0;
}

void Registar::printSubCourse(int course_index) {
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

void Registar::addOneStudent(string name_input) {
	students->getName();
}

void Registar::addOneCourse(string name_input) {

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
