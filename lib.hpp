#ifndef JW_LIB_H
#define JW_LIB_H

#include <string>
#include <fstream>
#include <streambuf>
#include "hashlibpp/hashlibpp.h"

bool fexists(std::string filename);
bool fexists(const char *filename);
bool is_valid_username(std::string str);
std::string md5(std::string str);
std::string file_get_contents(std::string filename);

#endif
