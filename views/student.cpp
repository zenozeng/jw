#include "student_view.hpp"

using namespace std;

/**
  * 输出帮助信息
  */
void StudentView::help () {
	cout << "Type following commands for further step:" << endl;
	cout << "	help: get help" << endl;
	cout << "	courses: display courses for this term" << endl; 
	cout << "	course: display detail of the course" << endl;
	cout << "	select: select courses" << endl;
	cout << "	exit: logout and exit" << endl;
}

/**
  * 对输入的命令进行路由
  */
void StudentView::dispatch (string cmd) {
	if (cmd == "help") {
        return this->help();
    }
	if (cmd == "course") {
		return this->display_course();
	}
	if (cmd == "courses") {
        return this->display_courses();
    }
	if (cmd == "select") {
		return this->select();
	}
	cout << "Command not found." << endl;
	help();
}

/**
  * 选课
  */
void StudentView::select () {
	string course_id;
	string teacher_id;

	// 接受循环输入
	while (1) {
		cout << "Type the id of course to select it." << endl;
		cout << "Type `quit` to quit." << endl;
		cout << "JW>Select ";
		getline(cin, course_id);
		// 输入 "quit" 时退出
		if (course_id == "quit") {
			return;
		}
		if (course_manager.get(course_id + "/") == "") {
			cout << "No such course." << endl;
			continue;
		}
		teacher_id = course_manager.get(course_id, "teacher");
		student_course_manager.add(user_id, course_id);
		user_manager.set(teacher_id, "courses/" + course_id + "/" + user_id, "");
		cout << "Select successfully!" << endl;
	}
}

