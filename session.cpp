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
    if(username.length() > 0 && fexists("db/users/"+username)) {
        cout << "Password: ";
        cin >> password;
    } else {
        cout << "User not exists!" << endl;
    }
}
