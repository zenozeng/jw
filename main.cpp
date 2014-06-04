#include "main.hpp"

using namespace std;

void help() {
    cout << "Commands: user/login, user/create, user/read, user/update, user/delete" << endl;
}

int main() {
    string cmd;

    cout << "Welcome to JW REPL!" << endl << endl;
    cout << "Copyright (C) 2014 Zeno Zeng & Trevor Sun. " << endl;
    cout << "Licensed under AGPL. See LICENSE for detail." << endl;
    cout << endl;

    // Display usage
    help();

    // Create Session Instance
    Session session;

    // Start REPL
    while (true) {
        cout << "JW REPL> ";
        cin >> cmd;

        if (cmd == "help") {
            help();
        }

        if (cmd == "user/login") {
            session.login();
        }
    };

    return 0;
}
