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


			cout << "Xin moi nhap mon hoc ma Sinh Vien dang ky: ";
			string name_Course;
			getline(cin, name_Course);
			int indexCourse = moodle.isCourseInList(name_Course);
			cout << endl;
			while (indexCourse == -1) {
				cout << "Lop hoc ko co trong danh sach, xin nhap lai: ";
				getline(cin, name_Course);
				indexCourse = moodle.isCourseInList(name_Course);
				cout << endl;
			}

			moodle.regSinhVien(indexStudent, indexCourse);

			cout << "Da dang ky lop hoc " << name_Course << " cho Sinh Vien " << name_Student << " thanh cong !\n";
			system("pause");
		}
		else if (selection == 4)
		{
			system("cls");
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
			system("pause");
		}
		else if (selection == 8)
		{
			system("cls");
			system("pause");
		}
		else if (selection == 9)
		{
			system("cls");
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