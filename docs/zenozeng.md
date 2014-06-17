# ZenoZeng

## 完成哪些工作

### 概述

架构设计，Database类，FileSystem相关函数（及相关测试），MD5 Hash函数封装。
BaseView类，AdminView类，CourseManager类，Session类，Main.cpp。

### Commit Log

```
git log --pretty=format:"%h - %an, %ad : %s" | grep "Zeno Zeng"
```

```
768e140 - Zeno Zeng, Tue Jun 17 22:34:52 2014 +0800 : add comments
47b69c2 - Zeno Zeng, Tue Jun 17 22:24:06 2014 +0800 : add comments for Database
391ea44 - Zeno Zeng, Tue Jun 17 22:16:15 2014 +0800 : add comments for lib
557ea1e - Zeno Zeng, Tue Jun 17 22:06:27 2014 +0800 : add comments for main.cpp
bb22d96 - Zeno Zeng, Tue Jun 17 22:03:19 2014 +0800 : Merge branch 'master' of https://github.com/zenozeng/jw
beb4038 - Zeno Zeng, Tue Jun 17 22:03:10 2014 +0800 : add comments for session.cpp
d902b42 - Zeno Zeng, Tue Jun 17 21:56:59 2014 +0800 : add Database::parse_key, only allow [0-9A-Za-z/\._-,], fixes #20
d15a64e - Zeno Zeng, Tue Jun 17 21:01:05 2014 +0800 : reorganize files
9b3409b - Zeno Zeng, Mon Jun 16 22:56:08 2014 +0800 : Merge branch 'master' of https://github.com/zenozeng/jw
a7225e6 - Zeno Zeng, Mon Jun 16 22:55:49 2014 +0800 : update AdminView, add get_student_course_score, fixes #18, fixes #19
d133b60 - Zeno Zeng, Mon Jun 16 22:25:10 2014 +0800 : fix some bugs, fixes #16, fixes #17
15a7a69 - Zeno Zeng, Mon Jun 16 21:41:36 2014 +0800 : use getline instead of cin in BaseView
d0bb456 - Zeno Zeng, Mon Jun 16 21:24:56 2014 +0800 : fix exit in baseView's repl loop, use getline instead of cin in adminView
3f082b2 - Zeno Zeng, Fri Jun 13 14:56:02 2014 +0800 : Update test.cpp
d6c15a2 - Zeno Zeng, Fri Jun 13 14:55:29 2014 +0800 : Update test.cpp
6c95f13 - Zeno Zeng, Thu Jun 12 21:31:13 2014 +0800 : add display_student_courses/add_student_course/remove_student_course/set_student_course_score for AdminView, fixes #13
3738926 - Zeno Zeng, Thu Jun 12 19:56:06 2014 +0800 : add edit course/add course/remove course/users/edit user/add user/remove user support for AdminView
11228de - Zeno Zeng, Thu Jun 12 19:47:59 2014 +0800 : use getline instead of cin to allow whitespace as cmd
f9b54bc - Zeno Zeng, Thu Jun 12 19:10:56 2014 +0800 : add BaseView
f6a96c1 - Zeno Zeng, Thu Jun 12 16:27:13 2014 +0800 : add *.swo to .gitignore
eefdae2 - Zeno Zeng, Thu Jun 12 16:12:05 2014 +0800 : add wintest to Makefile
0db85d7 - Zeno Zeng, Thu Jun 12 16:11:06 2014 +0800 : merge
22722e6 - Zeno Zeng, Thu Jun 12 16:09:30 2014 +0800 : new pathExists using stat, fixes #11
87b91fe - Zeno Zeng, Wed Jun 11 20:09:19 2014 +0800 : update README
07ee646 - Zeno Zeng, Wed Jun 11 15:47:22 2014 +0800 : add admin view
da6964a - Zeno Zeng, Wed Jun 11 12:58:42 2014 +0800 : rewrite rm_r using stat(), fixes #9
e60ffbc - Zeno Zeng, Wed Jun 11 01:50:34 2014 +0800 : update StudentView::init()
ad9e3b5 - Zeno Zeng, Wed Jun 11 01:47:19 2014 +0800 : fix prefix issue of database.cpp
17de158 - Zeno Zeng, Wed Jun 11 01:35:29 2014 +0800 : add StudentView::exit, fixes #8
6e28f56 - Zeno Zeng, Wed Jun 11 01:28:56 2014 +0800 : update Makefile, fixes #7
61c652e - Zeno Zeng, Wed Jun 11 01:20:32 2014 +0800 : rewrite session using new api
f5c9dc6 - Zeno Zeng, Wed Jun 11 01:04:30 2014 +0800 : add some users for testing
9a075a0 - Zeno Zeng, Wed Jun 11 00:56:34 2014 +0800 : add ::list, fixes #5
4d7e84f - Zeno Zeng, Tue Jun 10 16:07:43 2014 +0800 : find . -name \*.swp | xargs rm, add *.swp in gitignore, fixes #6
c158890 - Zeno Zeng, Sat Jun 7 03:19:44 2014 +0800 : init StudentView
75b3431 - Zeno Zeng, Sat Jun 7 03:18:43 2014 +0800 : init StudentView
d9c71b0 - Zeno Zeng, Sat Jun 7 02:59:35 2014 +0800 : update help()
276f465 - Zeno Zeng, Sat Jun 7 02:46:27 2014 +0800 : update ui
b578c1f - Zeno Zeng, Sat Jun 7 02:28:11 2014 +0800 : fixes for course_manager
98b1d2e - Zeno Zeng, Sat Jun 7 02:06:09 2014 +0800 : fix typo
8bae579 - Zeno Zeng, Sat Jun 7 02:03:00 2014 +0800 : update Makefile, add make winbuild
91a7d7b - Zeno Zeng, Sat Jun 7 01:59:25 2014 +0800 : class Database
b77b29e - Zeno Zeng, Fri Jun 6 21:52:31 2014 +0800 : add file_put_contents & add test/
d5413be - Zeno Zeng, Fri Jun 6 21:00:26 2014 +0800 : update Makefile, use g++
a9cc02f - Zeno Zeng, Thu Jun 5 18:02:01 2014 +0800 : update hashlib++ license
dcddc4d - Zeno Zeng, Thu Jun 5 18:01:19 2014 +0800 : add hashlib++ license
9d22cad - Zeno Zeng, Thu Jun 5 17:30:36 2014 +0800 : login & logout, fixes #2
c3c2e7b - Zeno Zeng, Thu Jun 5 00:20:23 2014 +0800 : update help()
f9f7c9b - Zeno Zeng, Thu Jun 5 00:06:09 2014 +0800 : update this->group
2ea5e24 - Zeno Zeng, Wed Jun 4 23:48:17 2014 +0800 : remove .svn & swp
31c8895 - Zeno Zeng, Wed Jun 4 23:47:30 2014 +0800 : 增加哈希密码校验
06ddd00 - Zeno Zeng, Wed Jun 4 22:58:12 2014 +0800 : check if username is invalid
5378a28 - Zeno Zeng, Wed Jun 4 22:48:40 2014 +0800 : check if user exists
956623e - Zeno Zeng, Wed Jun 4 22:15:10 2014 +0800 : add lib & session
2df8944 - Zeno Zeng, Wed Jun 4 18:24:06 2014 +0800 : init repo
c9ef497 - Zeno Zeng, Wed Jun 4 17:54:41 2014 +0800 : update README
35b5a93 - Zeno Zeng, Wed Jun 4 17:50:31 2014 +0800 : Initial commit
```

## 类的设计思路

### Database

按照 HTML5 localStorage 为原型，
基于 FileSystem 函数封装的一个 Key-Value 型数据库。
提供 set，get，remove 三个方法。
每个 value 对应一个文件，一个 object 对应一个目录。
如课程ID为12345678（key：courses/12345678/） 是一个object，对应一个目录，
下有子文件 name, teacher 等，对应key：courses/12345678/name 以及 courses/12345678/teacher

### BaseView

封装的所有 View 的基类。
包括了 init 方法，会启动一个 REPL（read-eval-print loop），
读取用户输入交给 dispatch 方法（是个虚函数，交给子类实现的）。
另外放了三个在所有子类都会公用到方法在baseView里头。
另外在类初始化的时候还会自动初始化 UserManager 和 CourseManager 作为成员变量。

### AdminView

基于 BaseView 构建，提供一些基本的管理操作：

```
Common Commands:
	exit: logout
	help: get help
Course Manager:
	courses: list all courses
	course: show detail of course
	edit course: edit course
	add course: add course
	remove course: remove course
User Manager:
	users: list all users
	edit user: edit user
	add user: add user
	remove user: remove user
Student Course Manager:
	courses of student: list all courses of a student
	add course for student: add course for student
	remove course of student: remove course of student
	get course score of student: get course score of student
	set course score of student: set course score of student
```


### CourseManager

TODO

### Session

TODO

## 心得体会

- 早知道跨平台这么麻烦就用 boost 了！
