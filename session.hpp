#ifndef JW_SESSION_H
#define JW_SESSION_H

#include "iostream"
#include "lib.hpp"

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
