# 简易教务系统

## 目标

- 面向学生、老师、管理员

- 学生：选课，查看课程安排

- 教师：查看课程安排，查看选课情况，录入成绩等

- 管理员：管理课程信息，学生和老师的信息

- 各个部分的增删改查功能

## Build

### Linux

```
make build
```

### Windows

```
make winbuild
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

## License

AGPL

### hashlib++ license

hashlib++ - a simple hash library for C++ 

Copyright (c) 2007-2011 Benjamin Grüdelbach 

Redistribution and use in source and binary forms, with or without modification, 

are permitted provided that the following conditions are met: 

1) Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer. 

2) Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
