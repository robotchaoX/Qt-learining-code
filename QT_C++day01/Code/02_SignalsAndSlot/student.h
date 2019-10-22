#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject {
  Q_OBJECT
 public:
  explicit Student(QObject *parent = 0);

 signals:

 public slots:
  //自定义槽函数(响应？)
  //高版本可以写到  public下 或者全局函数
  //槽函数返回值 void
  //槽函数需要声明 也需要实现
  //槽函数也可以有参数 可以发生重载
  void treat();

  // 槽函数重载
  void treat(QString foodName);
};

#endif  // STUDENT_H
