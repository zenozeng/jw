#include "admin.hpp"

using namespace std;

/**
 * Display help info
 *
 */
void AdminView::help () {
    cout << "Type following commands for further step:" << endl;
    // common
    cout << "	Common Commands:" << endl;
    cout << "		exit: logout" << endl;
    cout << "		help: get help" << endl;
    // course
    cout << "	Course Manager:" << endl;
    cout << "		courses: list all courses" << endl;
    cout << "		course: show detail of course" << endl;
    cout << "		edit course: edit course" << endl;
    cout << "		add course: add course" << endl;
    cout << "		remove course: remove course" << endl;
    // user
    cout << "	User Manager:" << endl;
    cout << "		users: list all users" << endl;
    cout << "		edit user: edit user" << endl;
    cout << "		add user: add user" << endl;
    cout << "		remove user: remove user" << endl;
    // student course
    cout << "	Student Course Manager:" << endl;
    cout << "		courses of student: list all courses of a student" << endl;
    cout << "		add course for student: add course for student" << endl;
    cout << "		remove course of student: remove course of student" << endl;
    cout << "		get course score of student: get course score of student" << endl;
    cout << "		set course score of student: set course score of student" << endl;
}

/**
 * Dispatch command
 *
 */
void AdminView::dispatch (string cmd) {
    if ( cmd == "" ) {
        return;
    } else if ( cmd == "help" ) {
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
    } else if ( cmd == "add course of student" ) {
        this->add_student_course();
    } else if ( cmd == "remove course of student" ) {
        this->remove_student_course();
    } else if ( cmd == "set course score of student" ) {
        this->set_student_course_score();
    } else if ( cmd == "get course score of student" ) {
        this->get_student_course_score();
    } else {
        cout << "Command not Found." << endl;
    }
}

/**
 * Display all users
 *
 */
void AdminView::display_users () {
    string id, name, group;
    vector<string> users = split(this->user_manager.get("/"), '\n');

    cout << "id name group" << endl;
    for (int i = 0, len = users.size(); i < len; i++) {
        id = users[i];
        name = this->user_manager.get(id, "name");
        group = this->user_manager.get(id, "group");
        cout << id << " " << name << " " << group << " " << endl;
    }
}

/**
 * Edit user
 *
 */
void AdminView::edit_user () {
    string id, name, group, password;
    cout << "ID: ";
    getline(cin, id);
    cout << "Name: ";
    getline(cin, name);
    cout << "Group: ";
    getline(cin, group);
    cout << "Password: ";
    getline(cin, password);
    this->user_manager.set(id, "name", name);
    this->user_manager.set(id, "group", group);
    this->user_manager.set(id, "password", password);
}

/**
 * Remove user
 *
 */
void AdminView::remove_user () {
    string id;
    cout << "ID: ";
    getline(cin, id);
    this->user_manager.remove(id);
}

/**
 * Edit course
 *
 */
void AdminView::edit_course () {
    string id, name, teacher, semester, time, location;
    cout << "ID: ";
    getline(cin, id);
    cout << "Name: ";
    getline(cin, name);
    cout << "Teacher: ";
    getline(cin, teacher);
    cout << "Semester: ";
    getline(cin, semester);
    cout << "Time: ";
    getline(cin, time);
    cout << "Location: ";
    getline(cin, location);
    this->course_manager.set(id, "name", name);
    this->course_manager.set(id, "teacher", teacher);
    this->course_manager.set(id, "semester", semester);
    this->course_manager.set(id, "time", time);
    this->course_manager.set(id, "location", location);
}

/**
 * Remove course
 *
 */
void AdminView::remove_course () {
    string id;
    cout << "ID: ";
    getline(cin, id);
    this->course_manager.remove(id);
}

/**
 * Display all courses of a student
 *
 */
void AdminView::display_student_courses () {
    string user_id, courses;
    cout << "User ID: ";
    getline(cin, user_id);
    courses = this->student_course_manager.list(user_id);
    if ( courses.size() == 0 ) {
        cout << "No courses found" << endl;
    } else {
        cout << this->student_course_manager.list(user_id);
    }
}

/**
 * Add a course to a student
 *
 */
void AdminView::add_student_course () {
    string user_id, course_id;
    cout << "User ID: ";
    getline(cin, user_id);
    cout << "Course ID: ";
    getline(cin, course_id);
    this->student_course_manager.add(user_id, course_id);
}

/**
 * Remove a course of a student
 *
 */
void AdminView::remove_student_course () {
    string user_id, course_id;
    cout << "User ID: ";
    getline(cin, user_id);
    cout << "Course ID: ";
    getline(cin, course_id);
    this->student_course_manager.remove(user_id, course_id);
}

/**
 * Set course score of a student
 *
 */
void AdminView::set_student_course_score () {
    string user_id, course_id, score;
    cout << "User ID: ";
    getline(cin, user_id);
    cout << "Course ID: ";
    getline(cin, course_id);
    cout << "Score: ";
    getline(cin, score);
    this->student_course_manager.set(user_id, course_id, "score", score);
}

/**
 * Get course score of a student
 *
 */
void AdminView::get_student_course_score () {
    string user_id, course_id, score;
    cout << "User ID: ";
    getline(cin, user_id);
    cout << "Course ID: ";
    getline(cin, course_id);
    cout << this->student_course_manager.get(user_id, course_id, "score") << endl;
}
