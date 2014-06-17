#ifndef JW_LIB_H
#define JW_LIB_H

#include <string>
#include <fstream>
#include <iostream>
#include <streambuf>
#include "hashlibpp/hashlibpp.h"
#include "dirent.h"
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <sys/types.h>
#include <sys/stat.h>

#ifdef _WIN32
#include <direct.h>
#include <io.h>
#endif

#ifndef _WIN32
#include <stdarg.h>
#include <unistd.h>
#endif

#ifdef _WIN32
#define ACCESS _access
#define MKDIR(a) _mkdir((a))
#endif

#ifndef _WIN32
#define ACCESS access
#define MKDIR(a) mkdir((a),0755)
#endif

#ifdef _WIN32
#define IN_WIN true
#endif

#ifndef _WIN32
#define IN_WIN false
#endif

bool pathExists(std::string path);
bool is_valid_username(std::string str);
std::string md5(std::string str);
std::string file_get_contents(std::string filename);
std::string ls(std::string dir);
void file_put_contents(std::string filename, std::string contents);
void rm_r(std::string path);
void mkpath(std::string path);
std::vector<std::string> split(const std::string &s, char delim);

#endif
