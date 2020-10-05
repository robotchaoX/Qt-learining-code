#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

    // 2.定时器事件
    //定时器第一种方式
    //重载定时器事件
    void timerEvent(QTimerEvent *);
    //定时器标识号
    int timer_id1;
    int timer_id2;
    void firstTimerEventWay();

    //QTimer定时器第二种方式（推荐）
    void secondTimerEventWay();

    // 3.事件过滤器的事件
    bool eventFilter(QObject *, QEvent *);

    // 4.事件分发器
    bool event(QEvent *);
};

#endif // WIDGET_H
