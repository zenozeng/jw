#include "admin.hpp"

using namespace std;

void AdminView::help () {
    cout << "Type following commands for further step:" << endl;
    // common
    cout << "	exit: logout" << endl;
    cout << "	help: get help" << endl;
    // course
    cout << "	courses: list all courses" << endl;
    cout << "	course: show detail of course" << endl;
    cout << "	edit course: edit course" << endl;
    cout << "	add course: add course" << endl;
    cout << "	remove course: remove course" << endl;
    // user
    cout << "	users: list all users" << endl;
    cout << "	edit user: edit user" << endl;
    cout << "	add user: add user" << endl;
    cout << "	remove user: remove user" << endl;
    // student course
    cout << "	courses of student: list all courses of a student" << endl;
    cout << "	add course for student: add course for student" << endl;
    cout << "	remove course for student: remove course for student" << endl;
    cout << "	set course score for student: set course score for student" << endl;
}

void AdminView::dispatch (string cmd) {
    if ( cmd == "help" ) {
        this->help();
    } else if ( cmd == "courses" ) {
        this->display_courses();
    } else if ( cmd == "course" ) {
        this->display_course();
    } else if ( cmd == "users" ) {
        this->display_users();
    } else if ( cmd == "edit user" || cmd == "add user" ) {
        this->edit_user();
    } else if ( cmd == "remove course" ) {
        this->remove_course();
    } else if ( cmd == "remove user" ) {
        this->remove_user();
    } else if ( cmd == "edit course" || cmd == "add course" ) {
        this->edit_course();
    } else if ( cmd == "courses of student" ) {
        this->display_student_courses();
    } else if ( cmd == "add course for student" ) {
        this->add_student_course();
    } else if ( cmd == "remove course for student" ) {
        this->remove_student_course();
    } else if ( cmd == "set course score for student" ) {
        this->set_student_course_score();
    } else {
        cout << "Invalid Command!" << endl;
    }
}

void AdminView::display_users () {
    string id, name, group;
    vector<string> users = split(this->user_manager.get("/"), '\n');

    cout << "id	name	group" << endl;
    for (int i = 0, len = users.size(); i < len; i++) {
        id = users[i];
        name = this->course_manager.get(id, "name");
        group = this->course_manager.get(id, "group");
        cout << id << "	" << name << "	" << group << "	" << endl;
    }
}

void AdminView::edit_user () {
    string id, name, group;
    cout << "ID: ";
    cin >> id;
    cout << "Name: ";
    cin >> name;
    cout << "Group: ";
    cin >> group;
    this->user_manager.set(id, "name", name);
    this->user_manager.set(id, "group", group);
}

void AdminView::remove_user () {
    string id;
    cout << "ID: ";
    cin >> id;
    this->user_manager.remove(id);
}

void AdminView::edit_course () {
    string id, name, teacher;
    cout << "ID: ";
    cin >> id;
    cout << "Name: ";
    cin >> name;
    cout << "Teacher: ";
    cin >> teacher;
    this->course_manager.set(id, "name", name);
    this->course_manager.set(id, "teacher", teacher);
}

void AdminView::remove_course () {
    string id;
    cout << "ID: ";
    cin >> id;
    this->course_manager.remove(id);
}

void AdminView::display_student_courses () {
    string user_id;
    cout << "User ID: ";
    cin >> user_id;
    this->student_course_manager.list(user_id);
}

void AdminView::add_student_course () {
    string user_id, course_id;
    cout << "User ID: ";
    cin >> user_id;
    cout << "Course ID: ";
    cin >> course_id;
    this->student_course_manager.add(user_id, course_id);
}

void AdminView::remove_student_course () {
    string user_id, course_id;
    cout << "User ID: ";
    cin >> user_id;
    cout << "Course ID: ";
    cin >> course_id;
    this->student_course_manager.remove(user_id, course_id);
}

void AdminView::set_student_course_score () {
    string user_id, course_id, score;
    cout << "User ID: ";
    cin >> user_id;
    cout << "Course ID: ";
    cin >> course_id;
    cout << "Score: ";
    cin >> score;
    this->student_course_manager.set(user_id, course_id, "score", score);
}
