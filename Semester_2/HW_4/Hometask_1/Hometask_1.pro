TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += testcore
CONFIG += c++11

QT += core
QT += testlib

QMAKE_CXXFLAGS += -std=c++0x

SOURCES += \
    Hometask_1.cpp \
    list.cpp \
    hashtable.cpp

HEADERS += \
    list.h \
    hashtable.h \
    hashfunction.h \
    hashfunction1.h \
    testhash.h \
    hashfunction2.h

OTHER_FILES += \
    text.txt \
    output.txt \
    input.txt
