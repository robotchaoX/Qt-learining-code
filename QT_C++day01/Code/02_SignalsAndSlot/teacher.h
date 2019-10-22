#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject {
  Q_OBJECT
 public:
  explicit Teacher(QObject *parent = 0);

 signals:
  //自定义信号（事件？）
  //需要写到signals下
  //返回类型 必须void
  //信号只需要声明 不需要实现
  //信号可以有参数,可以重载
  void hungry();

  // 信号重载
  void hungry(QString foodName);

 public slots:
};

#endif  // TEACHER_H
