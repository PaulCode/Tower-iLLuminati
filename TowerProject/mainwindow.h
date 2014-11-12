#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGroupBox>
#include <QDialogButtonBox>
#include <QWidget>
#include "buttons.h"

class MainWindow : public QMainWindow 
{
    Q_OBJECT
 public:
    explicit MainWindow(QWidget *parent = 0);
    //MainWindow();
    ~MainWindow();
    
    void add_widget( QWidget* p_widget );
    Buttons button;

 private:
            QMenu *fileMenu;
        QMenu *edit;
        QMenu *insert;
        QMenu *animate;
        QMenu *view;
        QMenu *help;
        QMenu *about;   //
        QAction *openAction;
        QAction *exitAction;
        QAction *openAction2;
        QAction *openAction3;
        QAction *openAction4;
        QAction *openAction5;
        QToolBar *toolBar;
        //QMenu *file;
        //QPushButton *buttons[NumButtons];
        QGroupBox *horizontalGroupBox;
        QDialogButtonBox *buttonBox;

        /*
    QPushButton *left;
    QPushButton *right;
    QPushButton *up;
    QPushButton *down;
    QPushButton *upleft;
    QPushButton *downleft;
    QPushButton *upright;
    QPushButton *downright;
    
    QPushButton *save;
    QPushButton *play;
    QPushButton *stop;
    QPushButton *pause;
    QPushButton *plus;
    QPushButton *minus;
    QPushButton *duplicate;
    QPushButton *clear;
    QPushButton *mButton[17];
        */
    void open();

};
    
#endif // MAINWINDOW_H
