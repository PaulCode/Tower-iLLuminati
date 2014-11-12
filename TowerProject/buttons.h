#pragma once

#include <QObject>
#include <QDebug>
#include <QWidget>
#include <QPushButton>
#include <QMenuBar>
#include <QPlainTextEdit>
#include <QMainWindow>
#include <QGroupBox>
#include <QDialogButtonBox>

#include "myGridLayout.h"
#include "colorwheel.h"

//class Buttons : public QWidget, public QObject {
class Buttons : public QWidget {
    Q_OBJECT
 public:
    //explicit Buttons(QWidget *parent = 0);
     Buttons(QWidget *parent = 0);
     //~Buttons();
     virtual ~Buttons(){};
    //explicit Buttons(QObject *parent = 0);
    // signals:
    public slots:
        void wbrowBtnClicked();
        void tbrowBtnClicked();
        void preColorClicked0() {newColor = getPreColor(0);setColor(cur);}
        void preColorClicked1() {newColor = getPreColor(1);setColor(cur);}
        void preColorClicked2() {newColor = getPreColor(2);setColor(cur);}
        void preColorClicked3() {newColor = getPreColor(3);setColor(cur);}
        void preColorClicked4() {newColor = getPreColor(4);setColor(cur);}
        void preColorClicked5() {newColor = getPreColor(5);setColor(cur);}
        void preColorClicked6() {newColor = getPreColor(6);setColor(cur);}
        void preColorClicked7() {newColor = getPreColor(7);setColor(cur);}
        void preColorClicked8() {newColor = getPreColor(8);setColor(cur);}
        void preColorClicked9() {newColor = getPreColor(9);setColor(cur);}
        void preColorClicked10() {newColor = getPreColor(10);setColor(cur);}
        void preColorClicked11() {newColor = getPreColor(11);setColor(cur);}
        void preColorClicked12() {newColor = getPreColor(12);setColor(cur);}
        void preColorClicked13() {newColor = getPreColor(13);setColor(cur);}
        void preColorClicked14() {newColor = getPreColor(14);setColor(cur);}
        void preColorClicked15() {newColor = getPreColor(15);setColor(cur);}
        void preColorClicked16() {newColor = getPreColor(16);setColor(cur);}
        void gridLayoutClicked00();
        void gridLayoutClicked01();
        void gridLayoutClicked02();
        void gridLayoutClicked03();
        void gridLayoutClicked04();
        void gridLayoutClicked05();
        void gridLayoutClicked10();
        void gridLayoutClicked11();
        void gridLayoutClicked12();
        void gridLayoutClicked13();
        void gridLayoutClicked14();
        void gridLayoutClicked15();
        void gridLayoutClicked20();
        void gridLayoutClicked21();
        void gridLayoutClicked22();
        void gridLayoutClicked23();
        void gridLayoutClicked24();
        void gridLayoutClicked25();
        void gridLayoutClicked30();
        void gridLayoutClicked31();
        void gridLayoutClicked32();
        void gridLayoutClicked33();
        void gridLayoutClicked34();
        void gridLayoutClicked35();
        void gridLayoutClicked40();
        void gridLayoutClicked41();
        void gridLayoutClicked42();
        void gridLayoutClicked43();
        void gridLayoutClicked44();
        void gridLayoutClicked45();
        void gridLayoutClicked50();
        void gridLayoutClicked51();
        void gridLayoutClicked52();
        void gridLayoutClicked53();
        void gridLayoutClicked54();
        void gridLayoutClicked55();
        void gridLayoutClicked60();
        void gridLayoutClicked61();
        void gridLayoutClicked62();
        void gridLayoutClicked63();
        void gridLayoutClicked64();
        void gridLayoutClicked65();
        void gridLayoutClicked70();
        void gridLayoutClicked71();
        void gridLayoutClicked72();
        void gridLayoutClicked73();
        void gridLayoutClicked74();
        void gridLayoutClicked75();
        void gridLayoutClicked80();
        void gridLayoutClicked81();
        void gridLayoutClicked82();
        void gridLayoutClicked83();
        void gridLayoutClicked84();
        void gridLayoutClicked85();
        void gridLayoutClicked90();
        void gridLayoutClicked91();
        void gridLayoutClicked92();
        void gridLayoutClicked93();
        void gridLayoutClicked94();
        void gridLayoutClicked95();
        void gridLayoutClicked100();
        void gridLayoutClicked101();
        void gridLayoutClicked102();
        void gridLayoutClicked103();
        void gridLayoutClicked104();
        void gridLayoutClicked105();
        void gridLayoutClicked110();
        void gridLayoutClicked111();
        void gridLayoutClicked112();
        void gridLayoutClicked113();
        void gridLayoutClicked114();
        void gridLayoutClicked115();
 public:
        void preColorClicked(int);
        void setColor(QPushButton* [][4], int i, int j, QColor);
        void setColor(QPushButton* [][6], int i, int j, QColor);
        void setColor(QPushButton* [][6], int i, int j);
        void setColor(QPushButton*);
        void setColorToDefault(QPushButton*);
        QColor getPreColor(int idx);
        void printH(QColor color);
        void printM(QColor color);
        void printE(QColor color);
        void printP(QColor color);
        void printR(QColor color);
        void setMyGridLayout(int x, int y);
        //void createMenu();
        void setHeight(QPlainTextEdit *edit, int nRows);
        void loadme();
        void saveme();
        void saveFile();
        void saveFileAs();
        void addFrame(QGridLayout*);
        void open();
 private:
        // I have these before
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
        QPushButton *mButton[17];  // for predifined colors
        QPushButton* mButt[12][6];
        myGridLayout* mGrid;
        QGridLayout* gridView[5];
        QPushButton* mBut1[10][4];
        QPushButton* mBut2[10][4];
        QPushButton* mBut3[10][4];
        QPushButton* mBut4[10][4];
        QPushButton* mBut5[10][4];
        QPushButton* dir[4][3];
        QMenuBar *menuBar;
        //QMenu *fileMenu;
        //QAction *exitAction;
        QString filename;
        QPushButton* scrLeft;
        QPushButton* scrRight;
        QPlainTextEdit *wedit;
        QPlainTextEdit *tedit;
        QPushButton *pre; // for previous color review
        QPushButton *cur; // for previous color review
        int mRow;
        int mCol;
        //static int color[36];
        QColor newColor;
        QColor curColor;
};
