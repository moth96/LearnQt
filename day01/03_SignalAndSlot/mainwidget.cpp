#include "mainwidget.h"
#include <QPushButton>
#include <QDebug>   //打印

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

    setWindowTitle("老大");

    b3.setParent(this);
    b3.setText("切换到子窗口");
    b3.move(50,50);

    //显示子窗口
    //w.show();

    connect(&b3, &QPushButton::released, this, &MainWidget::changeWin);

    //处理子窗口的信号
    //函数指针解决二义性
    void (SubWidght::*funSignal)() = &SubWidght::mySignal;
    connect(&w, funSignal, this, &MainWidget::dealSub);

    void (SubWidght::*testSignal)(int, QString) = &SubWidght::mySignal;
    connect(&w, testSignal, this, &MainWidget::dealSlot);

    //Qt4信号连接
    //Qt4槽函数必须有slots关键字来修饰
    //connect(&w, SIGNAL(mySignal()), this, SLOT(dealSub()));

    //connect(&w, SIGNAL(mySignal(int, QString)), this, SLOT(dealSlot(int, QString)));

    // SIGNAL SLOT 将函数名字 -> 字符串, 不进行错误检测
    // 尽量不用

    //Lambda表达式, 匿名函数对象
    //C++11增加的新特性, 项目文件: CONFIG += C++11
    //Qt配合信号一起使用, 非常方便

    QPushButton *b4 = new QPushButton(this);
    b4->setText("Lambda表达式");
    b4->move(150,150);

    connect(b4, &QPushButton::released,
            []()
            {
                qDebug() << "111111";
            });

    //设置窗口大小
    resize(400,300);
}

void MainWidget::dealSlot(int a, QString str)
{
    qDebug() << a << str;
}

void MainWidget::MySlot()
{
    b2->setText("123");
}

void MainWidget::changeWin()
{
    //子窗口显示
    w.show();
    //本窗口隐藏
    this->hide();
}

void MainWidget::dealSub()
{
    //子窗口隐藏
    w.hide();
    //本窗口显示
    this->show();
}

MainWidget::~MainWidget()
{
}
