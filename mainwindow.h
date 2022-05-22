//
// Created by bdoncer on 14.05.22.
//

#ifndef TIC_TAC_TOE_MAINWINDOW_H
#define TIC_TAC_TOE_MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QGridLayout>
#include <QScrollArea>
#include <QLabel>
#include <QImage>
#include <QWidget>
#include "instruction.h"

class QPushButton;
class QTextBrowser;
class QPlainTextEdit;
class QIcon;


class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QPushButton* button;
    QPushButton* button2;
    QPushButton* button3;
    QLabel *score1;
    QLabel *score2;
    QLabel *dots;
    QIcon icon;
    QSize size;
    QImage* inputImg;
    QLabel* imgDisplayLabel;
    QImage* inputImg2;
    QLabel* imgDisplayLabel2;
    QGridLayout *mainLayout = new QGridLayout;
    int s1 = 0;
    int s2 = 0;
    int p1 = 0;
    int p2 = 0;
    int r1 = 0;
    int r2 = 0;
    int points1 = 0;
    int points2 = 0;
    Instruction instruction;

private slots:
    void readyButtonClicked();
    void resetButtonClicked();
    void instructionButtonClicked();

protected:
    void keyPressEvent(QKeyEvent *event);
    int countResult() const;
};

#endif //TIC_TAC_TOE_MAINWINDOW_H
