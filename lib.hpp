#ifndef JW_LIB_H
#define JW_LIB_H

#include <fstream>

bool fexists(std::string filename);
bool fexists(const char *filename);
bool is_valid_username(std::string str);

#endif
