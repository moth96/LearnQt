#include "widget.h"

//QApplication应用程序类
//Qt头文件没有.h
//头文件和类名一样
#include <QApplication>

int main(int argc, char *argv[])
{
    //有且只有一个应用程序类的对象
    QApplication a(argc, argv);

    //Widget继承于QWidget，QWidget是一个窗口基类
    //w是一个窗口
    Widget w;

    //显示窗口
    w.show();

    //a.exec() 让程序一直执行，等待用户操作
    return a.exec();
}
