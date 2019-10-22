#ifndef MYWIDGET_H
#define MYWIDGET_H

// 窗口类头文件
#include <QWidget>

// MyWidget继承QWidget
class MyWidget : public QWidget  //MyWidget继承QWidget
{
    // Q_OBJECT宏，允许类中使用信号槽的机制
    Q_OBJECT  //Q_OBJECT宏 写了这个宏 就支持了 Qt中的信号和槽机制

public:
    MyWidget(QWidget *parent = 0);  // 构造函数声明
    ~MyWidget(); //析构函数
};

#endif // MYWIDGET_H
