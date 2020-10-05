#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // widget.ui中 mywidget控件 被升格为自定义的SmallWidget控件
    //点击设置 到一半的位置
    connect(ui->btnSet,&QPushButton::clicked,[=](){
        ui->mywidget->setValue(50);
    });

    //点击获取，拿到当前值
    connect(ui->btnGet,&QPushButton::clicked,[=](){
        qDebug () << "当前值为：" << ui->mywidget->getValue();
    });
}

Widget::~Widget()
{
    delete ui;
}
