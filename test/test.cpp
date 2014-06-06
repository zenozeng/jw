#include "../lib.hpp"
#include <iostream>

using namespace std;

int main() {
    cout << "Test begin!" << endl;
    file_put_contents("tmp", "Hello World");
    return 0;
}
