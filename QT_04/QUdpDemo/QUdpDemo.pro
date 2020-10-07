#-------------------------------------------------
#
# Project created by QtCreator 2017-05-09T11:27:25
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QUdpDemo
TEMPLATE = app


SOURCES += main.cpp\
        udp1.cpp \
    udp2.cpp

HEADERS  += udp1.h \
    udp2.h

FORMS    += udp1.ui \
    udp2.ui
