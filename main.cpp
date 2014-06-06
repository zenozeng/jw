#include "main.hpp"

using namespace std;

void help() {
    cout << "Commands: login, logout, change password" << endl;
    cout << "          user/create, user/info, user/update, user/delete" << endl;
    cout << "          course/create, course/info, course/update, course/delete" << endl;
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
