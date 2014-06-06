#include "../lib.hpp"
#include <iostream>

using namespace std;

int main() {
    cout << "Test begin!" << endl;
    // cout << "file_put_contents" << endl;
    // file_put_contents("tmp", "Hello World");
    cout << "ls(\"db\")" << endl;
    cout << ls("db") << endl;
    // cout << "rm_r(\"tmp\")" << endl;
    // rm_r("tmp/");
    cout << "mkpath" << endl;
    mkpath("a/b/c/d/e/xxx");
    return 0;
}
