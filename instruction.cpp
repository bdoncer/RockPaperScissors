#include <QtWidgets>
#include <string>
#include "instruction.h"

Instruction::Instruction(QWidget *parent) :
        QWidget(parent)
{
    imgDisplayLabel = new QLabel("");
    inputImg = new QImage("resources/instruction.png");
    icon.addPixmap(QPixmap::fromImage(*inputImg), QIcon::Normal, QIcon::On);
    size = QSize(600,300);
    QPixmap pixmap = icon.pixmap(size, QIcon::Normal, QIcon::On);
    imgDisplayLabel->setPixmap(pixmap);
    mainLayout->addWidget(imgDisplayLabel,1,0);
    setWindowTitle(tr("Instruction"));
    setLayout(mainLayout);
}

Instruction::~Instruction() {
    delete imgDisplayLabel;
    delete inputImg;
    delete mainLayout;
}


