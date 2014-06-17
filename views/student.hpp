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
	void select();								// select courses
};

#endif
