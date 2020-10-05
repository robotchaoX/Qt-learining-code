#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

//自定义MyLabel控件，继承自QLabel
class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = 0);

    // 1.捕获鼠标事件(重写方法)
    //鼠标进入
    void enterEvent(QEvent *);
    //鼠标离开
    void leaveEvent(QEvent *);
    //鼠标按下
    void mousePressEvent(QMouseEvent *ev);
    //鼠标释放
    void mouseReleaseEvent(QMouseEvent *ev);
    //鼠标移动
    void mouseMoveEvent(QMouseEvent *ev);

    //事件分发 Event事件
    bool event(QEvent *e);

};

#endif // MYLABEL_H
