#ifndef JW_STUDENT_VIEW_H
#define JW_STUDENT_VIEW_H

#include "base.hpp"
#include "../models/student_course_manager.hpp"

class StudentView: public BaseView{

private:
	StudentCourseManager student_course_manager;

public:
	virtual void help();
	virtual void dispatch(std::string cmd);
	void get_courses();
	void get_course(std::string course_id);
	void select();
	void exit();
};

#endif
