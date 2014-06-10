#include "main.hpp"

using namespace std;

// void help() {
//     // session view
//     cout << "Commands:" << endl;
//     cout << "    help, login, logout, change password" << endl;
//     // teacher view
//     cout << "Commands for Teachers:" << endl;
//     cout << "    TODO" << endl;
//     // Admin view
//     cout << "Commands for Admin:" << endl;
//     cout << "    user/create, user/info, user/update, user/delete" << endl;
//     cout << "    course/create, course/info, course/update, course/delete" << endl;
// }

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

    session.login();

    // Prepare views
    StudentView student_view;

    if (session.group == "administrator") {
    }
    else if (session.group == "teacher") {
    }
    else if (session.group == "student") {
        student_view.init(session.id);
    }
    

    // // Start REPL
    // while (true) {
    //     cout << "JW REPL> ";
    //     cin >> cmd;

    //     if (cmd == "help") {
    //         help();
    //     }

    //     if (cmd == "login") {
    //         session.login();
    //     }

    //     if (cmd == "logout") {
    //         session.logout();
    //     }
    // };

    return 0;
}
