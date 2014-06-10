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
    // cin 保证了不为空，所以这里就不进行　username 的长度检查了
    if(is_valid_username(id)) {
        if(user_manager.exists(id)) {
            cout << "Password: ";
            cin >> password;
            string hash = md5(password);
            string hash_in_db = user_manager.get(id, "password");
            cout << "Hash: " << hash << endl;
            if( hash == hash_in_db ) {
                cout << "Hash Match!" << endl;
                cout << "Login success!" << endl;
                string group = user_manager.get(id, "group");
                cout << "ID: " << id << endl;
                cout << "Group: " << group << endl;
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
 * Login
 *
 */
void Session::logout() {
    this->id = "";
    this->group = "";
    cout << "Logout success!" << endl;
}
