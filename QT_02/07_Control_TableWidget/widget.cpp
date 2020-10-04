#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);

  // QTableWidget控件使用
  //告诉控件 一共有多少列
  QStringList list;
  list << "姓名"
       << "性别"
       << "年龄";
  // 设置列数
  ui->tableWidget->setColumnCount(list.size());

  //设置水平头
  ui->tableWidget->setHorizontalHeaderLabels(list);

  //设置行数
  ui->tableWidget->setRowCount(5);

  //设置正文
  // ui->tableWidget->setItem(0,0,new QTableWidgetItem("亚瑟"));  // new匿名对象

  //准备数据
  QStringList nameList;
  nameList << "亚瑟"
           << "妲己"
           << "安琪拉"
           << "东皇太一"
           << "李白";

  // QList<QString> 等价 QStringList
  QList<QString> sexList;
  sexList << "男"
          << "女"
          << "女"
          << "男"
          << "男";

  for (int i = 0; i < 5; i++) {
    int col = 0;
    //设置正文
    ui->tableWidget->setItem(i, col++, new QTableWidgetItem(nameList[i]));
    //添加性别
    ui->tableWidget->setItem(
        i, col++, new QTableWidgetItem(sexList.at(i))); // at越界抛出异常
    //添加年龄
    ui->tableWidget->setItem(
        i, col++,
        new QTableWidgetItem(QString::number(i + 18))); // int 转 QString number
  }

  //点击按钮 添加赵云
  connect(ui->addBtn, &QPushButton::clicked, [=]() {
    //先判断有没有赵云，有不添加，没有才添加
    bool isEmpty = ui->tableWidget->findItems("赵云", Qt::MatchExactly).empty();

    if (isEmpty) {
      ui->tableWidget->insertRow(0);
      ui->tableWidget->setItem(0, 0, new QTableWidgetItem("赵云"));
      ui->tableWidget->setItem(0, 1, new QTableWidgetItem("男"));
      ui->tableWidget->setItem(0, 2, new QTableWidgetItem(QString::number(20)));
    } else {
      QMessageBox::warning(this, "警告！", "赵云有了！");
    }
  });

  //点击按钮 删除赵云
  connect(ui->delBtn, &QPushButton::clicked, [=]() {
    bool isEmpty = ui->tableWidget->findItems("赵云", Qt::MatchExactly).empty();
    if (isEmpty) {
      QMessageBox::warning(this, "警告！", "赵云没有了！");
    } else {
      //先找到赵云所在的行
      int row =
          ui->tableWidget->findItems("赵云", Qt::MatchExactly).first()->row();
      //找到行数  删除掉
      ui->tableWidget->removeRow(row);
    }
  });
}

Widget::~Widget() { delete ui; }
