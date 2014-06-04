#include "session.hpp"

using namespace std;

/**
 * Constructor that generate a session instance
 *
 */
Session::Session() {
    this->username = "";
    this->group = "";
}

/**
 * Login
 *
 */
void Session::login() {
    string username, password;
    cout << "Username: ";
    cin >> username;
    // cin 保证了不为空，所以这里就不进行　username 的长度检查了
    if(is_valid_username(username)) {
        if(fexists("db/users/"+username)) {
            cout << "Password: ";
            cin >> password;
            string hash = md5(password);
            string hash_in_db = file_get_contents("db/users/"+username+"/password");
            cout << "Hash: " << hash << endl;
            if( hash == hash_in_db ) {
                cout << "Hash Match!" << endl;
                cout << "Login success!" << endl;
                string group = file_get_contents("db/users/"+username+"/group");
                cout << "Username: " << username << endl;
                cout << "Group: " << group << endl;
                this->username = username;
                this->group = group;
            } else {
                cout << "Hash not Match!" << endl;
            }
        } else {
            cout << "User not exists!" << endl;
        }
    } else {
            cout << "Invalid username!" << endl;
    }
}
