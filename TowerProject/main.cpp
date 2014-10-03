/*
 * Tower Animator Porgram
 * Designers:
 *  Matthew Brown
 *  Emeth Thompson
 *  Ranger Adams
 *  Paul Bailey
 *  Heyan Huang
 *
 *  Version 0.0.2
 *
 */

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
