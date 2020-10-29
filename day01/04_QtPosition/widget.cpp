#include "widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //对于父窗口，坐标系统相对于屏幕而言
    //原点，屏幕左上角
    //x:往右递增
    //y:往下递增
    move(100,100);


    //对于父窗口，坐标系统相对于父窗口而言
    //原点，窗口左上角
    //x:往右递增
    //y:往下递增
    QPushButton *b1 = new QPushButton(this);
    b1->setText("0_0");
    b1->move(100,100);
    b1->resize(200,100);

    QPushButton *b2 = new QPushButton(b1);
    b2->setText("@_@");
    b2->move(50,20);
    //b2->resize(10,10);
}

Widget::~Widget()
{
}

