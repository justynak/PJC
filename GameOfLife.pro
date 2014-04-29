#-------------------------------------------------
#
# Project created by QtCreator 2014-03-27T16:14:58
#
#-------------------------------------------------

QT       += core gui

TARGET = GameOfLife
TEMPLATE = app


SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    src/cell.cpp \
    src/area.cpp

HEADERS  += src/mainwindow.h \
    src/cell.h \
    src/area.h

FORMS    += \
    src/area.ui

OTHER_FILES += \
    CMakeLists.txt
