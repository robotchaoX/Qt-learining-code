#include "mybutton.h"
#include <QDebug>  // 通过调试在QT中打印信息

//构造函数
MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{
 qDebug() << "MyButton的构造调用！";
}

//析构函数
MyButton::~MyButton()
{

    qDebug() << "MyButton的析构调用！";
}
