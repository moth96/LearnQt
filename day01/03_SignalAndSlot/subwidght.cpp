#include "subwidght.h"

SubWidght::SubWidght(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("小弟");
    b.setParent(this);
    b.setText("切换到主窗口");

    connect(&b, &QPushButton::clicked, this, &SubWidght::sendSlot);

    resize(400,300);
}

void SubWidght::sendSlot()
{
    emit mySignal();
    emit mySignal(250,"我是子窗口");
}
