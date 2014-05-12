TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += testcore

QT += core
QT +=testlib


CONFIG += c++11

QMAKE_CXXFLAGS += -std=c++0x

SOURCES += \
    Hometask_1.cpp \
    parsetree.cpp

HEADERS += \
    parsetree.h \
    addition.h \
    multiplication.h \
    subtraction.h \
    division.h \
    numericaloperand.h \
    operatorclass.h \
    testparsetree.h

OTHER_FILES += \
    expression.txt \
    result.txt \
    testparsetree1.txt \
    testparsetree2.txt \
    testparsetree3.txt

