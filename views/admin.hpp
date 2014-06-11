#ifndef JW_ADMIN_VIEW_H
#define JW_ADMIN_VIEW_H

#include <iostream>
#include <vector>
#include "../lib.hpp"
#include "../session.hpp"
#include "../models/user_manager.hpp"
#include "../models/course_manager.hpp"

class AdminView {

private:
    UserManager user_manager;
    CourseManager course_manager;
    std::string status;

public:
    std::string id;
    std::string name;
    AdminView(void);
    void init(std::string id);
    void help();
    void route(std::string cmd);
    void get_courses();
    void get_course(std::string id);
    void exit();
};
#endif
