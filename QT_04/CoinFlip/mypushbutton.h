#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

//自定义按钮类，没有ui
class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyPushButton(QWidget *parent = 0);

    //构造函数 参数1:正常显示的图片路径   参数2:按下后显示的图片路径
    MyPushButton(QString normalImg, QString pressImg = "" );

    //按键按下弹出动态特效
    //按键按下动态特效
    void zoomdown();
    //按键松开动态特效
    void zoomup();

    //鼠标按下按键切换图片，释放切换图片，实现按下松开动态
    //重写鼠标 按下 事件
    void mousePressEvent(QMouseEvent *e);
    //重写鼠标 释放 事件
    void mouseReleaseEvent(QMouseEvent *e);

    //成员属性 保存用户传入的默认显示路径 以及按下后显示的图片路径
    QString normalImgPath;//默认显示图片路径
    QString pressImgPath;//按下显示图片路径

signals:

public slots:
};

#endif // MYPUSHBUTTON_H
