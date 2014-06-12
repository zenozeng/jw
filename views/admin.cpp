#include "admin.hpp"

using namespace std;

void AdminView::help () {
    cout << "Type following commands for further step:" << endl;
    cout << "	help: get help" << endl;
    cout << "	courses: list all courses" << endl;
    cout << "   course: show detail of course" << endl;
    cout << "	users: list all users" << endl;
    cout << "	exit: logout and exit" << endl;
}

void AdminView::dispatch (string cmd) {
    if ( cmd == "courses" ) {
        this->display_courses();
    } else if ( cmd == "course" ) {
        this->display_course();
    }
}

