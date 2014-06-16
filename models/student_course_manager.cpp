#include "student_course_manager.hpp"

using namespace std;

StudentCourseManager::StudentCourseManager () {
}

string StudentCourseManager::list (string user_id) {
	return this->db.get("users/" + user_id + "/courses/");
}

void StudentCourseManager::add (string user_id, string course_id) {
	this->db.set("users/" + user_id + "/courses/" + course_id + "/score", "");
}

void StudentCourseManager::set (string user_id, string course_id, string key, string value) {
	this->db.set("users/" + user_id + "/courses/" + course_id + "/" + key, value);
}

string StudentCourseManager::get (string user_id, string course_id, string key) {
	return this->db.get("users/" + user_id + "/courses/" + course_id + "/" + key);
}

string StudentCourseManager::get (string user_id, string path) {
	return this->db.get("users/" + user_id + "/" + path);
}

void StudentCourseManager::remove (string user_id, string course_id) {
   this->db.remove("users/" + user_id + "/courses/" + course_id + "/");
}   
