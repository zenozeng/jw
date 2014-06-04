#ifndef JW_SESSION_H
#define JW_SESSION_H

class Session {

public:
    Session(void);
    std::string username;
    std::string password;
    std::string group;
    void login();
    void logout();
};

#endif
