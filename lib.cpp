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

std::string file_get_contents(const std::string filename) {
    std::ifstream t(filename.c_str());
    std::string str((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());
    return str;
}

std::string md5(std::string str) {
    hashwrapper *myWrapper = new md5wrapper();
    return myWrapper->getHashFromString(str);
}
