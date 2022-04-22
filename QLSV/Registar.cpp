#include "Registar.h"
#include "Function.h"
#include <sstream>

Registar::Registar() {
	this->courses = nullptr;
	this->students = nullptr;
	this->nStudents = 0;
	this->nCourses = 0;
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
	for (int i = 0; i < this->nStudents; i++)
	{
		if (students[i].getName() == name_input)
			return i;
	}
	return -1;
}

int Registar::isCourseInList(string name_input) {
	for (int i = 0; i < this->nCourses; i++)
	{
		if (courses[i].getName() == name_input)
			return i;
	}
	return -1;
}

void Registar::printSubCourse(int course_index) {
	this->printSubCourse(this->courses[course_index]);
}

void Registar::printStudentFromCourse(Courses& a)
{
	cout << a;
}

int Registar::countStudentsInACourse(string a)
{
	int count = 0;
	string courseName = a;
	for (int i = 0; i < nStudents; i++) {
		Schedule Sch = students[i].getSchedule();		// Thoi khoa bieu cua sinh vien i
		string* temp = Sch.getCourses();		// Mang cac courses ma sinh vien i dang ki 
		int n = Sch.getQuantity();				// So luong courses ma sinh vien i dang ki
		for (int j = 0; j < n; j++) {
			istringstream ss(temp[j]);
			string token;
			getline(ss, token, '_');
			if (token == courseName)
				count++;
		}
	}
	return count;
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

	//string convert
	name_courseSub = course.getName() + "_" + name_courseSub;
	name_course_sub_dst = course.getName() + "_" + name_course_sub_dst;
	student.updateCourse(name_courseSub, name_course_sub_dst);
}


void Registar::addSubCourseIntoCourse(Courses& course)
{
	cout << "Danh sach hien tai cua khoa hoc " << course.getName() << " :\n";
	cout << course;

	cout << "Xin moi nhap ten lop hoc con ban muon them (Vd: CTT2, CTT3): ";
	string input_name;
	getline(cin, input_name);

	//check trong course co hau to lop hoc con chua 
	while (course.isHaveRoster(input_name)) {
		cout << "\nLop hoc da ton tai trong danh sach, xin moi nhap lai: ";
		getline(cin, input_name);
	}

	//Neu co roi thi them vo
	course.addRoster(input_name);
	cout << "Da them lop " << course.getName() << "_" << input_name << "vao danh sach !";
}

void Registar::updateSubCourseFormCourse(Courses& course)
{
	cout << "Danh sach cac lop trong khoa hoc " << course.getName() << " :\n";
	cout << course;

	cout << endl << "Xin moi nhap ten lop hoc ma ban muon doi: ";
	string course_src, course_dst;
	getline(cin, course_src);

	//Check course_src co trong danh sach ko, ko thi bat nhap lai 
	while (course.isHaveRoster(course_src) == false)
	{
		cout << "Lop hoc khong ton tai trong danh sach, xin moi nhap lai: ";
		getline(cin, course_src);
	}
	cout << endl;
	
	cout << "Ban muon chuyen lop " << course.getName() << "_" << course_src << " thanh ten gi ?:";
	getline(cin, course_dst);
	cout << endl;
	//check course_dst co ton tai trong danh sach ko, neu co thi bat nhap lai
	while (course.isHaveRoster(course_dst) == true)
	{
		cout << "Lop hoc da ton tai trong danh sach, xin moi nhap lai: ";
		getline(cin, course_dst);
		cout << endl;
	}
		
	course.updateRoster(course_src, course_dst);
	cout << "Da hoan thanh viec doi ten lop !\n";
}

void Registar::addOneStudent(string name_input)
{
	int nStudents_new = this->nStudents + 1;
	Student* students_new = new Student[nStudents_new];

	//Copy all from the old array
	for (int i = 0; i < this->nStudents; i++)
	{
		students_new[i] = this->students[i];
	}
	Student add;
	add.setName(name_input);
	students_new[this->nStudents] = add;
	delete[] this->students;
	this->students = students_new;
	this->nStudents = nStudents_new;
}

void Registar::addOneCourse(string name_input) {
	int nCourses_new = this->nCourses + 1;
	Courses* courses_new = new Courses[nCourses_new];

	//Copy all from the old array
	for (int i = 0; i < this->nCourses; i++)
	{
		courses_new[i] = courses[i];
	}

	Courses add;
	add.setName(name_input);
	courses_new[this->nCourses] = add;
	delete[] this->courses;
	this->courses = courses_new;
	this->nCourses = nCourses_new;
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
