Imsun
=======

```
孙士权 3120103709 计算机科学与技术
```

## 完成哪些工作

### 概述

架构设计，UserManager 类，StudentCourseManager 类，StudentView 类，TeacherView 类。

### Commit Log

```
? git log --pretty=format:"%h - %an, %s" | grep "R7" | sed -e "s/ - R7//g"     
6df3441, Merge branch 'master' of https://github.com/zenozeng/jw
8a1cfd9, add comments
7ae9e4e, add comments
e4c1b38, Merge branch 'master' of https://github.com/zenozeng/jw
3445ca2, rename student view
264376f, merge
d5e6426, add score to studnet
29a389d, refine teacher view
02f3a58, Merge branch 'master' of https://github.com/zenozeng/jw
d418872, refine views
d53c3b5, add select command to student view
5807283, Merge branch 'master' of https://github.com/zenozeng/jw
4bd46cf, add names for student and teacher
637d08f, rewrite views with base view and fix some bugs
27e3c50, fix the bug of pathExists under Windows
c3d47cb, fixed bug in views
6edea96, Merge branch 'master' of https://github.com/zenozeng/jw
0ce0de9, Merge branch 'master' of https://github.com/zenozeng/jw
ff6c09d, overload get method
a857633, Merge branch 'master' of https://github.com/zenozeng/jw
da84595, merge
caf4c3f, Merge branch 'master' of https://github.com/zenozeng/jw
9ede21f, add teacher view and fix some bugs
9e2ac0b, add models and views
ba1c9a3, Merge branch 'master' of https://github.com/zenozeng/jw
3bbaf26, Merge branch 'master' of https://github.com/zenozeng/jw
b0c3f8a, Merge branch 'master' of https://github.com/zenozeng/jw
b117155, Merge branch 'master' of https://github.com/zenozeng/jw
50c765b, back up
```

##	类的设计思路

### Model 部分

我们将数据库操作部分全部封装到 model，避免数据库操作直接暴露到业务逻辑中。这样也有利于降低耦合性，提高程序的灵活性。

### View 部分

View 部分负责处理与用户的交互和业务逻辑。为了加强重用，我们将输入输出处理写在了基类中，命令的路由和处理细节则放到各个子类中。

## 心得体会

恰当地使用 OO 和设计模式能够有效地提高工作效率和代码的灵活性，并使程序更易于测试。
