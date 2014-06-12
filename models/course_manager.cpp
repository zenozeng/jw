#include "course_manager.hpp"

using namespace std;

CourseManager::CourseManager() {}

void CourseManager::add(string id, string name, string teacher, string semester, string time, string location) {
    this->db.set("courses/"+id+"/name", name);
    this->db.set("courses/"+id+"/teacher", teacher);
    this->db.set("courses/"+id+"/semester", semester);
    this->db.set("courses/"+id+"/time", time);
    this->db.set("courses/"+id+"/location", location);
}

string CourseManager::get(string id, string key) {
    return this->db.get("courses/"+id+"/"+key);
}

string CourseManager::get(string path) {
    return this->db.get("courses/" + path);
}

string CourseManager::list() {
    return this->db.get("courses/");
}

void CourseManager::set(string id, string key, string value) {
    this->db.set("courses/"+id+"/"+key, value);
}

void CourseManager::remove(string id) {
    this->db.remove("courses/"+id+"/");
}
