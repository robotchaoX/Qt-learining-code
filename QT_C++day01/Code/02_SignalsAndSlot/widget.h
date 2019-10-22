#ifndef WIDGET_H
#define WIDGET_H

#include "student.h"
#include "teacher.h"
#include <QWidget>

// Widget类  ：继承QWidget
class Widget : public QWidget {
  Q_OBJECT

public:
  explicit Widget(QWidget *parent = 0);
  ~Widget();

  // private:
  Teacher *zt; // 老师类对象指针
  Student *st; // 学生类对象指针

  // 下课方法声明
  void classIsOver();
};

#endif // WIDGET_H
