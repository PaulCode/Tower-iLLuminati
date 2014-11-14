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
#include <QSpinBox>
#include <iostream>

#include "myGridLayout.h"
#include "colorwheel.h"

class Buttons : public QWidget {
    Q_OBJECT
 public:
     Buttons(QWidget *parent = 0);
     virtual ~Buttons(){};
    public slots:
        void tbrowBtnClicked(); // for .tan file "Browse" button

        // for "pre" "cur" button to get latest color used
        void preBtnClicked(){newColor = getPreCurColor(pre);setColor(cur);setSpinBoxValue();}
        void curBtnClicked(){newColor = getPreCurColor(cur);setColor(cur);setSpinBoxValue();}
        
        // for 17 predefined color slots
        void preColorClicked0() {newColor = getPreColor(0);setColor(cur);setSpinBoxValue();}
        void preColorClicked1() {newColor = getPreColor(1);setColor(cur);setSpinBoxValue();}
        void preColorClicked2() {newColor = getPreColor(2);setColor(cur);setSpinBoxValue();}
        void preColorClicked3() {newColor = getPreColor(3);setColor(cur);setSpinBoxValue();}
        void preColorClicked4() {newColor = getPreColor(4);setColor(cur);setSpinBoxValue();}
        void preColorClicked5() {newColor = getPreColor(5);setColor(cur);setSpinBoxValue();}
        void preColorClicked6() {newColor = getPreColor(6);setColor(cur);setSpinBoxValue();}
        void preColorClicked7() {newColor = getPreColor(7);setColor(cur);setSpinBoxValue();}
        void preColorClicked8() {newColor = getPreColor(8);setColor(cur);setSpinBoxValue();}
        void preColorClicked9() {newColor = getPreColor(9);setColor(cur);setSpinBoxValue();}
        void preColorClicked10() {newColor = getPreColor(10);setColor(cur);setSpinBoxValue();}
        void preColorClicked11() {newColor = getPreColor(11);setColor(cur);setSpinBoxValue();}
        void preColorClicked12() {newColor = getPreColor(12);setColor(cur);setSpinBoxValue();}
        void preColorClicked13() {newColor = getPreColor(13);setColor(cur);setSpinBoxValue();}
        void preColorClicked14() {newColor = getPreColor(14);setColor(cur);setSpinBoxValue();}
        void preColorClicked15() {newColor = getPreColor(15);setColor(cur);setSpinBoxValue();}
        void preColorClicked16() {newColor = getPreColor(16);setColor(cur);setSpinBoxValue();}

        // for 12x6 grid slots
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
        QColor getPreColor(int idx);        // get color from predefined array
        QColor getPreCurColor(QPushButton*);// get color from "pre cur"  button
        void setSpinBoxValue();
        void setHeight(QPlainTextEdit *edit, int nRows);
        void addFrame(QGridLayout*);
        void open();
        void printH(QColor color);
        void printM(QColor color);
        void printE(QColor color);
        void printP(QColor color);
        void printR(QColor color);
 private:
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
        QString filename;
        QPushButton* scrLeft;
        QPushButton* scrRight;
        QPlainTextEdit *tedit;
        QPushButton *pre; // store the last color used
        QPushButton *cur; // for preview current color
        QSpinBox *rspinBox;
        QSpinBox *gspinBox;
        QSpinBox *bspinBox;
        QColor newColor;
        QColor curColor;
};
