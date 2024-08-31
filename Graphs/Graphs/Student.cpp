
#include "Student.h"
#include <stdexcept>
#include <iostream>

string Student::toString()
{
	return string(name);
}

// Original
string FindCourseName(list<Student> stu, string name) {
	for (list<Student>::iterator it = stu.begin(); it != stu.end(); it++) {
		if ((*it).toString() == name) {
			return it->courseName;
		}
	}
	return "";
}

//Refactored
string FindCourseName(list<Student>& stu, string name) {
	for (list<Student>::iterator it = stu.begin(); it != stu.end(); it++) {
		if (strcmp( (*it).name, name.c_str()) ) {
			return it->courseName;
		}
	}
	return "";
}

//Refactored2
string FindCourseName(const list<Student>& stu, const string name) {
	//for (list<Student>::iterator it = stu.begin(); it != stu.end(); it++) {
	for (const Student& it : stu) {
		if (strcmp(it.name, name.c_str())) {
			return it.courseName;
		}
	}
	return "";
}




using namespace std;

void process(const unique_ptr<int[]>& h1, const unique_ptr<int[]>& h2) {
	// ... 
}
int* create(unsigned size) {
	if (size == 0 || size == 1) {
		throw runtime_error("create: runtime error");
	}
	//return new int(size); 
	return new int[size];
}
void run(unsigned size) {
	try {
		//auto* h1 = create(size); 
		unique_ptr<int[]> h1(create(size));
		//auto* h2 = create(size/2); 
		unique_ptr<int[]> h2(create(size / 2));
		process(h1, h2);
		//delete[] h1;
		//delete[] h2;
	}
	catch (runtime_error& ex) {
		cerr << ex.what() << endl;
	}
}





