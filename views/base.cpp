#include "base.hpp"

using namespace std;

BaseView::BaseView () {}

BaseView::~BaseView () {}

/**
 * Init View, start REPL
 *
 */
void BaseView::init (string user_id) {
    string cmd;

    // set user info
    this->user_id = user_id;
    this->user_name = user_manager.get(user_id, "name");

    // display welcome text
    this->welcome();

    // display help info
    this->help();

    // start REPL
    cin.get(); // skip the very first enter
    do {
        cout << "JW> ";
        getline(cin, cmd);
        if( cmd == "exit") {
            break;
        }
        if( cmd.size() == 0 ) {
            continue;
        }
        dispatch(cmd);
    } while (true);
}

/**
 * Display welcome text
 *
 */
void BaseView::welcome () {
    cout << "Welcome, " << this->user_name << "!" << endl;
}

/**
 * Display all courses
 *
 */
void BaseView::display_courses () {
    string course, teacher, teacher_id;
    string course_id_str = this->course_manager.get("/");
    vector<string> courses = split(course_id_str, '\n');

    cout << "id	name	teacher" << endl;
    for (int i = 0, length = courses.size(); i < length; i++) {
        course = this->course_manager.get(courses[i], "name");
        teacher_id = this->course_manager.get(courses[i], "teacher");
        teacher = this->user_manager.get(teacher_id, "name");
        cout << courses[i] << "	" << course << "	" << teacher << endl;
    }
    cout << endl;
}

/**
 * Display the detail of given course
 *
 */
void BaseView::display_course () {
    string course_id, teacher_id;
    cout << "Course ID: ";
    getline(cin, course_id);
    cout << "ID:	" << course_id << endl;
    cout << "Name:	" << course_manager.get(course_id, "name") << endl;
    teacher_id = course_manager.get(course_id, "teacher");
    cout << "Teacher:	" << user_manager.get(teacher_id, "name") << endl;
    cout << "Semester:	" << course_manager.get(course_id, "semester") << endl;
    cout << "Time:	" << course_manager.get(course_id, "time") << endl;
    cout << "Location:	" << course_manager.get(course_id, "location") << endl;
}
