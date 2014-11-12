/*
 * Tower Animator Senior Design Project
 * Group Members:
 *      Heyan Huang
 *      Emeth Thompson
 *      Paul Bailey
 *      Ranger Adams
 *      Matthew Brown
 */
#include <QApplication>
#include <QTextEdit>
#include <QSplitter>
#include <QVBoxLayout>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <cstring>
#include <iostream>

//#include "mainwindow.h"
#include "myGridLayout.h"
#include "buttons.h"
//#include "verticalbox.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    /*
    MainWindow win;
    win.show();
    */

        // for buttons for final
    Buttons button;
    //viewer.rootContext()->setContextProperty(QStringLiteral("_btnObject"), &sc);
    button.resize(290, 170);
    button.move(300, 300);  
    button.setWindowTitle("Tower iLLuminati");
    button.show();


    /*
    // works for 12x6 grids
    myGridLayout window(10,4);
    window.printH(QColor::fromRgb(135,206,250));

    window.printE(QColor::fromRgb(255, 105, 180));
    window.printR(QColor::fromRgb(240,128,128)); // light red
    window.printP(QColor::fromRgb(176, 196, 222));
    window.printM(QColor::fromRgb(255,215,0));

    window.move(300, 300);
    window.show();
    */
    /*
      // works for one graphics
    QGraphicsScene scene;
    QGraphicsView view(&scene);
    QGraphicsView view2(&scene);
    QGraphicsPixmapItem item(QPixmap(":/images/color"));
    QGraphicsPixmapItem item2(QPixmap(":/images/h"));
    scene.addItem(&item);
    scene.addItem(&item2);
    view.show();
*/
    /*
    QApplication a(argc, argv);
    QTextEdit te ("blah blah blah blah blah blah blah blah blah blah blah blah");
    te.show();
    cout << te.document()->size().height() << endl;
    cout << te.document()->size().width() << endl;
    cout <<  te.size().height() << endl;
    cout <<  te.size().width() << endl;
    // and you can resize then how do you like, e.g. :
    te.resize(te.document()->size().width(), te.document()->size().height() + 10);
    */

    
    /*
    VerticalBox window;
    window.resize(240, 230);
    window.move(300, 300);
    window.setWindowTitle("VerticalBox");
    window.show();

       QtColorPicker window;
    window.insertColor(QColor("white"), "White");
    window.insertColor(QColor("black"), "Black");
    window.insertColor(QColor("green"), "Green");
    window.insertColor(QColor("darkGreen"), "Dark green");
    window.insertColor(QColor("blue"), "Blue");
    window.insertColor(QColor("darkBlue"), "Dark blue");
    window.insertColor(QColor("cyan"), "Cyan");
    window.insertColor(QColor("darkCyan"), "Dark cyan");
    window.insertColor(QColor("magenta"), "Magenta");
    window.insertColor(QColor("darkMagenta"), "Dark magenta");
    window.insertColor(QColor("yellow"), "Yellow");
    window.insertColor(QColor("grey"), "Grey");
    window.show();
   */    
    /*
      myGridLayout* myptr = &window;

      QWidget *container = new QWidget;
      QHBoxLayout *layout = new QHBoxLayout;
      QVBoxLayout *container_layout = new QVBoxLayout;

      QSplitter *split1 = new QSplitter;
      QTextEdit *editor2 = new QTextEdit;
      split1->addWidget(myptr);
      split1->addWidget(editor2);

      container_layout->addWidget(split1);
      container->setLayout(container_layout);
    */
    return app.exec();
}

//#include "moc_buttons.cpp"
