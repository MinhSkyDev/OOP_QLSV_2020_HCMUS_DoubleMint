#include "Roster.h"

Roster::Roster() {
	roster = nullptr;
	numOfCourses = 0;
	numOfStudents = 0;
}

Roster::~Roster() {
	if (roster != nullptr) {
		delete[] roster;
		roster = nullptr;
	}
	numOfCourses = 0;
	numOfStudents = 0;
}

Roster::Roster(Roster& r) {
	if (roster != nullptr)
		delete[] roster;
	roster = new string[r.numOfCourses];
	numOfCourses = r.numOfCourses;
	numOfStudents = r.numOfStudents;
	for (int i = 0; i < numOfCourses; i++)
		roster[i] = r.roster[i];
}

void Roster::operator=(Roster& r) {
	if (roster != nullptr)
		delete[] roster;
	roster = new string[r.numOfCourses];
	numOfCourses = r.numOfCourses;
	numOfStudents = r.numOfStudents;
	for (int i = 0; i < numOfCourses; i++)
		roster[i] = r.roster[i];
}

// Y tuong giong nhu o ben class Schedule, khi kiem tra mot hau to co nam trong khoa hoc
// hay khong, ta kiem tra no voi mot mang phu la cac tien to duoc ghi in hoa het, cac tu
// cach nhay boi 1 dau cach, dam bao cho viec tim kiem chinh xac

string normalizeString(string inp) {
	// Vi du:
	// input: ' asd  123 456  '
	// Output: 'asd 123 456'
	for (unsigned int i = 0; i < inp.size(); i++)
		inp[i] = toupper(inp[i]);
	while (inp[0] == ' ')
		inp.erase(0, 1);
	int j = 0;
	while (j < inp.size() - 1) {
		if (inp[j] == ' ' && inp[j + 1] == ' ')
			inp.erase(j + 1, 1);
		else
			j++;
	}
	return inp;
}

int Roster::isCourseHaveRoster(const string& roster_find) {
	// Chuan hoa chuoi roster can tim kiem
	string tempRoster = normalizeString(roster_find);

	// Linear search the roster in list
	for (int i = 0; i < numOfCourses; i++) {
		string temp = normalizeString(roster[i]);
		if (tempRoster == temp)
			return i;
	}
	return -1;
}

void Roster::addRoster(string roster_name) {
	// Kiem tra ten hau to cua khoa hoc da co hay chua
	if (isCourseHaveRoster(roster_name) != -1) {
		cout << "Lop nay da ton tai trong khoa hoc roi!\n";
		return;
	}
	// Mot khoa hoc chi toi da 40 sinh vien dang ki
	else if (numOfStudents == 40) {
		cout << "Lop nay da day, khong dang ki duoc nua!\n";
		return;
	}
	int newSize = numOfCourses + 1;		// Create this to avoid C6385 warning from IDE
	string* tempRoster = new string[newSize];
	for (int i = 0; i < newSize - 1; i++)
		tempRoster[i] = roster[i];
	tempRoster[numOfCourses] = roster_name;
	delete[] roster;
	roster = tempRoster;
}

void Roster::updateRoster(string roster_name_src, string roster_name_dst) {
	int ind = isCourseHaveRoster(roster_name_src);
	if (ind == -1) {
		cout << "Lop hoc khong co trong danh sach lop cua mon hoc nay!\n";
		return;
	}
	roster[ind] = roster_name_dst;
}

void Roster::deleteRoster(string roster_name) {
	int ind = isCourseHaveRoster(roster_name);
	if (ind == -1) {
		cout << "Lop hoc khong co trong danh sach lop cua mon hoc nay!\n";
		return;
	}
	else if (numOfCourses == 0) {
		cout << "Mon hoc chua phan lop!\n";
		return;
	}
	int newSize = numOfCourses - 1;		// Create this to avoid C6385 warning from IDE

	string* tempRoster = new string[newSize];
	for (int i = 0; i < ind; i++)
		tempRoster[i] = roster[i];
	for (int i = ind; i < newSize; i++) 
		tempRoster[i] = roster[i + 1];
	numOfCourses--;

	delete[] roster;
	roster = tempRoster;
}

ostream& operator<<(ostream& out, Roster& r) {
	cout << "Danh sach cac lop hoc cua mon hoc nay la:\n";
	for (int i = 0; i < r.numOfCourses; i++)
		out << r.roster[i] << '\n';
	return out;
}
