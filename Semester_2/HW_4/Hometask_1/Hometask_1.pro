TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++0x

SOURCES += \
    Hometask_1.cpp \
    userstring.cpp \
    list.cpp \
    hashtable.cpp

HEADERS += \
    userstring.h \
    list.h \
    hashtable.h \
    hashfunction.h \
    hashfunction1.h

OTHER_FILES += \
    text.txt \
    output.txt \
    input.txt
