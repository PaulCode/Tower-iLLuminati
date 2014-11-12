#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTime>
#include <QTimeEdit>
#include <QComboBox>

#include <QDoubleSpinBox>
#include "verticalbox.h"

VerticalBox::VerticalBox(QWidget *parent)
    : QWidget(parent) {
    QVBoxLayout *vbox = new QVBoxLayout(this);

    QHBoxLayout *hbox = new QHBoxLayout();
    QHBoxLayout *hbox2 = new QHBoxLayout();
    QHBoxLayout *hbox3 = new QHBoxLayout();
    QHBoxLayout *hbox4 = new QHBoxLayout();
    QHBoxLayout *hbox5 = new QHBoxLayout();
    vbox->setSpacing(1);

    // two time boxes
    /*
    QLabel *atimel = new QLabel;
    QComboBox *comBox = new QComboBox;
    comBox->addItem("yyyy-MM-dd hh:mm:ss (zzz 'ms')");
    comBox->addItem("hh:mm:ss MM/dd/yyyy");
    comBox->addItem("hh:mm:ss dd/MM/yyyy");
    comBox->addItem("hh:mm:ss");
    comBox->addItem("hh:mm ap");
    connect(comBox, SIGNAL(activated(QString)), this, SLOT(setFormatString(QString)));
    */    
    QLabel *atimel = new QLabel;
    QTimeEdit *atimeEdit = new QTimeEdit(QTime::currentTime());
    atimeEdit->setTimeRange(QTime(0, 0, 0, 0), QTime(23, 59, 0, 0));
    atimel->setText(tr("Frame Start Time"));
    QLabel *btimel = new QLabel;
    QTimeEdit *btimeEdit = new QTimeEdit(QTime::currentTime());
    btimeEdit->setTimeRange(QTime(0, 0, 0, 0), QTime(23, 59, 0, 0));
    btimel->setText(tr("Increment Amount"));

    hbox->addWidget(atimeEdit);
    hbox->addWidget(atimel);
    hbox2->addWidget(btimeEdit);
    hbox2->addWidget(btimel);

    // integer spinbox
    QLabel *alabel = new QLabel(tr("R"));
    QSpinBox *aspinBox = new QSpinBox;
    aspinBox->setRange(0, 255);
    aspinBox->setSingleStep(1);
    aspinBox->setValue(255);
    QLabel *blabel = new QLabel(tr("G"));
    QSpinBox *bspinBox = new QSpinBox;
    bspinBox->setRange(0, 255);
    bspinBox->setSingleStep(1);
    bspinBox->setValue(255);
    QLabel *clabel = new QLabel(tr("B"));
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

    vbox->addLayout(hbox);
    vbox->addLayout(hbox2);
    vbox->addLayout(hbox3);
    vbox->addLayout(hbox4);
    vbox->addLayout(hbox5);
        
    setLayout(vbox);
}
