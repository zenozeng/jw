#include "lib.hpp"

bool fexists(const std::string filename) {
    return fexists(filename.c_str());
}

bool fexists(const char *filename) {
    std::ifstream ifile(filename);
    return ifile;
}
