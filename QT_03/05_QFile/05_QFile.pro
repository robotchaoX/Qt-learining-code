#-------------------------------------------------
#
# Project created by QtCreator 2017-05-08T16:38:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 05_QFile
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    filesystemwatcher.cpp

HEADERS  += widget.h \
    filesystemwatcher.h

FORMS    += widget.ui
