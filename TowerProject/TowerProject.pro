#-------------------------------------------------
#
# Project created by QtCreator 2014-10-02T15:03:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TowerProject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    pixel.cpp \
    grid.cpp \
    animation.cpp \
    pixelgroup.cpp

HEADERS  += mainwindow.h \
    pixel.h \
    grid.h \
    animation.h \
    pixelgroup.h

FORMS    += mainwindow.ui
