#ifndef JW_COURSE_MANAGER_H
#define JW_COURSE_MANAGER_H

#include <iostream>
#include <cstdlib>
#include "../lib.hpp"
#include "../database.hpp"

class CourseManager {

private:
    Database db;

public:
    CourseManager(void);

    void add(std::string id,
             std::string name,
             std::string teacher,
             std::string semester,
             std::string time,
             std::string location);

    std::string get(std::string id, std::string key);

	std::string get(std::string path);

    void set(std::string id, std::string key, std::string value);

    void remove(std::string id);

    std::string list(void);
};

#endif
