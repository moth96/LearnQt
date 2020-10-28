#include <QApplication>
#include <QWidget> //窗口控制基类
#include <QPushButton>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget w;
    //设置标题
    w.setWindowTitle(QString("Hello Qt"));
    //w.show();

    //设置按钮
    //QPushButton b;
    //给按钮设置内容
    //b.setText("^_^");
    //b.show();

    //如果不指定父对象，对象和对象（窗口和窗口）没有关系
    //a指定b为它的父对象，a放在b的上面
    //指定父对象，有两种方式：
    //              1.setParent
    //              2.通过构造函数传参
    //指定父对象，只需要父对象显示，上面的子对象自动显示

    //设置按钮
    QPushButton b;
    //给按钮设置内容
    b.setText("^_^");
    //指定父对象
    b.setParent(&w);
    //移动按钮
    b.move(100,100);
    //b.show();

    QPushButton b1(&w);
    b1.setText("abc");

    w.show();

    app.exec();
    return 0;
}
