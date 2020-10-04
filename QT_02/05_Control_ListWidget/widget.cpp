#include "widget.h"
#include "ui_widget.h" // ui界面编译生成的头文件 ui_xxx.h
#include <QDebug>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    // listWidget文本框
    // 文本框添加文本
    // 方式一：QListWidgetItem list文本内容
    QListWidgetItem *item = new QListWidgetItem("锄禾日当午");
    //设置对齐方式
    item->setTextAlignment(Qt::AlignHCenter);
    ui->listWidget->addItem(item);

    // 方式二：QStringList ===  QList<QString>
    QStringList list;
    list << "锄禾日当午"
         << "汗滴禾下土"
         << "谁知盘中餐"
         << "粒粒皆辛苦";

    ui->listWidget->addItems(list);
}

Widget::~Widget() { delete ui; }
