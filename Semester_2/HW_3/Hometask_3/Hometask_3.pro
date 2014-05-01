#-------------------------------------------------
#
# Project created by QtCreator 2014-03-27T12:25:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Hometask_3
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++0x

SOURCES +=\
        ubercalculator.cpp \
    stackcalculator.cpp \
    linkedstack.cpp \
    doublylinkedlist.cpp \
    Hometask_3.cpp

HEADERS  += ubercalculator.h \
    stackcalculator.h \
    stack.h \
    list.h \
    linkedstack.h \
    doublylinkedlist.h

FORMS    += ubercalculator.ui
