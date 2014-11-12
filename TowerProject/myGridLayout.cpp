#include <QPushButton>
#include <QGridLayout>
#include <cstring>
#include <QPalette>
#include <QColor>

#include "myGridLayout.h"
using namespace std;

void myGridLayout::setColor(int i, int j, QColor color) {
    QPalette pal;
    pal = ptrBtn[i][j]->palette();
    pal.setColor(QPalette::Button, color);
    ptrBtn[i][j]->setPalette(pal);
    ptrBtn[i][j]->setAutoFillBackground(true);
}

void myGridLayout::setButtonSize(int i, int j){
    mx = i;
    my = j;
    for (int i = 0; i < mRow; ++i) 
        for (int j = 0; j < mCol; ++j) 
            ptrBtn[i][j]->setFixedSize(i, j);
}

void myGridLayout::setSpacing(int x) {
    mSpacing = x;
    ptrGrid->setSpacing(x);
}

QGridLayout* myGridLayout::getPtrQGridLayout() {
    return ptrGrid;
}

void myGridLayout::printH(QColor color){ // LightSkyBlue 135,206,250
    for (int i = 0; i < 7; ++i) {
        setColor(i, 0, color);
        setColor(i, 3, color);
    }
    setColor(3, 1, color);
    setColor(3, 2, color);
}
void myGridLayout::printM(QColor color){ // 255,215,0
    for (int i = 0; i < 7; ++i) {
        setColor(i, 0, color);
        setColor(i, 3, color);
    }
    for (int i = 1; i < 3; ++i) {        
        setColor(0, i, color);
        setColor(3, i, color);
        setColor(6, i, color);
    }
}

void myGridLayout::printE(QColor color){
    for (int i = 0; i < 7; ++i) 
        setColor(i, 0, color);
    for (int i = 0; i < 4; ++i) {        
        setColor(0, i, color);
        setColor(6, i, color);
    }
    setColor(3, 1, color);
    setColor(3, 2, color);
}

void myGridLayout::printR(QColor color){
    for (int i = 0; i < 7; ++i) 
        setColor(i, 0, color);
    for (int i = 0; i < 4; ++i)
        setColor(i, 3, color);
    for (int i = 1; i < 3; ++i) {        
        setColor(0, i, color);
        setColor(3, i, color);
    }
    setColor(4, 1, color);
    setColor(5, 2, color);
    setColor(6, 3, color);
}

void myGridLayout::printP(QColor color){
    for (int i = 0; i < 7; ++i)
        setColor(i, 0, color);
    for (int i = 0; i < 4; ++i)
        setColor(i, 3, color);
    for (int i = 1; i < 3; ++i) {        
        setColor(0, i, color);
        setColor(3, i, color);
    }
}

myGridLayout::myGridLayout(int row, int col, QWidget *parent)
    : QWidget(parent) {
    mRow = row;
    mCol = col;

    ptrBtn = new QPushButton** [mRow];
    for (int j = 0; j < mRow; ++j) 
        ptrBtn[j] = new QPushButton*[mCol];
    
    ptrGrid = new QGridLayout();
    ptrGrid->setSpacing(5);

    for (int i = 0; i < mRow; i++) {
        for (int j = 0; j< mCol; j++) {
            ptrBtn[i][j] = new QPushButton();
            ptrBtn[i][j]->setFixedSize(40, 40);
            ptrGrid->addWidget(ptrBtn[i][j], i, j);
        }
    }
    setLayout(ptrGrid);
}
/*
myGridLayout& myGridLayout::operator=(const myGridLayout& src) {
    if (this != src) {
        myGridLayout a(mRow, mCol);
        a.setSpacing(src.mSpacing);
        for (int i = 0; i < src.mRow; ++i ) {
            for (int j = 0; j < src.mCol; ++j ) {
                setColor(i, j, src.getColor(i, j));
            }
        }
        a.setButtonSize(src.getmx(), src.getmy());
    }
    return a;
}
*/
QColor myGridLayout::getColor(int i, int j) {
    QColor color = ptrBtn[i][j]->palette().color(QPalette::Button);
    return color;
}


myGridLayout::~myGridLayout() {
    for (int i = 0; i < mCol; ++i) {
        delete [] ptrBtn[i];
    }
    delete [] ptrBtn;
}

