TEMPLATE = app
CONFIG += console
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++0x

SOURCES += \
    Hometask_2.cpp \
    linkedstack.cpp \
    stackcalculator.cpp \
    arraystack.cpp \
    doublylinkedlist.cpp

HEADERS += \
    stack.h \
    linkedstack.h \
    stackcalculator.h \
    arraystack.h \
    doublylinkedlist.h \
    list.h

OTHER_FILES += \
    temp.txt

