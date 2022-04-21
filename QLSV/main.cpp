#include "Registar.h"


void Menu() {


}


int main() {
	/*Menu();
	return 0;*/
	Student a;
	a.addCourse("OOP_CTT1");
	a.addCourse("CSDL_CTT1");
	a.addCourse("HTMT_CTT2");
	a.addCourse("OOP_CTT1");
	cout << a << '\n';
	Courses b;
	b.setName("OOP");
	b.addRoster("CTT1");
	b.addRoster("CTT2");
	b.addRoster("CTT2");
	cout << b;
}