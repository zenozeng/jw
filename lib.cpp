#include "lib.hpp"

bool fexists(const std::string filename) {
    return fexists(filename.c_str());
}

bool fexists(const char *filename) {
    std::ifstream ifile(filename);
    return ifile;
}

bool is_valid_username(const std::string str) {
    char ch;
    for (int i = 0; i < str.size(); ++i) {
        ch = str[i];
        if (!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))) {
                return false;
        }
    }
    return true;
}
