#-------------------------------------------------
#
# Project created by QtCreator 2019-07-15T21:12:48
#
#-------------------------------------------------

# QT包含的模块
QT       += core gui

# 向下兼容大于4版本以上才包含widget模块
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# 目标文件，生成的可执行文件名
TARGET = 01_Qt_First

# 模板
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
#DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# 源文件
SOURCES += main.cpp\
        mywidget.cpp \
    mybutton.cpp

# 头文件
HEADERS  += mywidget.h \
    mybutton.h
