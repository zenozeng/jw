#include "database.hpp"

using namespace std;

// 我们认为空与不存在是一致的

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

void Database::set(string key, string value) {
    key = parse_key(key);
    mkpath(key);
    file_put_contents(key, value);
}

// 读一个　object 后面有斜杠，读简单ｋｅｙ　ｖａｌｕｅ后面无斜杠
// db.get("courses/") => "001\n002\n003\n" => all keys in courses
// db.get("courses/001/") => "name\nteacher\n..."
// db.get("courses/001/name") => "微积分"

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
