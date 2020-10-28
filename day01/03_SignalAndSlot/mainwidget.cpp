#include "mainwidget.h"
#include <QPushButton>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    b1.setParent(this);
    b1.setText("close");
    b1.move(100,100);

    b2 = new QPushButton(this);
    b2->setText("ABC");

    //&b1： 信号发出者，指针类型
    //&QPushButton::pressed: 处理信号, &发送者的类名::信号名字
    //this: 信号接收者
    //&MainWidgets::close 槽函数,信号处理函数 &接收的类名::槽函数的名字
    connect(&b1, &QPushButton::pressed, this, &MainWidget::close);

    //自定义槽,普通函数的用法
    //Qt5: 任意的成员函数，普通全局函数，静态函数
    //槽函数需要和信号一致(参数,返回值)
    //由于信号都是没有返回值的，所以槽函数一定没有返回值
    connect(b2, &QPushButton::released, this, &MainWidget::MySlot);

    connect(b2, &QPushButton::released, &b1, &QPushButton::hide);

    //信号：短信
    //槽函数：接收短信的手机
}

void MainWidget::MySlot()
{
    b2->setText("123");
}

MainWidget::~MainWidget()
{
}
