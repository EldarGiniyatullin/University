TEMPLATE = app
CONFIG += console
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += testcase

QT += core
QT += testlib

CONFIG += c++11

SOURCES += \
    Hometask_1.cpp \
    linkedlist.cpp \
    doublylinkedlist.cpp

HEADERS += \
    list.h \
    linkedlist.h \
    doublylinkedlist.h \
    listtest.h

