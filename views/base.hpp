// base view that every other views should inherits

#ifndef JW_BASE_VIEW_H
#define JW_BASE_VIEW_H

#include <iostream>
#include <vector>
#include "../lib/lib.hpp"
#include "../session.hpp"
#include "../models/user_manager.hpp"
#include "../models/course_manager.hpp"

class BaseView {

protected:
    UserManager user_manager;
    CourseManager course_manager;

public:
    std::string user_id;
    std::string user_name;
    BaseView();
    ~BaseView();
    void init(std::string user_id);
    void welcome();
    virtual void help() {};
    virtual void dispatch(std::string cmd) {};
    void display_courses();
    void display_course();
};
#endif
