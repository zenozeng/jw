# ZenoZeng

```
曾昱深 3120100260 生物系统工程
```

## 完成哪些工作

### 概述

架构设计，Database类，FileSystem相关函数（及相关测试），MD5 Hash函数封装。
BaseView类，AdminView类，CourseManager类，Session类，Main.cpp。

### Commit Log

```
git log --pretty=format:"%h - %an, %s" | grep "Zeno" | sed -e "s/ - Zeno Zeng//g"
c8daf36, use pandoc, wkhtmltopdf to generate docs
69f3379, update docs/zenozeng.md
bdc2b88, add docs/zenozeng.md
c41fc6f, fix typo
768e140, add comments
47b69c2, add comments for Database
391ea44, add comments for lib
557ea1e, add comments for main.cpp
bb22d96, Merge branch 'master' of https://github.com/zenozeng/jw
beb4038, add comments for session.cpp
d902b42, add Database::parse_key, only allow [0-9A-Za-z/\._-,], fixes #20
d15a64e, reorganize files
9b3409b, Merge branch 'master' of https://github.com/zenozeng/jw
a7225e6, update AdminView, add get_student_course_score, fixes #18, fixes #19
d133b60, fix some bugs, fixes #16, fixes #17
15a7a69, use getline instead of cin in BaseView
d0bb456, fix exit in baseView's repl loop, use getline instead of cin in adminView
3f082b2, Update test.cpp
d6c15a2, Update test.cpp
6c95f13, add display_student_courses/add_student_course/remove_student_course/set_student_course_score for AdminView, fixes #13
3738926, add edit course/add course/remove course/users/edit user/add user/remove user support for AdminView
11228de, use getline instead of cin to allow whitespace as cmd
f9b54bc, add BaseView
f6a96c1, add *.swo to .gitignore
eefdae2, add wintest to Makefile
0db85d7, merge
22722e6, new pathExists using stat, fixes #11
87b91fe, update README
07ee646, add admin view
da6964a, rewrite rm_r using stat(), fixes #9
e60ffbc, update StudentView::init()
ad9e3b5, fix prefix issue of database.cpp
17de158, add StudentView::exit, fixes #8
6e28f56, update Makefile, fixes #7
61c652e, rewrite session using new api
f5c9dc6, add some users for testing
9a075a0, add ::list, fixes #5
4d7e84f, find . -name \*.swp | xargs rm, add *.swp in gitignore, fixes #6
c158890, init StudentView
75b3431, init StudentView
d9c71b0, update help()
276f465, update ui
b578c1f, fixes for course_manager
98b1d2e, fix typo
8bae579, update Makefile, add make winbuild
91a7d7b, class Database
b77b29e, add file_put_contents & add test/
d5413be, update Makefile, use g++
a9cc02f, update hashlib++ license
dcddc4d, add hashlib++ license
9d22cad, login & logout, fixes #2
c3c2e7b, update help()
f9f7c9b, update this->group
2ea5e24, remove .svn & swp
31c8895, 增加哈希密码校验
06ddd00, check if username is invalid
5378a28, check if user exists
956623e, add lib & session
2df8944, init repo
c9ef497, update README
35b5a93, Initial commit
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

就是基本的 CRUD，调用 Database 类的方法就行。

### Session

登陆会话管理，提供 login 和 logout，实例会保存当前用户的 id 及用户组信息。

## 心得体会

- 早知道跨平台这么麻烦就用 boost 了！

- Git 很好用。

- 基于文件系统存储可以简化数据库构建。

- 要是早点写单元测试的话，就不用手动调试调半天了。单元测试才是节约生命的做法。

- 像 shell 一样基于 string 会带来一定的动态能力，但常常引入大量字符操作，有利有弊
