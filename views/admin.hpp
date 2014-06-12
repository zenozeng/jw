#ifndef JW_ADMIN_VIEW_H
#define JW_ADMIN_VIEW_H

#include "base.hpp"

class AdminView :public BaseView{

public:
    void help();
    void dispatch(std::string cmd);
};
#endif
