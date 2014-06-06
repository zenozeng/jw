#include "lib.hpp"

class Database {

public:
    void set(std::string key, std::string value);
    void get(std::string key);
    void remove(std::string key);
}
