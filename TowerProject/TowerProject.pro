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
    pixelgroup.cpp \
    colorwheel.cpp \
    myGridLayout.cpp

HEADERS  += mainwindow.h \
    pixel.h \
    grid.h \
    animation.h \
    pixelgroup.h \
    colorwheel.h \
    myGridLayout.h
FORMS    +=

RESOURCES += \
    rsc_pic/images.qrc


