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
}

void BaseView::display_course () {
	string course_id;
    cout << "Course ID: ";
    getline(cin, course_id);
    cout << "ID:	" << course_id << endl;
    cout << "Name:	" << course_manager.get(course_id, "name") << endl;
    cout << "Teacher:	" << course_manager.get(course_id, "teacher") << endl;
    cout << "Semester:	" << course_manager.get(course_id, "semester") << endl;
    cout << "Time:	" << course_manager.get(course_id, "time") << endl;
    cout << "Location:	" << course_manager.get(course_id, "location") << endl;
}
