#ifndef JW_TEACHER_VIEW_H
#define JW_TEACHER_VIEW_H

#include <iostream>
#include <vector>
#include "../lib.hpp"
#include "../session.hpp"
#include "base.hpp"
#include "../models/student_course_manager.hpp"

class TeacherView: public BaseView {

private:
	StudentCourseManager student_course_manager;

public:
	virtual void help();
	virtual void dispatch(std::string cmd);
	void get_courses();
	void get_course(std::string course_id);
	void give_score(std::string user_id);
	void exit();
};
#endif
