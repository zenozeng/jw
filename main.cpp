#include "main.hpp"
using namespace std;

int main() {
    string cmd;
    cout << "Welcome to JW Shell!" << endl << endl;
    cout << "Copyright (C) 2014 Zeno Zeng & Trevor Sun. " << endl;
    cout << "Licensed under AGPL. See LICENSE for detail." << endl;
    // start REPL
    while (true) {
        cout << "REPL> ";
        cin >> cmd;
        cout << "Dispatch CMD: " << cmd << endl;
    };
    return 0;
}
