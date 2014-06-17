#include "session.hpp"

using namespace std;

/**
 * Constructor that generate a session instance
 *
 */
Session::Session() {
    this->group = "";
    this->id = "";
}

/**
 * Login
 *
 */
void Session::login() {
    string id, password;
    UserManager user_manager;
    cout << "ID: ";
    cin >> id;
    // make sure username is valid
    if(is_valid_username(id)) {
        // make sure user exists
        if(user_manager.exists(id)) {
            cout << "Password: ";
            cin >> password;
            // check if md5 matches
            string hash = md5(password);
            string hash_in_db = user_manager.get(id, "password");
            cout << "Hash: " << hash << endl;
            if( hash == hash_in_db ) {
                cout << "Hash Match!" << endl;
                cout << "Login success!" << endl;
                string group = user_manager.get(id, "group");
                cout << "ID: " << id << endl;
                cout << "Group: " << group << endl;
                // update user's info
                this->id = id;
                this->group = group;
                return;
            } else {
                cout << "Hash not Match!" << endl;
            }
        } else {
            cout << "User not exists!" << endl;
        }
    } else {
            cout << "Invalid username!" << endl;
    }
    this->login();
}

/**
 * Logout
 *
 */
void Session::logout() {
    this->id = "";
    this->group = "";
    cout << "Logout success!" << endl;
}
