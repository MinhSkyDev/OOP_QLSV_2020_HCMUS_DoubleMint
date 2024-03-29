#include "Menu.h"

Menu::Menu() {


}

Menu::~Menu() {

}

void Menu::init() {

	while (true) {
		system("cls");
		int selection;
		cout << "--------------Chuong trinh quan ly sinh vien va khoa hoc--------------\n";
		cout << "Chon 1 de them mot Sinh Vien vao chuong trinh !\n";
		cout << "Chon 2 de them mot Khoa Hoc vao chuong trinh !\n";
		cout << "Chon 3 de dang ky mon hoc cho Sinh Vien !\n";
		cout << "Chon 4 de cap nhat mon hoc ma Sinh Vien da dang ky \n";
		cout << "Chon 5 de them mot lop hoc con nam trong mot Khoa Hoc \n";
		cout << "Chon 6 de cap nhat cac khoa hoc con nam trong mot Khoa Hoc \n";
		cout << "Chon 7 de huy dang ky mot mon hoc cho Sinh Vien \n";
		cout << "Chon 8 de xoa mot Sinh Vien ra khoi chuong trinh \n";
		cout << "Chon 9 de xoa mot Khoa Hoc ra khoi chuong trinh \n";
		cout << "Chon 10 de hien thi toan bo thong tin cua Sinh Vien trong chuong trinh \n";
		cout << "Chon 11 de hien thi toan bo thong tin ve khoa hoc trong chuong trinh \n";
		cout << "Chon 0 de thoat khoi chuong trinh \n";

		cout << endl << endl;
		cout << "Xin moi nhap lua chon cua ban: "; cin >> selection;
		if (selection == 1)
		{
			system("cls");
			string name_input;
			cin.ignore();
			cout << "Xin moi nhap ten cua Sinh Vien muon them vao danh sach: ";
			getline(cin, name_input);

			//Neu nhu SinhVien co trong danh sach thi phai nhap lai
			while (moodle.isStudentInList(name_input) != -1)
			{
				cout << endl;
				cout << "Sinh vien da ton tai trong danh sach, xin vui long nhap lai: ";
				getline(cin, name_input);
			}
			moodle.addOneStudent(name_input);
			cout << "\nSinh vien " << name_input << " da duoc them vao danh sach \n";
			system("pause");
		}
		else if (selection == 2)
		{

			system("cls");
			string name_input;
			cin.ignore();
			cout << "Xin moi nhap ten cua Khoa Hoc muon them vao danh sach: ";
			getline(cin, name_input);

			while (moodle.isCourseInList(name_input) != -1)
			{
				cout << "\nKhoa hoc da ton tai trong danh sach, xin moi nhap lai: ";
				getline(cin, name_input);
			}
			moodle.addOneCourse(name_input);
			cout << "\nKhoa hoc " << name_input << " da duoc them vao danh sach !\n";
			system("pause");
		}
		else if (selection == 3)
		{
			system("cls");
			if (moodle.isCourseEmpty() == true && moodle.isStudentEmpty() == true)
			{
				cout << "Ban chua them khoa hoc va sinh vien nao vao trong chuong trinh !\n";
				system("pause");
				continue;
			}
			else if (moodle.isCourseEmpty())
			{
				cout << "Ban chua them khoa hoc nao vao danh sach !\n";
				system("pause");
				continue;
			}
			else if (moodle.isStudentEmpty())
			{
				cout << "Ban chua them Sinh Vien nao vao danh sach !\n";
				system("pause");
				continue;
			}
			cin.ignore();
			cout << "Xin moi nhap ten Sinh Vien dang ky mon hoc: ";
			string name_Student;
			getline(cin, name_Student);
			cout << endl;
			int indexStudent = moodle.isStudentInList(name_Student);
			while (indexStudent == -1) {
				cout << "Sinh vien ko co trong danh sach, xin nhap lai: ";
				getline(cin, name_Student);
				indexStudent = moodle.isStudentInList(name_Student);
				cout << endl;
			}

			if (moodle.countCoursesFromStudent(moodle.getStudentIndex(indexStudent)) 
																		>= 5)
			{
				cout<<"Sinh vien "<<name_Student<<" da dang ky qua 5 mon hoc, khong the dang ky nua ! \n";
				system("pause");
				continue;
			}

			cout << "Xin moi nhap mon hoc ma Sinh Vien dang ky: ";
			string name_Course;
			getline(cin, name_Course);
			int indexCourse = moodle.isCourseInList(name_Course);
			cout << endl;
			while (indexCourse == -1) {
				cout << "Khoa hoc ko co trong danh sach, xin nhap lai: ";
				getline(cin, name_Course);
				indexCourse = moodle.isCourseInList(name_Course);
				cout << endl;
			}

			if (moodle.countStudentsInACourse(name_Course) >= 40)
			{
				cout << "Lop da day, khong the dang ky nua ! \n";
				system("pause");
				continue;
			}

			moodle.regSinhVien(indexStudent, indexCourse);
			system("pause");
		}
		else if (selection == 4)
		{
			system("cls");

			if (moodle.isStudentEmpty())
			{
				cout << "Ban chua them Sinh Vien nao vao danh sach !";
				system("pause");
				continue;
			}


			cin.ignore();
			cout << "Xin moi nhap ten Sinh Vien muon cap nhat mon hoc: ";

			//Lay index SinhVien muon cap nhat
			string name_Student;
			getline(cin, name_Student);
			int indexStudent = moodle.isStudentInList(name_Student);
			while (indexStudent == -1) {
				cout << "Sinh vien ko co trong danh sach, xin nhap lai: ";
				getline(cin, name_Student);
				indexStudent = moodle.isStudentInList(name_Student);
				cout << endl;
			}

			//Lay ten mon hoc muon cap nhat
			cout << "Xin moi nhap khoa hoc ma ban muon cap nhat: ";
			string name_Course;
			getline(cin, name_Course);
			int indexCourse = moodle.isCourseInList(name_Course);
			while (indexCourse == -1)
			{
				cout << "Lop hoc ko co trong danh sach, xin nhap lai: ";
				getline(cin, name_Course);
				indexCourse = moodle.isCourseInList(name_Course);
				cout << endl;
			}

			cout << endl;
			moodle.updateSubCourseFromStudent(moodle.getStudentIndex(indexStudent), moodle.getCourseIndex(indexCourse));
			system("pause");
		}
		else if (selection == 5)
		{
			system("cls");
			cin.ignore();


			if (moodle.isCourseEmpty()) {
				cout << "Ban chua them mot khoa hoc nao vao trong danh sach !\n";
				system("pause");
				continue;
			}


			cout << "Xin moi nhap ten khoa hoc ban muon them lop hoc: ";
			string name_Course;
			getline(cin, name_Course);

			int indexCourse = moodle.isCourseInList(name_Course);
			while (indexCourse == -1) //Input Course_name, vd: OOP
			{
				cout << "Khoa hoc khong ton tai trong danh sach, xin moi nhap lai: ";
				getline(cin, name_Course);
				indexCourse = moodle.isCourseInList(name_Course);
			}

			moodle.addSubCourseIntoCourse(moodle.getCourseIndex(indexCourse));

			system("pause");
		}
		else if (selection == 6)
		{
			system("cls");
			cin.ignore();

			if (moodle.isCourseEmpty()) {
				cout << "Ban chua them mot khoa hoc nao vao trong danh sach !\n";
				system("pause");
				continue;
			}

			cout << "Xin moi nhap ten khoa hoc ban muon sua: ";
			string name_Course;
			getline(cin, name_Course);

			int indexCourse = moodle.isCourseInList(name_Course);
			while (indexCourse == -1)
			{
				cout << "Khoa hoc khong ton tai trong danh sach, xin moi nhap lai: ";
				getline(cin, name_Course);
				indexCourse = moodle.isCourseInList(name_Course);
			}

			moodle.updateSubCourseFormCourse(moodle.getCourseIndex(indexCourse));
			system("pause");
		}
		else if (selection == 7)
		{
			system("cls");
			cin.ignore();

			if (moodle.isCourseEmpty() == true && moodle.isStudentEmpty() == true)
			{
				cout << "Ban chua them khoa hoc va sinh vien nao vao trong chuong trinh !\n";
				system("pause");
				continue;
			}
			else if (moodle.isCourseEmpty())
			{
				cout << "Ban chua them khoa hoc nao vao danh sach !\n";
				system("pause");
				continue;
			}
			else if (moodle.isStudentEmpty())
			{
				cout << "Ban chua them Sinh Vien nao vao danh sach !\n";
				system("pause");
				continue;
			}

			cout << "Xin moi nhap ten sinh vien muon huy dang ky mon hoc: ";
			string name_Student;
			getline(cin, name_Student);

			cout << endl;
			int indexStudent = moodle.isStudentInList(name_Student);
			while (indexStudent == -1)
			{
				cout << "Sinh vien khong co trong danh sach, xin moi nhap lai: ";
				getline(cin, name_Student);
				cout << endl;
				indexStudent = moodle.isStudentInList(name_Student);
			}

			//In cac lop hoc ma sinh vien nhap vo hoc
			moodle.printCoursesFromStudent(moodle.getStudentIndex(indexStudent));

			cout << "\nXin moi nhap ten lop hoc ma ban muon huy dang ky (Ten day du cua lop hoc, vd: OOP_CTT1) : ";
			string name_Course;
			getline(cin, name_Course);
			moodle.delCoursesFromStudent(moodle.getStudentIndex(indexStudent), name_Course);


			cout << "\nDa huy dang ky thanh cong !\n";
			system("pause");
		}
		else if (selection == 8)
		{
			system("cls");
			cin.ignore();

			if (moodle.isStudentEmpty())
			{
				cout << "Ban chua them Sinh Vien nao vao danh sach !";
				system("pause");
				continue;
			}


			moodle.printAllStudents();
			cout << endl;

			cout << "Xin moi nhap ten sinh vien ma ban muon xoa khoi chuong trinh : ";
			string name_Student;
			getline(cin, name_Student);

			int indexStudent = moodle.isStudentInList(name_Student);
			while (indexStudent == -1) {
				cout << "Sinh vien khong co trong danh sach, xin moi nhap lai: ";
				getline(cin, name_Student);
				cout << endl;
				indexStudent = moodle.isStudentInList(name_Student);
			}

			moodle.deleteStudent(indexStudent);
			cout << "Da xoa sinh vien khoi danh sach ! \n";
			system("pause");
		}
		else if (selection == 9)
		{
			system("cls");
			cin.ignore();

			if (moodle.isCourseEmpty())
			{
				cout << "Ban chua them khoa hoc nao vao danh sach !";
				system("pause");
				continue;
			}

			moodle.printAllCourses();
			cout << endl;

			cout << "Xin moi nhap ten khoa hoc ban muon xoa khoi chuong trinh: ";
			string name_Course;
			getline(cin, name_Course);
			cout << endl;
			int indexCourse = moodle.isCourseInList(name_Course);
			while (indexCourse == -1)
			{
				cout << "Khoa hoc khong co trong danh sach, xin moi nhap lai: ";
				getline(cin, name_Course);
				indexCourse = moodle.isCourseInList(name_Course);
			}
			moodle.delCoursesFromStudent(moodle.getCourseIndex(indexCourse));
			moodle.deleteCourse(indexCourse);
			cout << "Da xoa khoa hoc khoi danh sach ! \n";
			system("pause");
		}
		else if(selection == 10){
			system("cls");
			if (moodle.isStudentEmpty()) {
				cout << "Khong co sinh vien nao trong chuong trinh !\n";
			}
			else {
				moodle.printAllStudentsData();
			}
			system("pause");
		}
		else if (selection == 11) {
			system("cls");
			if (moodle.isCourseEmpty()) {
				cout << "Khong co khoa hoc nao trong chuong trinh !\n";
			}
			else {
				moodle.printAllCoursesData();
			}
			system("pause");
		}
		else if (selection == 0)
		{
			cout << "--------------Cam on da su dung chuong trinh--------------\n";
			system("pause");
			break;
		}
	}
}