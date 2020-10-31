#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //通过ui控制
    ui->button1->setText("123");
    //connect(ui->button1, &QPushButton::clicked, this, &MainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

