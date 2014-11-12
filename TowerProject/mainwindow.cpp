#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QDialogButtonBox>
#include <QtGui>
#include <QSplitter>
#include <QTextEdit>
#include <QMainWindow>

#include "mainwindow.h"
//#include "myGridLayout.h"
#include "buttons.h"

class frame {
public:
    frame();
    virtual ~frame();
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    //MainWindow::MainWindow() {
    setWindowTitle(tr("Tower-iLLuminati Main Window"));

    // for menubar
    openAction = new QAction(QIcon(":/images/doc-open"), tr("&Open..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing .wav file"));
    //connect(openAction, &QAction::triggered, this, &MainWindow::open);
    connect(openAction, &QAction::triggered, this, &MainWindow::open);

    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAction);
    // add more menu bottons here in the first line
    // Edit
    QMenu *edit = menuBar()->addMenu(tr("&Edit"));
    // Insert
    QMenu *insert = menuBar()->addMenu(tr("&Insert"));
    // Animate
    QMenu *animate = menuBar()->addMenu(tr("&Animate"));
    // View
    QMenu *view = menuBar()->addMenu(tr("&View"));
    // Help
    QMenu *help = menuBar()->addMenu(tr("&Help"));
    // About
    QMenu *about = menuBar()->addMenu(tr("&About"));

    openAction2 = new QAction(QIcon(":/images/doc-close"), tr("&Close..."), this);
    openAction3 = new QAction(QIcon(":/images/searchI"), tr("&Search..."), this);
    openAction4 = new QAction(QIcon(":/images/copyI"), tr("&Copy..."), this);
    openAction5 = new QAction(QIcon(":/images/pasteI"), tr("&Paste..."), this);

    openAction2->setShortcuts(QKeySequence::Close);
    openAction2->setStatusTip(tr("Close an existing .wav file"));

    toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);
    toolBar->addAction(openAction2);
    toolBar->addAction(openAction3);
    toolBar->addAction(openAction4);
    toolBar->addAction(openAction5);


    //Buttons button(this);
    //button = new Buttons(this);
    /*
    button.resize(290, 170);
    button.move(300, 300);  
    //button.setWindowTitle("Tower iLLuminati");
    button.show();
    */
}

MainWindow::~MainWindow() {
}
void MainWindow::open() {
    QMessageBox::information(this, tr("Information"), tr("Open"));
}
