#ifndef JW_TEACHER_VIEW_H
#define JW_TEACHER_VIEW_H

#include <iostream>
#include <vector>
#include "../lib.hpp"
#include "../session.hpp"
#include "../models/user_manager.hpp"
#include "../models/course_manager.hpp"
#include "../models/student_course_manager.hpp"

class TeacherView {

private:
	UserManager user_manager;
	CourseManager course_manager;
	StudentCourseManager student_course_manager;
	std::vector<std::string> status;

public:
	std::string id;
	std::string name;
	
	TeacherView(void);
	void init(std::string user_id);
	void help();
	void route(std::string command);
	void get_courses();
	void get_course(std::string course_id);
	void give_score(std::string user_id);
	void exit();
};
#endif
