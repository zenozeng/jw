#ifndef JW_TEACHER_VIEW_H
#define JW_TEACHER_VIEW_H

#include "base.hpp"
#include "../models/student_course_manager.hpp"

class TeacherView: public BaseView {

private:
	StudentCourseManager student_course_manager;

public:
	virtual void help();
	virtual void dispatch(std::string cmd);
	void get_courses();						// diaplay all courses under the teacher's teaching
	void get_course();						// display the detail of course under the teacher's teaching
	void give_score();						// give score to students
};
#endif
