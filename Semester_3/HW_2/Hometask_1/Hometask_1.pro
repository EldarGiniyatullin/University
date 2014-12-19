TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle
CONFIG += qt
CONFIG += testcore

QT += core
QT += testlib

SOURCES += \
    Hometask_1.cpp \
    localnet.cpp \
    personalcomputer.cpp \
    operatingsystem.cpp

HEADERS += \
    personalcomputer.h \
    operatingsystem.h \
    localnet.h \
    testlocalnet.h

