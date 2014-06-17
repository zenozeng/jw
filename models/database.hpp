#ifndef JW_DATABASE_H
#define JW_DATABASE_H

#include "../lib/lib.hpp"

class Database {

public:
    void set(std::string key, std::string value);
    std::string get(std::string key);
    void remove(std::string key);
};

#endif
