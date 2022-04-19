#include "Schedule.h"

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
