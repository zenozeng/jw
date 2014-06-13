#include "student_view.hpp"

using namespace std;

StudentView::StudentView () {
}

void StudentView::init (string id) {
	this->id = id;
	cout << "Welcome, " << this->id << endl;
    this->help();

	string command;
	cout << "> ";
	cin >> command;
	while (command != "exit") {
		route(command);
		cout << "> ";
		cin >> command;
	}
}

void StudentView::help () {
	cout << "Type following commands for further step:" << endl;
	cout << "	help: get help" << endl;
	cout << "	courses: get courses for this term" << endl; 
	cout << "	exit: logout and exit" << endl;
}

void StudentView::route (string command) {
	if (command == "back" && this->status.size() > 0) {
		this->status.pop_back();
		return this->route(this->status[this->status.size() - 1]);
	}
	if (command == "exit") {
		return this->exit();
	}

	int length = this->status.size() - 1;
	string status;
	if (length >= 0) {
		status = this->status[this->status.size() - 1];
	}
	if (status == "courses") {
		return this->get_course(command);
	}

	this->status.push_back(command);
	if (command == "help") {
        return this->help();
    }
	if (command == "courses") {
        return this->get_courses();
    }
	cout << "Command not found." << endl;
	help();
}

void StudentView::get_courses () {
	string course, teacher;
	string course_id_str = this->course_manager.get("/");
	vector<string> courses = split(course_id_str, '\n');

	cout << "id	name	teacher" << endl;
	for (int i = 0, length = courses.size(); i < length; i++) {
		course = this->course_manager.get(courses[i], "name");
		teacher = this->course_manager.get(courses[i], "teacher");
		cout << courses[i] << "	" << course << "	" << teacher << endl;
	}
	cout << endl;
	cout << "Type course id to see more information." << endl;
}

void StudentView::get_course (string course_id) {

	string name = this->course_manager.get(course_id, "name");
	string teacher_id = this->course_manager.get(course_id, "teacher");
	string teacher_name = this->user_manager.get(teacher_id, "name");
	string semester = this->course_manager.get(course_id, "semester");
	string time = this->course_manager.get(course_id, "time");
	string location = this->course_manager.get(course_id, "location");

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
	this->status.push_back("select");

	string teacher_id = this->course_manager.get(course_id, "teacher");
	this->student_course_manager.add(this->id, course_id);
	this->user_manager.set(teacher_id, "courses/" + course_id + "/" + this->id, "");
}

void StudentView::exit () {
    // simply do nothing to release control
}
