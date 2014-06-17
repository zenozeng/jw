#include "main.hpp"

using namespace std;

int main() {
    string cmd;

    cout << "Welcome to JW REPL!" << endl << endl;
    cout << "Copyright (C) 2014 Zeno Zeng & Trevor Sun. " << endl;
    cout << "Licensed under AGPL. See LICENSE for detail." << endl;
    cout << endl;


    // Create Session Instance
    Session session;

    cout << "Default IDs:" << endl;
    cout << "    Admin: 10086, 123456" << endl;
    cout << "    Teacher: 210345, 123456" << endl;
    cout << "    Student: 3120100890, 123456" << endl;

    // Login
    session.login();

    // Prepare views
    AdminView admin_view;
    TeacherView teacher_view;
    StudentView student_view;

    // Display View based on user group
    if (session.group == "admin") {
        admin_view.init(session.id);
    }
    else if (session.group == "teacher") {
        teacher_view.init(session.id);
    }
    else if (session.group == "student") {
        student_view.init(session.id);
    }
    
    return 0;
}
