#ifndef myGridLayout_H
#define myGridLayout_H

#include <QWidget>
#include <QPushButton>
#include <cstring>
#include <QColor>
#include <QGridLayout>

using namespace std;

class myGridLayout : public QWidget {
public:
    myGridLayout(int row, int col, QWidget *parent = 0);
    ~myGridLayout();
    void setButtonSize(int i, int j);

    void setSpacing(int x);
    int getSpacing() {return mSpacing;}
    int getRow() {return mRow;}
    int getCol() {return mCol;}
    int getmx() {return mx;}
    int getmy() {return my;}
    void setColor(int i, int j, QColor color);
    QColor getColor(int i, int j);
    void printH(QColor color);
    void printM(QColor color);
    void printE(QColor color);
    void printP(QColor color);
    void printR(QColor color);
    QGridLayout* getPtrQGridLayout();
    QGridLayout* ptrGrid;
//myGridLayout& operator=(const myGridLayout&);

private:
    int mRow;
    int mCol;
    int mSpacing = 5;
    int mx = 40;
    int my = 40;
    QPushButton*** ptrBtn;
};

#endif // MYGRIDLAYOUT_H
