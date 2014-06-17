#include "database.hpp"

using namespace std;

/**
 * Filter key string, only allow [0-9A-Za-z/\._-,]
 *
 */
string Database::parse_key(string key) {
    string buf;
    char ch;
    // filter key string
    for(int i = 0; i < key.size(); i++) {
        ch = key[i];
        if( ( ch >= '0' && ch <= '9' ) ||
            ( ch >= 'a' && ch <= 'z' ) ||
            ( ch >= 'A' && ch <= 'Z' ) ||
            ( ch == '/' ) ||
            ( ch == '.' ) ||
            ( ch == '_' ) ||
            ( ch == '-' ) ||
            ( ch == ',' ) ) {
            buf += ch;
        }
    }
    return "db/" + buf;
}

/**
 * Simple KVDB's set method, like js's localStorage.setItem
 *
 */
void Database::set(string key, string value) {
    key = parse_key(key);
    mkpath(key);
    file_put_contents(key, value);
}

/**
 * Simple KVDB's get method, like js's localStorage.getItem
 *
 * @example: get courses 001's detail (note the slash at the end)
 *     db.get("courses/001/");
 *
 * @example: get courses 001's name
 *     db.get("courses/001/name")
 */
string Database::get(string key) {
    key = parse_key(key);

    if( pathExists(key) ) {
        if ( key.at( key.length() - 1 ) == '/' ) {
            // this is object, list all keys, and join them
            return ls(key);
        } else {
            // this is simple key value pair, return value
            return file_get_contents(key);
        }
    } else {
        return "";
    }
}

/**
 * Simple KVDB's remove method, like js's localStorage.removeItem
 *
 * @example: remove courses 001 (note the slash at the end)
 *     db.remove("courses/001/");
 */
void Database::remove(string key) {
    key = parse_key(key);

    if( pathExists(key) ) {
        if ( key.at( key.length() - 1 ) == '/' ) {
            // this is a dir
            rm_r(key);
        } else {
            // this is a file
            remove(key.c_str());
        }
    }
}
