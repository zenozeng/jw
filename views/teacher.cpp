#include "teacher.hpp"

using namespace std;

/**
  * 输出帮助信息
  */
void TeacherView::help () {
	cout << "Type following commands for further step:" << endl;
	cout << "	help: get help" << endl;
	cout << "	courses: display all courses under your taught" << endl; 
	cout << "	my courses: display all courses under your teaching" << endl;
	cout << "	my course: display the detail of the course usder your teaching" << endl;
	cout << "	score: give score to your student" << endl;
	cout << "	exit: logout and exit" << endl;
}

/**
  * 对输入的命令进行路由
  */
void TeacherView::dispatch (string cmd) {
	if (cmd == "help") {
		return this->help();
	}
	if (cmd == "courses") {
		return this->display_courses();
	}
	if (cmd == "my courses") {
		return this->get_courses();
	}
	if (cmd == "my course") {
		return this->get_course();
	}
	if (cmd == "score") {
		return this->give_score();
	}
	if (cmd == "exit") {
		return this->exit();
	}
	cout << "Command not found." << endl;
	help();
}

/**
  * 显示教师代的所有课
  */
void TeacherView::get_courses () {
	vector<string> courses_id = split(user_manager.get(user_id, "courses/"), '\n');
	string course;
	for (int i = 0, length = courses_id.size(); i < length; i++) {
		course = course_manager.get(courses_id[i], "name");
		cout << courses_id[i] << "	" << course << endl;
	}
}

/**
  * 显示某门课的详细信息及选课情况
  */
void TeacherView::get_course () {
	string course_id, name, teacher_id, teacher_name, semester, time, location;

	// 接受循环输入
	while (1) {
		cout << "Type the id of course to see detail. Type `quit` to quit." << endl;
		cout << "JW>my course> ";
		getline(cin, course_id);
		if (course_id == "quit") {
			return;
		}
		name = this->course_manager.get(course_id, "name");
		if (name == "") {
			cout << "No such course." << endl;
			continue;
		}
		teacher_id = this->course_manager.get(course_id, "teacher");
		teacher_name = this->user_manager.get(teacher_id, "name");
		semester = this->course_manager.get(course_id, "semester");
		time = this->course_manager.get(course_id, "time");
		location = this->course_manager.get(course_id, "location");

		cout << "Name:	" << name << endl;
		cout << "Teacher:	" << teacher_name << endl;
		cout << "Semester:	" << semester << endl;
		cout << "Time:	" << time << endl;
		cout << "Location:	" << location << endl;
		cout << endl;

		// 显示所有选中该门课的学生
		vector<string> students = split(this->user_manager.get(user_id, "courses/" + course_id + "/"), '\n');
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
}

/**
  * 给学生打分
  */
void TeacherView::give_score () {
	string course_id, student_id, score;
	cout << "Type the course id to select course. " << endl;
	cout << "JW>Score> ";
	getline(cin, course_id);

	// 接受循环输入
	while (1) {
		cout << "Type the student id to give score. Type `quit` to quit." << endl;
		cout << "JW>Score ";
		getline(cin, student_id);
		if (student_id == "quit") {
			return;
		}
		cout << "Input thte score:" << endl;
		cout << "JW>Score ";
		getline(cin, score);
		user_manager.set(student_id, "courses/" + course_id + "/score", score);
	}
}

