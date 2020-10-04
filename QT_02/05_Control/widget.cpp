#include "widget.h"
#include "ui_widget.h" // ui界面编译生成的头文件 ui_xxx.h
#include <QDebug>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    //单选按钮 默认选中 男
    ui->rBtnMan->setChecked(true);

    //点击女的 就打印选中了
    // connect 连接后自动监听
    connect(ui->rBtnWoman, &QRadioButton::clicked,
            [=]() { qDebug() << "选中女的了！"; });

    //多选框  选中后打印内容
    //状态   选中:2    未选中:0   半选tristate:1
    connect(ui->checkBox, &QCheckBox::stateChanged,
            [=](int state) { qDebug() << state; });

}

Widget::~Widget() { delete ui; }
