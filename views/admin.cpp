#include "admin.hpp"

using namespace std;

AdminView::AdminView () {}

void AdminView::init (string id) {
    this->id = id;
    cout << "Welcome, " << this->id << endl;
    this->help();
    string cmd;
    for(cout << "> " && cin >> cmd; cmd != "exit"; cout << "> ") {
        cin >> cmd;
        route(cmd);
    }
}

void AdminView::help () {
    cout << "Type following commands for further step:" << endl;
    cout << "	help: get help" << endl;
    cout << "	courses: list all courses" << endl;
    cout << "	users: list all users" << endl;
    cout << "	exit: logout and exit" << endl;
}

void AdminView::route (string cmd) {
    
}
