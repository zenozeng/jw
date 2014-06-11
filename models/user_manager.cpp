#include "user_manager.hpp"

using namespace std;

UserManager::UserManager () {
}

void UserManager::add (string id, string name, string password) {
	if (this->exists("users/" + id)) return;

	string password_in_md5 = md5(password);

	this->db.set("users/" + id + "/name", name);
	this->db.set("users/" + id + "/password", password_in_md5);
}

void UserManager::set (string id, string key, string value) {
	if (!this->exists("users/" + id)) return;

	if (key == "password") {
		value = md5(value);
	}
	this->db.set("users/" + id + "/" + key, value);
}

string UserManager::get (string id, string key) {
	return this->db.get("users/" + id + "/" + key);
}

string UserManager::get (string path) {
	return this->db.get("users/" + path);
}

void UserManager::remove (string id) {
	this->db.remove("users/" + id);
}

bool UserManager::exists (string id) {
	return (this->db.get("users/" + id + "/") == "") ? false : true;
}
