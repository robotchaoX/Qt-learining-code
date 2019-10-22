#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QPushButton>

// 新建 -- C++ -- C++class -- 继承父类 // 自定义类
// 自定义MyButton类
class MyButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent = 0);
    ~MyButton();
signals:

public slots:
};

#endif // MYBUTTON_H
