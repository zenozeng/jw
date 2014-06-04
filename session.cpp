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
    std::string username, password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
}
