#include <QtWidgets>
#include <string>
#include "mainwindow.h"
#include "instruction.h"

MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent)
{

    button = new QPushButton(tr("Ready"));
    button2 = new QPushButton(tr("Instruction"));
    button3 = new QPushButton(tr("Reset score"));

    score1 = new QLabel("0");
    score2 = new QLabel("0");
    dots = new QLabel(":");

    mainLayout->addWidget(button,0,0);
    mainLayout->addWidget(button2,0,4);
    mainLayout->addWidget(button3,0,2);
    mainLayout->addWidget(score1,0,8);
    mainLayout->addWidget(dots,0,9);
    mainLayout->addWidget(score2,0,10);

    connect(button, SIGNAL(clicked()), this, SLOT(readyButtonClicked()));
    connect(button2, SIGNAL(clicked()), this, SLOT(instructionButtonClicked()));
    connect(button3, SIGNAL(clicked()), this, SLOT(resetButtonClicked()));

    imgDisplayLabel = new QLabel("");
    imgDisplayLabel2 = new QLabel("");
    inputImg = new QImage("resources/doggo1.jpg");
    icon.addPixmap(QPixmap::fromImage(*inputImg), QIcon::Normal, QIcon::On);
    size = QSize(200,200);
    QPixmap pixmap = icon.pixmap(size, QIcon::Normal, QIcon::On);
    imgDisplayLabel->setPixmap(pixmap);
    mainLayout->addWidget(imgDisplayLabel,1,0);
    imgDisplayLabel2->setPixmap(pixmap);
    mainLayout->addWidget(imgDisplayLabel2,1,10);

    setWindowTitle(tr("Paper, rock, scissors!"));
    setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
    delete button;
    delete button2;
    delete button3;
    delete score1;
    delete score2;
    delete dots;
    delete inputImg;
    delete imgDisplayLabel;
    delete inputImg2;
    delete imgDisplayLabel2;
    delete mainLayout;
}

int MainWindow::countResult() const {
    if (s1 == 1){
        if (s2 == 1){
            return 0;
        }
        if (p2 == 1){
            return 1;
        }
        if (r2 == 1){
            return 2;
        }
    }
    if (p1 == 1){
        if (s2 == 1){
            return 2;
        }
        if (p2 == 1){
            return 0;
        }
        if (r2 == 1){
            return 1;
        }
    }
    if (r1 == 1){
        if (s2 == 1){
            return 1;
        }
        if (p2 == 1){
            return 2;
        }
        if (r2 == 1){
            return 0;
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_A)
    {
        inputImg = new QImage("resources/paper.png");
        p1 = 1;
        s1 = 0;
        r1 = 0;
    }

    if(event->key() == Qt::Key_S)
    {
        inputImg = new QImage("resources/rock.png");
        r1 = 1;
        s1 = 0;
        p1 = 0;
    }

    if(event->key() == Qt::Key_D)
    {
        inputImg = new QImage("resources/scissors.png");
        s1 = 1;
        p1 = 0;
        r1 = 0;
    }




    if(event->key() == Qt::Key_J)
    {
        inputImg2 = new QImage("resources/paper.png");
        p2 = 1;
        s2 = 0;
        r2 = 0;
    }

    if(event->key() == Qt::Key_K)
    {
        inputImg2 = new QImage("resources/rock.png");
        r2 = 1;
        s2 = 0;
        p2 = 0;
    }

    if(event->key() == Qt::Key_L)
    {
        inputImg2 = new QImage("resources/scissors.png");
        s2 = 1;
        p2 = 0;
        r2 = 0;
    }

}



void MainWindow::readyButtonClicked() {
    int result = countResult();
    if (result == 1){
        points1++;
        QString s = QString::number(points1);
        score1->setText(s);
    }
    else if (result == 2){
        points2++;
        QString s = QString::number(points2);
        score2->setText(s);
    }
    else{
        points1++;
        points2++;
        QString s = QString::number(points1);
        score1->setText(s);
        s = QString::number(points2);
        score2->setText(s);
    }
    imgDisplayLabel->setPixmap(QPixmap::fromImage(*inputImg));
    imgDisplayLabel2->setPixmap(QPixmap::fromImage(*inputImg2));


}

void MainWindow::resetButtonClicked() {
    score1->setText("0");
    score2->setText("0");
    points1 = 0;
    points2 = 0;
}

void MainWindow::instructionButtonClicked() {
    instruction.show();
}

