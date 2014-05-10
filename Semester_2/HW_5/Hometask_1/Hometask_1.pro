TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

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
    operatorclass.h

OTHER_FILES += \
    expression.txt \
    result.txt

