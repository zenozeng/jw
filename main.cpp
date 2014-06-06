#include "main.hpp"

using namespace std;

void help() {
    // session view
    cout << "Commands:" << endl;
    cout << "    help, login, logout, change password" << endl;
    // teacher view
    cout << "Commands for Teachers:" << endl;
    cout << "    TODO" << endl;
    // Admin view
    cout << "Commands for Admin:" << endl;
    cout << "    user/create, user/info, user/update, user/delete" << endl;
    cout << "    course/create, course/info, course/update, course/delete" << endl;
}

int main() {
    string cmd;

    cout << "Welcome to JW REPL!" << endl << endl;
    cout << "Copyright (C) 2014 Zeno Zeng & Trevor Sun. " << endl;
    cout << "Licensed under AGPL. See LICENSE for detail." << endl;
    cout << endl;


    // Create Session Instance
    Session session;

    cout << "Default ID & password: admin, 123456. " << endl;

    session.login();
    help()

    // Start REPL
    while (true) {
        cout << "JW REPL> ";
        cin >> cmd;

        if (cmd == "help") {
            help();
        }

        if (cmd == "login") {
            session.login();
        }

        if (cmd == "logout") {
            session.logout();
        }
    };

    return 0;
}
