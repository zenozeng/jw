#ifndef JW_STUDENT_COURSE_MANAGER_H
#define JW_STUDENT_COURSE_MANAGER_H

#include <iostream>
#include <cstdlib>
#include "../lib.hpp"
#include "../database.hpp"

class StudentCourseManager {

private:
	Database db;

public:
	StudentCourseManager(void);
	std::string list(std::string user_id);
	void add(std::string user_id, std::string course_id);
	void set(std::string user_id, std::string course_id, std::string key, std::string value);
	std::string get(std::string user_id, std::string course_id, std::string key);
	std::string get(std::string user_id, std::string path);
	void remove(std::string user_id, std::string course_id);
};

#endif
