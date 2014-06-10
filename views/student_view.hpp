#ifndef JW_STUDENT_VIEW_H
#define JW_STUDENT_VIEW_H

#include <iostream>
#include <vector>
#include "../lib.hpp"
#include "../session.hpp"
#include "../models/user_manager.hpp"
#include "../models/course_manager.hpp"

class StudentView {

private:
	UserManager user_manager;
	CourseManager course_manager;
	std::string status;

public:
	std::string id;
	std::string name;
	StudentView(void);
	void init(std::string user_id);
	void help();
	void route(std::string command);
	void get_courses();
	void get_course(std::string course_id);
	void exit();
};
#endif
