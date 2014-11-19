#-------------------------------------------------
#
# Project created by QtCreator 2014-10-10T17:34:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tower
TEMPLATE = app


SOURCES += main.cpp\
    myGridLayout.cpp \
    verticalbox.cpp \
    colorwheel.cpp \
    mainwindow.cpp

HEADERS  += myGridLayout.h \
    verticalbox.h \
    floatspinbox.h \
    colorwheel.h \
    mainwindow.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc \
    rsc_pic/images.qrc
