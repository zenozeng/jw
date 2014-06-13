#include "student_view.hpp"

using namespace std;

void StudentView::help () {
	cout << "Type following commands for further step:" << endl;
	cout << "	help: get help" << endl;
	cout << "	courses: get courses for this term" << endl; 
	cout << "	exit: logout and exit" << endl;
}

void StudentView::dispatch (string cmd) {
	if (cmd == "help") {
        return this->help();
    }
	if (cmd == "courses") {
        return this->get_courses();
    }
	cout << "Command not found." << endl;
	help();
}

void StudentView::get_courses () {
	string course, teacher;
	string course_id_str = course_manager.get("/");
	vector<string> courses = split(course_id_str, '\n');

	cout << "id	name	teacher" << endl;
	for (int i = 0, length = courses.size(); i < length; i++) {
		course = course_manager.get(courses[i], "name");
		teacher = course_manager.get(courses[i], "teacher");
		cout << courses[i] << "	" << course << "	" << teacher << endl;
	}
	cout << endl;
	cout << "Type course id to see more information." << endl;
}

void StudentView::get_course (string course_id) {
	string name = course_manager.get(course_id, "name");
	string teacher_id = course_manager.get(course_id, "teacher");
	string teacher_name = user_manager.get(teacher_id, "name");
	string semester = course_manager.get(course_id, "semester");
	string time = course_manager.get(course_id, "time");
	string location = course_manager.get(course_id, "location");

	cout << "Name:	" << name << endl;
	cout << "Teacher:	" << teacher_name << endl;
	cout << "Semester:	" << semester << endl;
	cout << "Time:	" << time << endl;
	cout << "Location:	" << location << endl;
	cout << endl;
	cout << "Type select to take this course." << endl; 
	cout << "Type back to go back." << endl;
}

void StudentView::select (string course_id) {
	string teacher_id = course_manager.get(course_id, "teacher");
	student_course_manager.add(user_id, course_id);
	user_manager.set(teacher_id, "courses/" + course_id + "/" + user_id, "");
}

void StudentView::exit () {
    // simply do nothing to release control
}
