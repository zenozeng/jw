#include "base.hpp"

using namespace std;

BaseView::BaseView () {}

BaseView::~BaseView () {}

void BaseView::init (string user_id) {
    string cmd;

    // set user info
    this->user_id = user_id;
    this->user_name = user_manager.get(user_id, "name");

    // display welcome text
    this->welcome();

    // start repl
    do {
        cout << "JW> ";
        cin >> cmd;
        dispatch(cmd);
    } while ( cmd != "exit" );
}

void BaseView::welcome () {
    cout << "Welcome, " << this->user_name << "!" << endl;
}

void BaseView::display_courses () {
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
    cout << "Type course for futher information." << endl;
}

void BaseView::display_course () {
    string course_id;
    cout << "Course ID: ";
    cin >> course_id;
    cout << "ID:	" << course_id << endl;
    cout << "Name:	" << course_manager.get(course_id, "name") << endl;
    cout << "Teacher:	" << course_manager.get(course_id, "teacher") << endl;
}
