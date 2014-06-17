#ifndef JW_SESSION_H
#define JW_SESSION_H

#include <iostream>
#include <cstdlib>
#include "lib/lib.hpp"
#include "models/user_manager.hpp"

class Session {

public:
    Session(void);
    std::string id;
    std::string group;
    void login();
    void logout();
};

#endif
