#ifndef SUBWIDGHT_H
#define SUBWIDGHT_H

#include <QWidget>
#include <QPushButton>

class SubWidght : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidght(QWidget *parent = nullptr);

    void sendSlot();

signals:
    //信号必须有signal关键字来声明
    //信号没有返回值，但可以有参数
    //信号就是函数的声明，只需声明，无需定义
    //使用 emit mySignal();
    //信号可以重载

    void mySignal();
    void mySignal(int, QString);



private:
    QPushButton b;
};

#endif // SUBWIDGHT_H
