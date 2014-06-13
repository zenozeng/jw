#include "teacher.hpp"

using namespace std;


void TeacherView::help () {
	cout << "Type following commands for further step:" << endl;
	cout << "	help: get help" << endl;
	cout << "	courses: get courses under your taught" << endl; 
	cout << "	exit: logout and exit" << endl;
}

void TeacherView::dispatch (string cmd) {
	if (cmd == "help") {
		return this->help();
	}
	if (cmd == "courses") {
		return this->get_courses();
	}
	if (cmd == "exit") {
		return this->exit();
	}
	cout << "Command not found." << endl;
	help();
}

void TeacherView::get_courses () {
	vector<string> courses_id = split(user_manager.get(user_id, "courses/"), '\n');
	string course;
	for (int i = 0, length = courses_id.size(); i < length; i++) {
		course = course_manager.get(courses_id[i], "name");
		cout << courses_id[i] << "	" << course << endl;
	}
	cout << "Type the id of course to see more information." << endl;
}

void TeacherView::get_course (string course_id) {
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

	vector<string> students = split(this->user_manager.get(user_id, "courses/" + course_id), '\n');
	string student_name, student_score;
	cout << "Students:" << endl;
	cout << "ID	Name Score" << endl;
	for (int i = 0, length = students.size(); i < length; i++) {
		student_name = this->user_manager.get(students[i], "name");
		student_score = this->user_manager.get(students[i], "score/" + course_id);
		
		cout << students[i] << "	" << student_name << "	" << student_score << endl;
	}
	cout << endl;
	cout << "Type the id of studnet to give score. Press Esc to go back." << endl;
}

void TeacherView::give_score (string user_id) {
}

void TeacherView::exit () {
}
