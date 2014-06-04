#include "session.hpp"

using namespace std;

/**
 * Constructor that generate a session instance
 *
 */
Session::Session() {
    this->username = "";
    this->password = "";
    this->group = -1;
}

/**
 * Login
 *
 */
void Session::login() {
    string username, password;
    cout << "Username: ";
    cin >> username;
    // cin 保证了不为空，所以这里就不进行　username 的长度检查
    if(is_valid_username(username)) {
        if(fexists("db/users/"+username)) {
            cout << "Password: ";
            cin >> password;
        } else {
            cout << "User not exists!" << endl;
        }
    } else {
            cout << "Invalid username!" << endl;
    }
}
