#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "subwidght.h" //子窗口头文件

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

public slots:
    void MySlot();

    void changeWin();

    void dealSub();

    void dealSlot(int, QString);

private:
    QPushButton b1;
    QPushButton *b2;
    QPushButton b3;

    SubWidght w;

};
#endif // MAINWIDGET_H
