#-------------------------------------------------
#
# Project created by QtCreator 2014-12-03T15:03:29
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TowerLights2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    animation.cpp \
    grid.cpp \
    pixel.cpp \
    pixelgroup.cpp \
    frame.cpp \
    movie.cpp

HEADERS  += mainwindow.h \
    animation.h \
    grid.h \
    pixel.h \
    pixelgroup.h \
    frame.h \
    movie.h

FORMS    += mainwindow.ui
