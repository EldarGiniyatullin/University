TEMPLATE = app
CONFIG += console
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++0x

SOURCES += \
    Hometask_2.cpp \
    consoledisplayer.cpp \
    filedisplayer.cpp \
    arrayspiraldisplayer.cpp

HEADERS += \
    arrayspiraldisplayer.h \
    consoledisplayer.h \
    filedisplayer.h \
    arraysoft.h

OTHER_FILES += \
    result.txt \
    text.txt
