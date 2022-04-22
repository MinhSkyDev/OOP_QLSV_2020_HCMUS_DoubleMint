#include "Schedule.h"
#include "Function.h"

Schedule::Schedule() {
	courses = nullptr;
	quantity = 0;
}

Schedule::~Schedule() {
	if (courses != nullptr) {
		delete[] courses;
	}
	quantity = 0;
}

Schedule::Schedule(Schedule& a) {
	if (courses != nullptr)
		delete[] courses;
	this->quantity = a.quantity;
	this->courses = new string[a.quantity];
	for (int i = 0; i < this->quantity; i++)
		this->courses[i] = a.courses[i];
}

void Schedule::operator=(Schedule a) {
	if (this->courses != nullptr) {
		//Truong hop ma neu da khoi tao bang Constructor-ThamSo hoac da co them bot courses
		delete[] this->courses;
		this->courses = nullptr;
	}
	string* courses_new = new string[a.quantity];
	this->quantity = a.quantity;
	for (int i = 0; i < this->quantity; i++)
		courses_new[i] = a.courses[i];
	this->courses = courses_new;
}

int Schedule::isStudentHaveCourse(const string & course_find) {
	//Thuat toan tim kiem lieu SinhVien co khoa hoc can tim hay ko
	//Neu nhu trong danh sach khoa hoc string* courses co chua lop hoc la "OOP_CTT1"
	//Va input dau vao trong ham vo la course_find = "oop_cTt1" 
	//Van thoa duoc khoa hoc can tim => Ta se tao ra cac string phu la cac string duoc viet hoa toan bo cac ky tu

	//Toupper input course
	string course_find_capital = normalizeString(course_find);

	//Linear search courses in list
	for (int i = 0; i < this->quantity; i++) {
		string temp_course = normalizeString(this->courses[i]);
		if (course_find_capital == temp_course)
			return i;
	}
	return -1;
}



void Schedule::addCourse(string course_name) {
	//Kiem tra trong danh sach dang ky da co lop hoc nay chua 
	if (isStudentHaveCourse(course_name) != -1) {
		cout << "Hoc sinh da dang ky lop nay roi, khong the dang ky them \n";
		return;
	}
	//Mot sinh vien chi duoc phep co toi da 5 khoa hoc trong thoi khoa biet
	if (quantity == 5) {
		cout << "Sinh vien vuot qua so lop hoc quy dinh \n";
		return;
	}
	string* courses_temp = new string[++this->quantity];
	for (int i = 0; i < this->quantity - 1; i++)
		courses_temp[i] = this->courses[i];

	courses_temp[--this->quantity] = course_name;
	this->quantity++; 
	delete[] this->courses;
	this->courses = courses_temp;
}

void Schedule::deleteCourse(string course_name) {

	//Get the index of the removing element
	int indexToRemove = isStudentHaveCourse(course_name);
	//Check if the Course is not exist in the course list
	if (indexToRemove == -1) {
		cout << "Sinh vien khong dang ky lop hoc nay \n";
		return;
	}
	if (this->quantity == 0)
		cout << "Danh sach khoa hoc cua sinh vien rong ! \n";
	
	string* course_temp = new string[this->quantity - 1];
	//Copy the most left of the array
	int count = 0;
	for (int i = 0; i <= indexToRemove - 1; i++)
		course_temp[count++] = this->courses[i];

	//copy the most right of the array
	for (int i = indexToRemove + 1; i < this->quantity; i++)
		course_temp[count++] = this->courses[i];

	this->quantity--;
	delete[] this->courses;
	this->courses = course_temp;
}

void Schedule::updateCourse(string course_name_src, string course_name_dst) {
	int indexToUpdate = isStudentHaveCourse(course_name_src);
	if (indexToUpdate == -1) {
		cout << "Sinh vien khong dang ky lop hoc nay \n";
		return;
	}
	this->courses[indexToUpdate] = course_name_dst;
}

string* Schedule::getCourses()
{
	return courses;
}

int Schedule::getQuantity()
{
	return quantity;
}

ostream& operator<<(ostream& out, Schedule& a) {
	out << "\nDanh sach cac khoa hoc ma sinh vien nay tham gia la: \n";
	for (int i = 0; i < a.quantity; i++)
		out << "Khoa hoc thu " << i + 1 << " :" << a.courses[i] << endl;
	return out;
}