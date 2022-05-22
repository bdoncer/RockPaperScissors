#ifndef TIC_TAC_TOE_INSTRUCTION_H
#define TIC_TAC_TOE_INSTRUCTION_H

#include <QMainWindow>
#include <QDialog>
#include <QGridLayout>
#include <QScrollArea>
#include <QLabel>
#include <QImage>
#include <QWidget>

class QPushButton;
class QIcon;


class Instruction : public QWidget {
Q_OBJECT

public:
    explicit Instruction(QWidget *parent = 0);
    ~Instruction();


private:
    QIcon icon;
    QSize size;
    QImage *inputImg;
    QLabel *imgDisplayLabel;
    QGridLayout *mainLayout = new QGridLayout;
};


#endif //TIC_TAC_TOE_INSTRUCTION_H
