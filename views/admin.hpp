#ifndef JW_ADMIN_VIEW_H
#define JW_ADMIN_VIEW_H

#include "base.hpp"

class AdminView :public BaseView{

public:
    void help();
    void dispatch(std::string cmd);
    void display_users();
    void edit_user();
    void edit_course();
    void remove_user();
    void remove_course();
};
#endif
