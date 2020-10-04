#include "mainwindow.h"
#include "ui_mainwindow.h" // xx.ui文件编译后自动生成头ui_xx.h头文件

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //通过ui寻找控件
    //添加资源文件 到项目中
    //使用资源文件 " : + 前缀名 + 文件名 "
    ui->actionNew->setIcon(QIcon(":/Image/Luffy.png"));
    ui->actionOpen->setIcon(QIcon(":/Image/OnePiece.png")); //资源文件
    //ui->actionNew->setIcon(QIcon("E:/Image/Luffy.png")); //本地文件

}

MainWindow::~MainWindow()
{
    delete ui;
}
