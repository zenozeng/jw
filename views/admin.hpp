#ifndef JW_ADMIN_VIEW_H
#define JW_ADMIN_VIEW_H

#include "base.hpp"
#include "../models/student_course_manager.hpp"

class AdminView :public BaseView{

private:
    StudentCourseManager student_course_manager;

public:
    void help();
    void dispatch(std::string cmd);
    void display_users();
    void edit_user();
    void edit_course();
    void remove_user();
    void remove_course();
    void display_student_courses();
    void add_student_course();
    void remove_student_course();
    void set_student_course_score();
    void get_student_course_score();
};
#endif
