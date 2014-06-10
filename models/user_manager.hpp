#ifndef JW_USER_MANAGER_H
#define JW_USER_MANAGER_H

#include <iostream>
#include <cstdlib>
#include "../lib.hpp"
#include "../database.hpp"

class UserManager {

private:
	Database db;

public:
	UserManager(void);
	void add(std::string id, std::string name, std::string password);
	void set(std::string id, std::string key, std::string value);
	std::string get(std::string id, std::string key);
	void remove(std::string id);
	bool exists(std::string id);
};

#endif
