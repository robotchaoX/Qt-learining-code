#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QTimerEvent>
#include <QTimer>
#include <QMouseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //定时器第一种方式
    firstTimerEventWay();

    //QTimer定时器第二种方式（推荐）
    secondTimerEventWay();

    //3.事件过滤器的事件
    //给ui->label做事件过滤器 拦截
    //步骤1:  给控件安装过滤器
    // 参数this 通过父窗口给lable安装过滤器
    ui->label->installEventFilter(this);
    //步骤2:  重写 eventFilter事件
}

//重载事件过滤器的事件
bool Widget::eventFilter(QObject * obj, QEvent * e)
{
    //label对象
    if(obj == ui->label)
    {
        //鼠标按下事件
        if( e->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent * ev =  static_cast<QMouseEvent *>(e); //类型转换
            QString str = QString("事件过滤器：：：鼠标按下了！！！ x = %1 y = %2").arg(ev->x()).arg(ev->y());
            qDebug()  << str;
            //鼠标按下 自己处理 返回true，拦截事件
            return true;
        }
    }

    //其他事件让 父类处理
    return QWidget::eventFilter(obj,e);
}

// 4.事件分发器
bool Widget::event(QEvent * e)
{         //鼠标按下事件
    if( e->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent * ev =  static_cast<QMouseEvent *>(e); //类型转换
        QString str = QString("事件分发器：：：鼠标按下了！！！ x = %1 y = %2").arg(ev->x()).arg(ev->y());
        qDebug()  << str;
        //鼠标按下 自己处理 返回true，拦截事件
        return true;
    }

    //其他事件让 父类处理
    return QWidget::event(e);
}

//定时器第一种方式
void Widget::firstTimerEventWay()
{
    //定时器第一种方式
    //启动定时器,返回定时器id
    timer_id1 = startTimer(2000); //每间隔ms，调用一次timerEvent事件
    timer_id2 = startTimer(1000);//每1000毫秒自动调用一次timerEvent事件
}

//重载定时器事件
void Widget::timerEvent(QTimerEvent * e)
{
    //定时器第一种方式
    //定时器1
    if(e->timerId() == timer_id1)
    {
        static int num = 0;
        ui->label_2->setText( QString::number(num++)); // int转QString
    }

    //定时器2
    if(e->timerId() == timer_id2)
    {
        static int num2 = 0;
        ui->label_3->setText(QString::number(num2++));
    }

}

//QTimer定时器第二种方式（推荐）
void Widget::secondTimerEventWay()
{
    //QTimer定时器第二种方式（推荐）
    //定时器对象
    QTimer * timer1 = new QTimer(this);//父窗口
    //启动定时器对象
    timer1->start(500); //每间隔ms，触发信号
    //每隔0.5秒发送信号
    connect(timer1,&QTimer::timeout,[=](){
        static int num = 0;
        ui->label_4->setText( QString::number(num++));
    });

    //点击按钮 暂停定时器
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        timer1->stop(); //关闭定时器
    });
}

Widget::~Widget()
{
    delete ui;
}
