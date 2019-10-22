#-------------------------------------------------
#
# Project created by QtCreator 2019-05-05T14:37:13
#
#-------------------------------------------------

# QT包含的模块
QT       += core gui

# 向下兼容大于4版本以上才包含widget模块
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# 目标文件，生成的可执行文件名
TARGET = 02_SignalsAndSlot

# 模板
TEMPLATE = app

# 源文件
SOURCES += main.cpp\
        widget.cpp \
    teacher.cpp \
    student.cpp

# 头文件
HEADERS  += widget.h \
    teacher.h \
    student.h
