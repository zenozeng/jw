# 简易教务系统

## 目标

- 面向学生、老师、管理员

- 学生：选课，查看课程安排

- 教师：查看课程安排，查看选课情况，录入成绩等

- 管理员：管理课程信息，学生和老师的信息

- 各个部分的增删改查功能

## Build

```
sudo apt-get install clang
make build
```

## 约定

我们直接用文件目录结构作为数据库来存储吧！

### user

默认用户：

USERNAME: admin

PWD: 123456

#### group

- student

- teacher

- administrator

#### password

这个是密码的简单单次 md5，
这里只是示意一下，
实际使用请加强此块。
