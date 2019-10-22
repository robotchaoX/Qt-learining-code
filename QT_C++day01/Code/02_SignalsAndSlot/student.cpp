#include "student.h"
#include <QDebug>

Student::Student(QObject *parent) : QObject(parent) {}

//槽函数实现
void Student::treat() { qDebug() << "无参：请老师吃饭"; }

// 槽函数重载实现
void Student::treat(QString foodName) {
  // qDebug() << "请老师吃饭 ，老师要吃："<< foodName;  // 输出foodName带引号
  // QString 转 char*  // .toUtf8()先转成 QByteArray类型  再.data()转char *
  qDebug() << "有参：请老师吃饭 ，老师要吃：" << foodName.toUtf8().data();
}
