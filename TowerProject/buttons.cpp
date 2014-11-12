#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QSpinBox>
#include <QSlider>
#include <QPalette>
#include <QPushButton>
#include <QLabel>
#include <QTime>
#include <QTimeEdit>
#include <QComboBox>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QMenuBar>
#include <QPlainTextEdit>
#include <QDir>
#include <QFileDialog>
#include <QFile>
#include <QString>
#include <iostream>
#include <string>
#include <QObject>
//#include <QLCDNumber>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <QMainWindow>

#include "colorwheel.cpp"
using namespace std;

#include "buttons.h"
/*
  void Buttons::setMyGridLayout(int x, int y) {
  myGridLayout a(x,y);
  *myGrid = &a;
  }
*/
void Buttons::setHeight(QPlainTextEdit *edit, int nRows) { 
    QFontMetrics m (edit -> font()) ;
    int RowHeight = m.lineSpacing() ;
    edit -> setFixedHeight  (nRows * RowHeight) ;
}

void Buttons::setColor(QPushButton* ptrBtn[][4], int i, int j, QColor color) {
    QPalette pal;
    pal = ptrBtn[i][j]->palette();
    pal.setColor(QPalette::Button, color);
    ptrBtn[i][j]->setPalette(pal);
    ptrBtn[i][j]->setAutoFillBackground(true);
}
void Buttons::setColor(QPushButton* ptrBtn[][6], int i, int j, QColor color) {
    QPalette pal;
    pal = ptrBtn[i][j]->palette();
    pal.setColor(QPalette::Button, color);
    ptrBtn[i][j]->setPalette(pal);
    ptrBtn[i][j]->setAutoFillBackground(true);
}

/*
  void Buttons::createMenu() {
  menuBar = new QMenuBar;
  fileMenu = new QMenu(tr("&File"), this);
  exitAction = fileMenu->addAction(tr("E&xit"));
  menuBar->addMenu(fileMenu);
  connect(exitAction, SIGNAL(triggered()), this, SLOT(accept()));
  }*/

void Buttons::wbrowBtnClicked() {//load a specific file 
    //QFileDialog wdialog = new QFileDialog();
    //getOpenFileName(this, tr("Open File"), QDir::currentPath(), tr("Wave files (*.wav);;Tan files (*.tan);;All files (*.*)"), 0, QFileDialog::DontUseNativeDialog);
    //wdialog->setAcceptMode(QFileDialog::AcceptSave); //To save files,default is open mode.
    filename = QFileDialog::getOpenFileName(this, tr("Open file"), "/home/jenny/480/qt/tower/", tr("Wave files (*.wav);;Tan files (*.tan);;All files (*.*)"));
    wedit->insertPlainText(filename);
}
void Buttons::tbrowBtnClicked() { //load a specific file 
    //QFileDialog *tdialog = new QFileDialog();
    //tdialog->setAcceptMode(QFileDialog::AcceptSave);//To save files,default is open mode.
    filename = QFileDialog::getOpenFileName(this, tr("Open file"), "/home/jenny/480/qt/tower/", tr("Tan files (*.tan);;Wave files (*.wav);;All files (*.*)"));
    tedit->insertPlainText(filename);
}

/*
  void Buttons::saveme() {
  if(FilePath.isEmpty())
  saveFileAs();
  else
  saveFile(FilePath);
  }
  void Buttons::saveFile(const QString &name) { //save the existing file 
  QFile file(name);
  if (file.open(QIODevice::WriteOnly|QIODevice::Text)) {
  file.write(ui->textEdit->toPlainText().toUtf8());
  }
  }
  void Buttons::saveFileAs() { //save as a new file 
  FilePath = QFileDialog::getSaveFileName(this);
  if(FilePath.isEmpty())
  return;
  saveFile(mFilePath);
  }
*/

void Buttons::open() {
    QMessageBox::information(this, tr("Information"), tr("Open"));
}

Buttons::Buttons(QWidget *parent)
    //    : QObject(parent) {
    : QWidget(parent) {


    QHBoxLayout *hbox9 = new QHBoxLayout(this);
    // for menuBar: crashed, walk the other way around
    //hbox9->setMenuBar(menuBar);
    QVBoxLayout *vbox = new QVBoxLayout();

    // hbox10 for 5 images
    QHBoxLayout *hbox10 = new QHBoxLayout();

    for (int i = 0; i < 5; ++i) {        
        gridView[i] = new QGridLayout();
        gridView[i]->setSpacing(3);
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j< 4; j++) {
            mBut1[i][j] = new QPushButton();
            mBut1[i][j]->setFixedSize(20, 20);
            gridView[0]->addWidget(mBut1[i][j], i, j);
        }
    }
    printH(QColor::fromRgb(135,206,250));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j< 4; j++) {
            mBut2[i][j] = new QPushButton();
            mBut2[i][j]->setFixedSize(20, 20);
            gridView[1]->addWidget(mBut2[i][j], i, j);
        }
    }
    printM(QColor::fromRgb(255,215,0));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j< 4; j++) {
            mBut3[i][j] = new QPushButton();
            mBut3[i][j]->setFixedSize(20, 20);
            gridView[2]->addWidget(mBut3[i][j], i, j);
        }
    }
    printR(QColor::fromRgb(143, 188, 143));  
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j< 4; j++) {
            mBut4[i][j] = new QPushButton();
            mBut4[i][j]->setFixedSize(20, 20);
            gridView[3]->addWidget(mBut4[i][j], i, j);
        }
    }
    printP(QColor::fromRgb(176, 196, 222));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j< 4; j++) {
            mBut5[i][j] = new QPushButton();
            mBut5[i][j]->setFixedSize(20, 20);
            gridView[4]->addWidget(mBut5[i][j], i, j);
        }
    }
    printE(QColor::fromRgb(255, 105, 180));
    addFrame(gridView[3]);
    hbox10->addLayout(gridView[0]);
    hbox10->addLayout(gridView[1]);
    hbox10->addLayout(gridView[3]);  // P
    hbox10->addLayout(gridView[2]);  // R
    hbox10->addLayout(gridView[4]);
    /*
      QPushButton *img1 = new QPushButton(QIcon(":/images/m"),tr(" "),this);
      QPushButton *img2 = new QPushButton(QIcon(":/images/h"),tr(" "),this);
      QPushButton *img3 = new QPushButton(QIcon(":/images/e"),tr(" "),this);
      QPushButton *img4 = new QPushButton(QIcon(":/images/p"),tr(" "),this);
      QPushButton *img5 = new QPushButton(QIcon(":/images/r"),tr(" "),this);
      img1->setFixedSize(120,280);
      img2->setFixedSize(120,280);
      img3->setFixedSize(120,280);
      img4->setFixedSize(120,280);
      img5->setFixedSize(120,280);
      hbox10->addWidget(img1);
      hbox10->addWidget(img2);
      hbox10->addWidget(img3);
      hbox10->addWidget(img4);
      hbox10->addWidget(img5);
    */
    vbox->addLayout(hbox10);

    
    // for buttons
    QHBoxLayout *hbox1 = new QHBoxLayout();
    QSpinBox *spinBox = new QSpinBox(this);
    QSlider *slider = new QSlider(Qt::Horizontal, this);
    spinBox->setRange(0, 200);
    slider->setRange(0, 200);
    QObject::connect(slider, &QSlider::valueChanged, spinBox, &QSpinBox::setValue);
    void (QSpinBox:: *spinBoxSignal)(int) = &QSpinBox::valueChanged;
    QObject::connect(spinBox, spinBoxSignal, slider, &QSlider::setValue);
    spinBox->setValue(25);
    scrLeft = new QPushButton(QIcon(":/images/leftI"),tr("ScrollLeft "),this);
    scrRight = new QPushButton(QIcon(":/images/rightI"),tr("ScrollRight"),this);
    scrLeft->setFixedSize(90,30);
    scrRight->setFixedSize(90,30);
    hbox1->addWidget(scrLeft);
    hbox1->addWidget(slider);
    hbox1->addWidget(spinBox);
    hbox1->addWidget(scrRight);
    vbox->addStretch(1);
    vbox->addLayout(hbox1);


    // two file open dialog hboxes hboxw, hboxt
    QHBoxLayout *hboxw = new QHBoxLayout();
    QHBoxLayout *hboxt = new QHBoxLayout();
    QLabel *wav = new QLabel;
    wav->setText(".wav File:");
    QLabel *tan = new QLabel;
    tan->setText(".tan File: ");
    wedit = new QPlainTextEdit;
    tedit = new QPlainTextEdit;
    wedit->setFont(QFont ("Courier", 10));
    tedit->setFont(QFont ("Courier", 10));
    setHeight(wedit, 2);
    setHeight(tedit, 2);
    //QPushButton *wbrow  = new QPushButton(QIcon(":/images/doc-open"), tr("&Browse"), this);
    //connect(wbrow, SIGNAL(released()), this, SLOT(wbrowBtnClicked()));
    //wbrow->setFixedSize(80, 30);
    //hboxw->addWidget(wbrow);
    QPushButton *tbrow  = new QPushButton(QIcon(":/images/doc-open"), tr("&Browse"), this);
    tbrow->setFixedSize(80, 30);
    hboxw->addWidget(wav);
    hboxw->addWidget(wedit);
    hboxt->addWidget(tan);
    hboxt->addWidget(tedit);
    hboxt->addWidget(tbrow);
    /*
    // for fileDialogs for the two wbrow tbrow button
    QFileDialog *wdialog = new QFileDialog();
    wdialog->setAcceptMode(QFileDialog::AcceptSave);//To save files,default is open mode.
    QFileDialog *tdialog = new QFileDialog();
    //tdialog->setAcceptMode(QFileDialog::AcceptSave);//To save files,default is open mode.
    QStringList wfilters, tfilters;
    wfilters << "Wave files (*.wav)" << "Tan files (*.tan)" << "Any files (*)";
    tfilters << "Tan files (*.tan)" << "Wave files (*.wav)" << "Any files (*)";
    wdialog->setNameFilters(wfilters);
    tdialog->setNameFilters(tfilters);
    //wdialog->exec();
    //tdialog->exec();
    */
    // button click activities
    connect(tbrow, SIGNAL(released()), this, SLOT(tbrowBtnClicked()));
    

    QHBoxLayout *hbox2 = new QHBoxLayout();
    /*
      left = new QPushButton(QIcon(":/images/leftI"), tr(" Left "), this);
      right = new QPushButton(QIcon(":/images/rightI"), tr("Right"), this);
      up = new QPushButton(QIcon(":/images/upI"), tr("Up"), this);
      down = new QPushButton(QIcon(":/images/downI"), tr("Down"), this);
      upleft = new QPushButton(QIcon(":/images/upleftI"), tr("UpLeft"), this);
      upright = new QPushButton(QIcon(":/images/uprightI"), tr("UpRight"), this);
      downleft = new QPushButton(QIcon(":/images/downleftI"), tr("DownLeft"), this);
      downright = new QPushButton(QIcon(":/images/downrightI"), tr("DownRight"), this);
    */
    save = new QPushButton(QIcon(":/images/saveI"), tr(" Save "), this);
    play = new QPushButton(QIcon(":/images/playhsI"), tr(" Play "), this);
    stop = new QPushButton(QIcon(":/images/stophsI"), tr(" Stop "), this);
    pause = new QPushButton(QIcon(":/images/pauseI"), tr("Pause"), this);
    plus = new QPushButton(QIcon(":/images/plusI"), tr(" Plus "), this);
    minus = new QPushButton(QIcon(":/images/minusI"), tr("Minus"), this);
    duplicate = new QPushButton(QIcon(":/images/duplicateI"), tr("Duplicate"), this);
    clear = new QPushButton(QIcon(":/images/clearI"), tr("Clear"), this);
    /*
      left->setFixedSize(40, 40);
      right->setFixedSize(40, 40);
      up->setFixedSize(40,40);
      down->setFixedSize(40,40);
      upleft->setFixedSize(40,40);
      upright->setFixedSize(40,40);
      downleft->setFixedSize(40,40);
      downright->setFixedSize(40,40);  */
    save->setFixedSize(80,30);
    play->setFixedSize(80,30);
    stop->setFixedSize(80,30);
    pause->setFixedSize(80,30);
    plus->setFixedSize(80,30);
    minus->setFixedSize(80,30);
    duplicate->setFixedSize(80,30);
    clear->setFixedSize(80,30);
    /*
    // for 8 direction square
    QHBoxLayout *hbox6 = new QHBoxLayout();
    QHBoxLayout *hbox61 = new QHBoxLayout();
    QHBoxLayout *hbox62 = new QHBoxLayout();
    hbox61->addWidget(upleft, 0, Qt::AlignRight);
    hbox61->addWidget(up, 0, Qt::AlignRight);
    hbox61->addWidget(upright, 0, Qt::AlignRight);
    hbox6->addWidget(left, 1, Qt::AlignLeft);  // middle
    hbox6->addWidget(right, 0, Qt::AlignRight);
    hbox62->addWidget(downleft, 0, Qt::AlignRight);
    hbox62->addWidget(down, 0, Qt::AlignRight);
    hbox62->addWidget(downright, 0, Qt::AlignRight);
    QVBoxLayout *vboxSquare = new QVBoxLayout();
    vboxSquare->addLayout(hbox61);
    vboxSquare->addLayout(hbox6);
    vboxSquare->addLayout(hbox62);
    */
    QGridLayout* direction = new QGridLayout();
    direction->setSpacing(5);
    dir[0][0] = new QPushButton(QIcon(":/images/upleftI"), tr(""), this);
    dir[0][1] = new QPushButton(QIcon(":/images/upI"), tr(""), this);
    dir[0][2] = new QPushButton(QIcon(":/images/uprightI"), tr(""), this);
    dir[1][0] = new QPushButton(QIcon(":/images/leftI"), tr(""), this);
    dir[1][1] = new QPushButton();
    dir[1][2] = new QPushButton(QIcon(":/images/rightI"), tr(""), this);
    dir[2][0] = new QPushButton(QIcon(":/images/downleftI"), tr(""), this);
    dir[2][1] = new QPushButton(QIcon(":/images/downI"), tr(""), this);
    dir[2][2] = new QPushButton(QIcon(":/images/downrightI"), tr(""), this);
    dir[3][0] = new QPushButton();
    dir[3][1] = new QPushButton();
    dir[3][2] = new QPushButton();
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j ) {
            dir[i][j]->setFixedSize(40,40);
            direction->addWidget(dir[i][j], i, j);
        }
    }
    dir[1][1]->setFlat(true);
    for (int i = 0; i < 3; ++i)
        dir[3][i]->setFixedSize(40, 56);
    hbox2->addWidget(save, 1, Qt::AlignRight);
    hbox2->addWidget(duplicate, 0, Qt::AlignRight);
    hbox2->addWidget(clear, 0, Qt::AlignRight);
    hbox2->addWidget(plus, 0, Qt::AlignRight);
    hbox2->addWidget(minus, 0, Qt::AlignRight);
    hbox2->addWidget(play, 0, Qt::AlignRight);
    hbox2->addWidget(stop, 0, Qt::AlignRight);
    hbox2->addWidget(pause, 0, Qt::AlignRight);
    //vbox->addLayout(hbox6); // remove this line from top commands
    // add two file open hbox
    //vbox->addLayout(hboxw);  // remove this line cause eventually this file will be included in the .tan file
    vbox->addLayout(hboxt);
    vbox->addLayout(hbox2);


    // inserted verticalbox part
    QVBoxLayout *vbox2 = new QVBoxLayout();
    QHBoxLayout *hbox = new QHBoxLayout();
    QHBoxLayout *hbox7 = new QHBoxLayout();
    QHBoxLayout *hbox3 = new QHBoxLayout();
    QHBoxLayout *hbox4 = new QHBoxLayout();
    QHBoxLayout *hbox5 = new QHBoxLayout();
    vbox->setSpacing(1);
    // two time boxes
    QLabel *atimel = new QLabel;
    //QLCDNumber *lcdNumber1 = new QLCDNumber();
    //lcdNumber1->setNumDigits(9);
    //lcdNumber1->display(00:00.000);
    /*
      QTimer *timer = new QTimer(this);
      timer->start(1000);
      connect(timer, SIGNAL(timeout()), lcdNumber1, SLOT(tick()));
    */
    QTimeEdit *atimeEdit = new QTimeEdit(QTime::currentTime());
    atimeEdit->setTimeRange(QTime(0, 0, 0, 0), QTime(23, 59, 0, 0));
    QLabel *btimel = new QLabel;
    QTimeEdit *btimeEdit = new QTimeEdit(QTime::currentTime());
    btimeEdit->setTimeRange(QTime(0, 0, 0, 0), QTime(23, 59, 0, 0));
    atimel->setText(tr("  Frame Start Time"));
    btimel->setText(tr("Increment Amount"));
    hbox->addWidget(atimeEdit);
    //hbox->addWidget(lcdNumber1);
    hbox->addWidget(atimel);
    hbox7->addWidget(btimeEdit);
    //hbox7->addWidget(timer);
    hbox7->addWidget(btimel);
    
    // integer spinbox
    QLabel *alabel = new QLabel(tr("Red"));
    QSpinBox *aspinBox = new QSpinBox;
    aspinBox->setRange(0, 255);
    aspinBox->setSingleStep(1);
    aspinBox->setValue(255);
    QLabel *blabel = new QLabel(tr("Green"));
    QSpinBox *bspinBox = new QSpinBox;
    bspinBox->setRange(0, 255);
    bspinBox->setSingleStep(1);
    bspinBox->setValue(255);
    QLabel *clabel = new QLabel(tr("Blue"));
    QSpinBox *cspinBox = new QSpinBox;
    cspinBox->setRange(0, 255);
    cspinBox->setSingleStep(1);
    cspinBox->setValue(255);
    hbox3->addWidget(aspinBox);
    hbox3->addWidget(alabel);
    hbox4->addWidget(bspinBox);
    hbox4->addWidget(blabel);
    hbox5->addWidget(cspinBox);
    hbox5->addWidget(clabel);
    vbox2->addLayout(hbox);
    vbox2->addLayout(hbox7);
    //vbox2->addLayout(hbox3);
    //vbox2->addLayout(hbox4);
    //vbox2->addLayout(hbox5);
    QVBoxLayout* vboxRgb = new QVBoxLayout();  // for R G B
    vboxRgb->addLayout(hbox3);
    vboxRgb->addLayout(hbox4);
    vboxRgb->addLayout(hbox5);
    
    // inserted verticalbox3 part for color preview
    QVBoxLayout *vbox3 = new QVBoxLayout(this);
    vbox3->setAlignment(Qt::AlignHCenter);
    QLabel *prelabel = new QLabel(tr("Color"));
    QLabel *curlabel = new QLabel(tr("Preview"));
    pre = new QPushButton();
    cur = new QPushButton();
    //QPushButton *tmp = new QPushButton(QIcon(":/images/down"), tr(""),this);
    pre->setFixedSize(80,60);
    //pre->setFlat(true);   //invisible at beginning, but will show up later
    cur->setFixedSize(80,60);
    //tmp->setFixedSize(30,30);
    vbox3->setAlignment(pre, Qt::AlignCenter);
    //vbox3->setAlignment(tmp, Qt::AlignCenter);
    vbox3->setAlignment(cur, Qt::AlignCenter);
    //vbox3->addWidget(prelabel);
    //vbox3->addWidget(curlabel);
    vbox3->addWidget(pre);
    //vbox3->addWidget(tmp, Qt::AlignRight);  // remove this arrow button for now
    vbox3->addWidget(cur);
    QHBoxLayout* hboxRgb = new QHBoxLayout();
    hboxRgb->addLayout(vboxRgb);
    hboxRgb->addLayout(vbox3);
    // hboxRgb    
    QHBoxLayout *hbox11 = new QHBoxLayout();
    /*
      QPushButton *color = new QPushButton(QIcon(":/images/color"), tr(""),this);
      color->setFixedSize(150, 150);
      QGraphicsScene *scene = new QGraphicsScene();
      QGraphicsView *view;// = new QGraphicsView();
      QGraphicsPixmapItem item(QPixmap(":/images/color"));
      view->addItem(&item);
      QPixmap img = new QPixmap(":/images/color");
      QLabel *imgl = new QLabel();
      imgl->setPixmap(img);
    */
    ColorWheel* color = new ColorWheel();
    //hbox11->addLayout(vbox3);
    //hbox11->addLayout(hboxRgb);
    vbox2->addLayout(hboxRgb); // R G B preview hbox
    //hbox11->addLayout(vboxSquare);

    // added a line in between the two part
    QFrame *line2 = new QFrame(this);    // <<< this does the trick
    line2->setLineWidth(3);
    line2->setMidLineWidth(2);
    line2->setFrameShape(QFrame::VLine);
    line2->setFrameShadow(QFrame::Raised);
    hbox11->addLayout(direction, Qt::AlignLeft);
    hbox11->addWidget(line2);
    hbox11->addLayout(vbox2, Qt::AlignCenter);
    hbox11->addWidget(color, Qt::AlignRight);
    vbox->addLayout(hbox11);

    
    // for button background color
    QHBoxLayout *hbox8 = new QHBoxLayout();
    for (int i = 0; i < 17; i++) {
        mButton[i] = new QPushButton(this);
        mButton[i]->setFixedSize(31,31);
        //mButton[i][j]->setStyleSheet("QPushButton{color:red;background-color:rgb(200,155,100)}");
        hbox8->addWidget(mButton[i]);
    }
    mButton[0]->setStyleSheet("QPushButton{color:red;background-color:rgb(0,0,0)}");
    mButton[1]->setStyleSheet("QPushButton{color:red;background-color:rgb(255,255,255)}");
    mButton[2]->setStyleSheet("QPushButton{color:red;background-color:rgb(0,255,255)}");
    mButton[3]->setStyleSheet("QPushButton{color:red;background-color:rgb(0,139,139)}");
    mButton[4]->setStyleSheet("QPushButton{color:red;background-color:rgb(255,0,0)}");
    mButton[5]->setStyleSheet("QPushButton{color:red;background-color:rgb(139,0,0)}");
    mButton[6]->setStyleSheet("QPushButton{color:red;background-color:rgb(255,0,255)}");
    mButton[7]->setStyleSheet("QPushButton{color:red;background-color:rgb(139,0,139)}");
    mButton[8]->setStyleSheet("QPushButton{color:red;background-color:rgb(0,128,0)}");
    mButton[9]->setStyleSheet("QPushButton{color:red;background-color:rgb(0,100,0)}");
    mButton[10]->setStyleSheet("QPushButton{color:red;background-color:rgb(255,255,0)}");
    mButton[11]->setStyleSheet("QPushButton{color:red;background-color:rgb(233,150,122)}"); // darkyello, darkSalmon
    mButton[12]->setStyleSheet("QPushButton{color:red;background-color:rgb(0,0,255)}");
    mButton[13]->setStyleSheet("QPushButton{color:red;background-color:rgb(0,0,139)}");
    mButton[14]->setStyleSheet("QPushButton{color:red;background-color:rgb(128,128,128)}");
    mButton[15]->setStyleSheet("QPushButton{color:red;background-color:rgb(169,169,169)}");
    mButton[16]->setStyleSheet("QPushButton{color:red;background-color:rgb(211,211,211)}");
    connect(mButton[0], SIGNAL(released()), this, SLOT(preColorClicked0()));
    connect(mButton[1], SIGNAL(released()), this, SLOT(preColorClicked1()));
    connect(mButton[2], SIGNAL(released()), this, SLOT(preColorClicked2()));
    connect(mButton[3], SIGNAL(released()), this, SLOT(preColorClicked3()));
    connect(mButton[4], SIGNAL(released()), this, SLOT(preColorClicked4()));
    connect(mButton[5], SIGNAL(released()), this, SLOT(preColorClicked5()));
    connect(mButton[6], SIGNAL(released()), this, SLOT(preColorClicked6()));
    connect(mButton[7], SIGNAL(released()), this, SLOT(preColorClicked7()));
    connect(mButton[8], SIGNAL(released()), this, SLOT(preColorClicked8()));
    connect(mButton[9], SIGNAL(released()), this, SLOT(preColorClicked9()));
    connect(mButton[10], SIGNAL(released()), this, SLOT(preColorClicked10()));
    connect(mButton[11], SIGNAL(released()), this, SLOT(preColorClicked11()));
    connect(mButton[12], SIGNAL(released()), this, SLOT(preColorClicked12()));
    connect(mButton[13], SIGNAL(released()), this, SLOT(preColorClicked13()));
    connect(mButton[14], SIGNAL(released()), this, SLOT(preColorClicked14()));
    connect(mButton[15], SIGNAL(released()), this, SLOT(preColorClicked15()));
    connect(mButton[16], SIGNAL(released()), this, SLOT(preColorClicked16()));
    vbox->addLayout(hbox8);

    // myGridLayout part
    //myGridLayout myGrid(12, 6);
    //myGrid.setSpacing(5);
    //mGrid = new myGridLayout(12, 6, this);
    //setLayout(mGrid->ptrGrid);
    
    QGridLayout* grid = new QGridLayout();
    grid->setSpacing(5);
    for (int i = 0; i < 12; ++i ) {
        for (int j = 0; j < 6; ++j ) {
            mButt[i][j] = new QPushButton();
            mButt[i][j]->setFixedSize(40, 40);
            grid->addWidget(mButt[i][j], i, j);
        }
    }
    connect(mButt[0][0], SIGNAL(released()), this, SLOT(gridLayoutClicked00()));   
    connect(mButt[0][1], SIGNAL(released()), this, SLOT(gridLayoutClicked01()));   
    connect(mButt[0][2], SIGNAL(released()), this, SLOT(gridLayoutClicked02()));   
    connect(mButt[0][3], SIGNAL(released()), this, SLOT(gridLayoutClicked03()));   
    connect(mButt[0][4], SIGNAL(released()), this, SLOT(gridLayoutClicked04()));   
    connect(mButt[0][5], SIGNAL(released()), this, SLOT(gridLayoutClicked05()));   
    connect(mButt[1][0], SIGNAL(released()), this, SLOT(gridLayoutClicked10()));   
    connect(mButt[1][1], SIGNAL(released()), this, SLOT(gridLayoutClicked11()));   
    connect(mButt[1][2], SIGNAL(released()), this, SLOT(gridLayoutClicked12()));   
    connect(mButt[1][3], SIGNAL(released()), this, SLOT(gridLayoutClicked13()));   
    connect(mButt[1][4], SIGNAL(released()), this, SLOT(gridLayoutClicked14()));   
    connect(mButt[1][5], SIGNAL(released()), this, SLOT(gridLayoutClicked15()));   
    connect(mButt[2][0], SIGNAL(released()), this, SLOT(gridLayoutClicked20()));   
    connect(mButt[2][1], SIGNAL(released()), this, SLOT(gridLayoutClicked21()));   
    connect(mButt[2][2], SIGNAL(released()), this, SLOT(gridLayoutClicked22()));   
    connect(mButt[2][3], SIGNAL(released()), this, SLOT(gridLayoutClicked23()));   
    connect(mButt[2][4], SIGNAL(released()), this, SLOT(gridLayoutClicked24()));   
    connect(mButt[2][5], SIGNAL(released()), this, SLOT(gridLayoutClicked25()));   
    connect(mButt[3][0], SIGNAL(released()), this, SLOT(gridLayoutClicked30()));   
    connect(mButt[3][1], SIGNAL(released()), this, SLOT(gridLayoutClicked31()));   
    connect(mButt[3][2], SIGNAL(released()), this, SLOT(gridLayoutClicked32()));   
    connect(mButt[3][3], SIGNAL(released()), this, SLOT(gridLayoutClicked33()));   
    connect(mButt[3][4], SIGNAL(released()), this, SLOT(gridLayoutClicked34()));   
    connect(mButt[3][5], SIGNAL(released()), this, SLOT(gridLayoutClicked35()));   
    connect(mButt[4][0], SIGNAL(released()), this, SLOT(gridLayoutClicked40()));   
    connect(mButt[4][1], SIGNAL(released()), this, SLOT(gridLayoutClicked41()));   
    connect(mButt[4][2], SIGNAL(released()), this, SLOT(gridLayoutClicked42()));   
    connect(mButt[4][3], SIGNAL(released()), this, SLOT(gridLayoutClicked43()));   
    connect(mButt[4][4], SIGNAL(released()), this, SLOT(gridLayoutClicked44()));   
    connect(mButt[4][5], SIGNAL(released()), this, SLOT(gridLayoutClicked45()));   
    connect(mButt[5][0], SIGNAL(released()), this, SLOT(gridLayoutClicked50()));   
    connect(mButt[5][1], SIGNAL(released()), this, SLOT(gridLayoutClicked51()));   
    connect(mButt[5][2], SIGNAL(released()), this, SLOT(gridLayoutClicked52()));   
    connect(mButt[5][3], SIGNAL(released()), this, SLOT(gridLayoutClicked53()));   
    connect(mButt[5][4], SIGNAL(released()), this, SLOT(gridLayoutClicked54()));   
    connect(mButt[5][5], SIGNAL(released()), this, SLOT(gridLayoutClicked55()));   
    connect(mButt[6][0], SIGNAL(released()), this, SLOT(gridLayoutClicked60()));   
    connect(mButt[6][1], SIGNAL(released()), this, SLOT(gridLayoutClicked61()));   
    connect(mButt[6][2], SIGNAL(released()), this, SLOT(gridLayoutClicked62()));   
    connect(mButt[6][3], SIGNAL(released()), this, SLOT(gridLayoutClicked63()));   
    connect(mButt[6][4], SIGNAL(released()), this, SLOT(gridLayoutClicked64()));   
    connect(mButt[6][5], SIGNAL(released()), this, SLOT(gridLayoutClicked65()));   
    connect(mButt[7][0], SIGNAL(released()), this, SLOT(gridLayoutClicked70()));   
    connect(mButt[7][1], SIGNAL(released()), this, SLOT(gridLayoutClicked71()));   
    connect(mButt[7][2], SIGNAL(released()), this, SLOT(gridLayoutClicked72()));   
    connect(mButt[7][3], SIGNAL(released()), this, SLOT(gridLayoutClicked73()));   
    connect(mButt[7][4], SIGNAL(released()), this, SLOT(gridLayoutClicked74()));   
    connect(mButt[7][5], SIGNAL(released()), this, SLOT(gridLayoutClicked75()));   
    connect(mButt[8][0], SIGNAL(released()), this, SLOT(gridLayoutClicked80()));   
    connect(mButt[8][1], SIGNAL(released()), this, SLOT(gridLayoutClicked81()));   
    connect(mButt[8][2], SIGNAL(released()), this, SLOT(gridLayoutClicked82()));   
    connect(mButt[8][3], SIGNAL(released()), this, SLOT(gridLayoutClicked83()));   
    connect(mButt[8][4], SIGNAL(released()), this, SLOT(gridLayoutClicked84()));   
    connect(mButt[8][5], SIGNAL(released()), this, SLOT(gridLayoutClicked85()));   
    connect(mButt[9][0], SIGNAL(released()), this, SLOT(gridLayoutClicked90()));   
    connect(mButt[9][1], SIGNAL(released()), this, SLOT(gridLayoutClicked91()));   
    connect(mButt[9][2], SIGNAL(released()), this, SLOT(gridLayoutClicked92()));   
    connect(mButt[9][3], SIGNAL(released()), this, SLOT(gridLayoutClicked93()));   
    connect(mButt[9][4], SIGNAL(released()), this, SLOT(gridLayoutClicked94()));   
    connect(mButt[9][5], SIGNAL(released()), this, SLOT(gridLayoutClicked95()));   
    connect(mButt[10][0], SIGNAL(released()), this, SLOT(gridLayoutClicked100()));   
    connect(mButt[10][1], SIGNAL(released()), this, SLOT(gridLayoutClicked101()));   
    connect(mButt[10][2], SIGNAL(released()), this, SLOT(gridLayoutClicked102()));   
    connect(mButt[10][3], SIGNAL(released()), this, SLOT(gridLayoutClicked103()));   
    connect(mButt[10][4], SIGNAL(released()), this, SLOT(gridLayoutClicked104()));   
    connect(mButt[10][5], SIGNAL(released()), this, SLOT(gridLayoutClicked105()));   
    connect(mButt[11][0], SIGNAL(released()), this, SLOT(gridLayoutClicked110()));   
    connect(mButt[11][1], SIGNAL(released()), this, SLOT(gridLayoutClicked111()));   
    connect(mButt[11][2], SIGNAL(released()), this, SLOT(gridLayoutClicked112()));   
    connect(mButt[11][3], SIGNAL(released()), this, SLOT(gridLayoutClicked113()));   
    connect(mButt[11][4], SIGNAL(released()), this, SLOT(gridLayoutClicked114()));   
    connect(mButt[11][5], SIGNAL(released()), this, SLOT(gridLayoutClicked115()));   
    setLayout(grid);

    // try to set a frame in the grid
    QFrame* line[28];
    for (int i = 0; i < 28; ++i) {        
        line[i] = new QFrame();    // <<< this does the trick
        line[i]->setLineWidth(3);
        line[i]->setMidLineWidth(2);
        line[i]->setFrameShadow(QFrame::Raised);
        line[i]->setFrameShape(QFrame::VLine);
    }
    for (int i = 20; i < 28; ++i) {        
        line[i] = new QFrame();    // <<< this does the trick
        line[i]->setLineWidth(3);
        line[i]->setMidLineWidth(2);
        line[i]->setFrameShadow(QFrame::Raised);
        line[i]->setFrameShape(QFrame::HLine);
    }
    for (int i = 0; i < 10; ++i) {        
        grid->addWidget(line[i], 1+i, 1, Qt::AlignLeft);
    }
    for (int i = 0; i < 10; ++i) {        
        grid->addWidget(line[i+10], 1+i, 4, Qt::AlignRight);
    }
    for (int i = 20; i < 24; ++i) {        
        grid->addWidget(line[i], 1, i-19, Qt::AlignTop);
    }
    for (int i = 24; i < 28; ++i) {        
        grid->addWidget(line[i], 10, i-23, Qt::AlignBottom);
    }
    
    // added a line in between the two part
    QFrame *linea1 = new QFrame(this);    // <<< this does the trick
    linea1->setLineWidth(3);
    linea1->setMidLineWidth(2);
    linea1->setFrameShape(QFrame::VLine);
    linea1->setFrameShadow(QFrame::Raised);
    //linea1->setPalette(QPalette(QColor(255, 0, 0)));  // here
    hbox9->addLayout(grid);
    hbox9->addWidget(linea1);
    hbox9->addLayout(vbox);
}

void Buttons::addFrame(QGridLayout* grid) {
    QFrame* line[28];
    for (int i = 0; i < 28; ++i) {        
        line[i] = new QFrame();    // <<< this does the trick
        line[i]->setLineWidth(3);
        line[i]->setMidLineWidth(2);
        line[i]->setFrameShadow(QFrame::Raised);
        line[i]->setFrameShape(QFrame::VLine);
    }
    for (int i = 20; i < 28; ++i) {        
        line[i] = new QFrame();    // <<< this does the trick
        line[i]->setLineWidth(3);
        line[i]->setMidLineWidth(2);
        line[i]->setFrameShadow(QFrame::Raised);
        line[i]->setFrameShape(QFrame::HLine);
    }
    for (int i = 0; i < 10; ++i) {        
        grid->addWidget(line[i], i, 0, Qt::AlignLeft);
    }
    for (int i = 0; i < 10; ++i) {        
        grid->addWidget(line[i+10], i, 3, Qt::AlignRight);
    }
    for (int i = 20; i < 24; ++i) {        
        grid->addWidget(line[i], 0, i-20, Qt::AlignTop);
    }
    for (int i = 24; i < 28; ++i) {        
        grid->addWidget(line[i], 9, i-24, Qt::AlignBottom);
    }
}

void Buttons::setColor(QPushButton* ptrBtn[][6], int i, int j) {
    QPalette pal;
    pal = ptrBtn[i][j]->palette();
    pal.setColor(QPalette::Button, newColor);
    ptrBtn[i][j]->setPalette(pal);
    ptrBtn[i][j]->setAutoFillBackground(true);
    // set newColor to be curColor
    curColor = newColor;
}
void Buttons::setColorToDefault(QPushButton* ptrBtn) {
    QPalette pal;
    pal = ptrBtn->palette();
    pal.setColor(QPalette::Button, QColor::fromRgb(211,211,211));  // light grey
    ptrBtn->setPalette(pal);
    ptrBtn->setAutoFillBackground(true);
}
void Buttons::setColor(QPushButton* ptrBtn) {
    QPalette pal;
    pal = ptrBtn->palette();
    pal.setColor(QPalette::Button, newColor);
    ptrBtn->setPalette(pal);
    ptrBtn->setAutoFillBackground(true);
    // set newColor to be curColor
    curColor = newColor;
}

void Buttons::gridLayoutClicked00(){setColor(mButt,0,0);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked01(){setColor(mButt,0,1);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked02(){setColor(mButt,0,2);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked03(){setColor(mButt,0,3);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked04(){setColor(mButt,0,4);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked05(){setColor(mButt,0,5);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked10(){setColor(mButt,1,0);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked11(){setColor(mButt,1,1);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked12(){setColor(mButt,1,2);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked13(){setColor(mButt,1,3);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked14(){setColor(mButt,1,4);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked15(){setColor(mButt,1,5);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked20(){setColor(mButt,2,0);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked21(){setColor(mButt,2,1);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked22(){setColor(mButt,2,2);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked23(){setColor(mButt,2,3);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked24(){setColor(mButt,2,4);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked25(){setColor(mButt,2,5);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked30(){setColor(mButt,3,0);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked31(){setColor(mButt,3,1);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked32(){setColor(mButt,3,2);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked33(){setColor(mButt,3,3);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked34(){setColor(mButt,3,4);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked35(){setColor(mButt,3,5);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked40(){setColor(mButt,4,0);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked41(){setColor(mButt,4,1);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked42(){setColor(mButt,4,2);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked43(){setColor(mButt,4,3);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked44(){setColor(mButt,4,4);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked45(){setColor(mButt,4,5);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked50(){setColor(mButt,5,0);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked51(){setColor(mButt,5,1);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked52(){setColor(mButt,5,2);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked53(){setColor(mButt,5,3);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked54(){setColor(mButt,5,4);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked55(){setColor(mButt,5,5);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked60(){setColor(mButt,6,0);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked61(){setColor(mButt,6,1);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked62(){setColor(mButt,6,2);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked63(){setColor(mButt,6,3);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked64(){setColor(mButt,6,4);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked65(){setColor(mButt,6,5);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked70(){setColor(mButt,7,0);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked71(){setColor(mButt,7,1);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked72(){setColor(mButt,7,2);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked73(){setColor(mButt,7,3);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked74(){setColor(mButt,7,4);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked75(){setColor(mButt,7,5);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked80(){setColor(mButt,8,0);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked81(){setColor(mButt,8,1);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked82(){setColor(mButt,8,2);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked83(){setColor(mButt,8,3);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked84(){setColor(mButt,8,4);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked85(){setColor(mButt,8,5);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked90(){setColor(mButt,9,0);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked91(){setColor(mButt,9,1);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked92(){setColor(mButt,9,2);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked93(){setColor(mButt,9,3);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked94(){setColor(mButt,9,4);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked95(){setColor(mButt,9,5);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked100(){setColor(mButt,10,0);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked101(){setColor(mButt,10,1);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked102(){setColor(mButt,10,2);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked103(){setColor(mButt,10,3);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked104(){setColor(mButt,10,4);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked105(){setColor(mButt,10,5);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked110(){setColor(mButt,11,0);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked111(){setColor(mButt,11,1);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked112(){setColor(mButt,11,2);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked113(){setColor(mButt,11,3);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked114(){setColor(mButt,11,4);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void Buttons::gridLayoutClicked115(){setColor(mButt,11,5);setColor(pre);curColor = newColor;setColorToDefault(cur);}

void Buttons::preColorClicked(int idx) {
    newColor = getPreColor(idx);
    setColor(cur);
}

void Buttons::printH(QColor color){ // LightSkyBlue 135,206,250
    for (int i = 0; i < 7; ++i) {
        setColor(mBut1, i, 0, color);
        setColor(mBut1, i, 3, color);
    }
    setColor(mBut1, 3, 1, color);
    setColor(mBut1, 3, 2, color);
}
void Buttons::printM(QColor color){ // 255,215,0
    for (int i = 0; i < 7; ++i) {
        setColor(mBut2, i, 0, color);
        setColor(mBut2, i, 3, color);
    }
    for (int i = 1; i < 3; ++i) {        
        setColor(mBut2, 0, i, color);
        setColor(mBut2, 3, i, color);
        setColor(mBut2, 6, i, color);
    }
}
void Buttons::printE(QColor color){
    for (int i = 0; i < 7; ++i) 
        setColor(mBut5, i, 0, color);
    for (int i = 0; i < 4; ++i) {        
        setColor(mBut5, 0, i, color);
        setColor(mBut5, 6, i, color);
    }
    setColor(mBut5, 3, 1, color);
    setColor(mBut5, 3, 2, color);
}
void Buttons::printR(QColor color){
    for (int i = 0; i < 7; ++i) 
        setColor(mBut3, i, 0, color);
    for (int i = 0; i < 4; ++i)
        setColor(mBut3, i, 3, color);
    for (int i = 1; i < 3; ++i) {        
        setColor(mBut3, 0, i, color);
        setColor(mBut3, 3, i, color);
    }
    setColor(mBut3, 4, 1, color);
    setColor(mBut3, 5, 2, color);
    setColor(mBut3, 6, 3, color);
}
void Buttons::printP(QColor color){
    for (int i = 0; i < 7; ++i)
        setColor(mBut4, i, 0, color);
    for (int i = 0; i < 4; ++i)
        setColor(mBut4, i, 3, color);
    for (int i = 1; i < 3; ++i) {        
        setColor(mBut4, 0, i, color);
        setColor(mBut4, 3, i, color);
    }
}

QColor Buttons::getPreColor(int idx) {
    QColor color;
    color = mButton[idx]->palette().color(QPalette::Button);
    return color;
}
