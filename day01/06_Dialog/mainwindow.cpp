#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *mBar = menuBar();
    setMenuBar(mBar);
    QMenu *menu = mBar->addMenu("对话框");
    QAction *p1 = menu->addAction("模态对话框");
    connect(p1, &QAction::triggered,
            [=]()
            {
                QDialog dlg;
                dlg.exec();
                qDebug() << "111";
            }
            );

    QAction *p2 = menu->addAction("非模态对话框");
    connect(p2, &QAction::triggered,
            [=]()
            {
                //一闪而过
                //QDialog dlg;
                //dlg.show();
                //qDebug() << "111";

                //容易内存泄漏
                //QDialog *p = new QDialog(this);
                //p->show();
                QDialog *p = new QDialog;
                //设置关闭后释放
                p->setAttribute(Qt::WA_DeleteOnClose);
                p->show();
            }
            );

    QAction *p3 = menu->addAction("关于对话框");
    connect(p3, &QAction::triggered,
            [=]()
            {
                QMessageBox::about(this, "about", "关于Qt");
            }
            );

    QAction *p4 = menu->addAction("问题对话框");
    connect(p4, &QAction::triggered,
            [=]()
            {
                int res = QMessageBox::question(this, "question", "Are you ok?"
                                                ,QMessageBox::Ok |
                                                QMessageBox::Yes |
                                                QMessageBox::No);
                switch (res)
                {
                case QMessageBox::Yes:
                    qDebug() << "I am ok";
                    break;
                case QMessageBox::No:
                    qDebug() << "I am bad";
                    break;
                default:
                    break;
                }
            }
            );

    QAction *p5 = menu->addAction("文件对话框");
    connect(p5, &QAction::triggered,
            [=]()
            {
                QString path = QFileDialog::getOpenFileName(
                            this,
                            "open",
                            "../",
                            "source(*.cpp *.h);;"
                            "Text(*.txt);;"
                            "all(*.*)"

                            );
                qDebug() << path;
            }
            );

}

MainWindow::~MainWindow()
{
}

