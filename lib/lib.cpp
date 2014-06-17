#include "lib.hpp"
#include <sstream>

using namespace std;


/**
 * Check if file/dir exists
 *
 */
bool pathExists(const std::string path) {
    struct stat info;
	if (IN_WIN && path[path.size() - 1] == '/') {
		return (stat(path.substr(0, path.size() - 1).c_str(), &info) == 0);
	} else {
	   return (stat(path.c_str(), &info) == 0);
	}
}

/**
 * Check if the username is valid
 *
 */
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

/**
 * Get the contents of the given file (like php's file_get_contents)
 *
 */
std::string file_get_contents(const std::string filename) {
    std::ifstream t(filename.c_str());
    std::string str((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());
    return str;
}

/**
 * Remove directory and its contents recursively (like shell's rm -r)
 *
 */
void rm_r(std::string path) {
    std::string dir_path = (path.at( path.length() - 1 ) == '/') ? path : path + "/";

    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir (dir_path.c_str())) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            std::string filename(ent->d_name);
            if(!(filename == "." || filename == "..")) {
                std::string filepath = dir_path + filename;
                struct stat info;
                stat(filepath.c_str(), &info);
                if ( info.st_mode & S_IFDIR ) {
                    // is dir
                    rm_r(filepath);
                } else {
                    // is file
                    remove(filepath.c_str());
                }
            }
        }
        closedir (dir);
        rmdir(path.c_str());
    }
}

/**
 * List directory contents, '\n' as separator (like shell's ls)
 *
 */
std::string ls(const std::string path) {
    std::string files = "";
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (path.c_str())) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            std::string filename(ent->d_name);
            if(!(filename == "." || filename == "..")) {
                files  = files + filename + "\n";
            }
        }
        closedir (dir);
        return files;
    } else {
        // could not open dir
        return "";
    }
}

/**
 * Writes a string to a file (like php's file_put_contents)
 *
 */
void file_put_contents(const std::string filename, const std::string contents) {
    std::ofstream outfile (filename.c_str());
    outfile << contents;
    outfile.close();
}

/**
 * Calc the md5 hash of a string
 *
 */
std::string md5(std::string str) {
    hashwrapper *myWrapper = new md5wrapper();
    return myWrapper->getHashFromString(str);
}

/**
 * Make directory, and make parent directories as needed (like shell's mkdir -p)
 *
 */
void mkpath(std::string path) {
    std::string current_path = "";
    for(int i = 0; i < path.size(); i++) {
        current_path += path[i];
        if (path[i] == '/') {
            MKDIR(current_path.c_str());
        }
    }
}

void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}
