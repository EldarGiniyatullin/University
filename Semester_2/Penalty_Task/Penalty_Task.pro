#-------------------------------------------------
#
# Project created by QtCreator 2014-05-26T18:38:40
#
#-------------------------------------------------

QT       += core gui webkitwidgets xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Penalty_Task
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp \
    widget.cpp

HEADERS  += \
    widget.h

FORMS    += widget.ui

OTHER_FILES += \
    json.txt
