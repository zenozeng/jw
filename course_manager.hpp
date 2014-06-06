#ifndef JW_COURSE_MANAGER_H
#define JW_COURSE_MANAGER_H

#include <iostream>
#include <cstdlib>
#include "lib.hpp"

class CourseManager {

public:
    CourseManager(void);

    void add(std::string id,
             std::string name,
             std::string teacher,
             std::string semester,
             std::string time,
             std::string location);

    void get(std::string id, std::string key);

    void set(std::string id, std::string key, std::string value);

    void remove(std::string id);
};

#endif
