#include "mywidget.h"
#include "mybutton.h"
#include <QDebug>      // 在QT中打印信息
#include <QPushButton> // 控件按钮的头文件

// 构造函数
MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent) //初始化列表
{
  //创建一个按钮对象
  QPushButton *btn = new QPushButton;
  // btn->show();
  // show用顶层方式弹出（单独窗口），如果想在MyWidget窗口中显示，就需要依赖MyWidget窗口

  //设置父亲,让btn依赖在mywidget窗口中
  btn->setParent(this);

  //设置按钮文字
  btn->setText("德玛西亚"); //将char* 隐式类型转为QString

  //创建按钮第二种方式  窗口会按照 btn2大小进行显示
  QPushButton *btn2 = new QPushButton("第二按钮", this);

  //重置主窗口大小
  resize(600, 400);

  //移动第二个按钮控件，（从原点移动，即设置按钮的位置）
  btn2->move(100, 100);

  //重置按钮大小
  btn2->resize(50, 50);

  //设置窗口标题
  setWindowTitle("Qt第一个窗口");
  //设置固定窗口大小
  setFixedSize(600, 400);

  //创建自己的按钮
  MyButton *myBtn = new MyButton;
  myBtn->setText("我的按钮");
  myBtn->move(200, 200);
  myBtn->setParent(this); // 自动设置到对象树中
  // 当主窗口被析构时，窗口下的控件都会被析构，一定程度下 简化了内存回收机制

  // Qt坐标系
  // 坐上（0,0）,x为右侧正向  y 以 下侧为正向

  // connect 信号和槽
  // 点击 myBtn 关闭窗口
  // 参数1：信号的发送者对象指针  参数2：发送的信号指针
  // 参数3：信号的接受者指针   参数4：处理的槽函数指针
  // connect(myBtn,&MyButton::clicked , this , &MyWidget::close);  // 等效
  connect(myBtn, &QPushButton::clicked, this, &QWidget::close);
}

MyWidget::~MyWidget() { qDebug() << "MyWidget析构了！"; } // 先打印再找子类，
