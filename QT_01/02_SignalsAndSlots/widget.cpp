#include "widget.h"
#include <QDebug>
#include <QPushButton>

//需求：  创建两个类  Teacher 类  Student 类
// 下课后 老师Teacher zt  会发出一个信号   饿了
// 学生响应信号Student st  处理信号的槽函数  请客吃饭

// Widget类的构造函数             ：初始化列表
Widget::Widget(QWidget *parent) : QWidget(parent) {
    //重置窗口大小
    this->resize(600, 400);

    // 创建老师对象
    //  this->zt = new Teacher(this);
    zt = new Teacher(this);
    // 创建学生对象
    //  this->st = new Student(this);
    st = new Student(this);

    // 1.连接 不带参数 老师和学生的信号和槽
    //    connect(zt, &Teacher::hungry, st, &Student::treat);
    // 2.连接 带参数 的信号和槽
    //函数指针 -> 函数地址
    void (Teacher::*teaherSignal)(QString) = &Teacher::hungry; // 重载时必须用函数指针指明显性参数
    void (Student::*stSlot)(QString) = &Student::treat;
    connect(zt, teaherSignal, st, stSlot);

    //通过调用下课方法，触发老师饿了的信号
    //  classIsOver();

    //点击一个下课的按钮，再触发下课
    //  创建按钮
    QPushButton *btn = new QPushButton("下课", this);

    //点击按钮 触发下课
    //  1. 信号 连接 槽函数
    // 连接按钮信号和最终槽函数
    //  connect(btn, &QPushButton::clicked, this, &Widget::classIsOver);

    // 2. 信号 连接 信号（信号可以通过连接传递）
    void (Teacher::*noTeacherSignal)(void) = &Teacher::hungry; //触发无参 信号和槽
    void (Student::*noStSlot)(void) = &Student::treat;
    //先 信号 连接 信号，再 信号 连接 槽
    connect(btn, &QPushButton::clicked, zt, noTeacherSignal);
    connect(zt, noTeacherSignal, st, noStSlot);
    //一个信号可以连接多个不同的槽函数
    //  connect(btn, &QPushButton::clicked, this, &Widget::close);

    //断开信号和槽
    //  disconnect(zt, noTeacherSignal, st, noStSlot);

    //信号和槽的拓展
    // 1 信号可以连接信号
    // 2 信号和槽可以断开 disconnect
    // 3 一个信号可以触发多个槽函数
    // 4 多个信号可以连接同一个槽函数
    // 5 信号和槽的参数必须一一对应,参数个数必须一一对应吗？不一定
    //信号的参数个数 可以多余 槽函数的参数个数，反之不可以，但是必须类型一一对应

    // Qt 4版本 信号和槽写法
    // connect(zt, SIGNAL(hungry(QString)), st, SLOT(treat(QString)));
    //不推荐Qt4版本信号槽写法 ，原因：类型匹配不检测
    // 优点： 参数类型 比较直观，发生重载也不用写函数指针
    //不检测原因 SIGNAL和SLOT下 会把里面代码作为字符串处理
    // SIGNAL("hungry(QString)") SLOT("treat(QString)")

    //  Lambda 匿名表达式
    //用到最频繁的 [=](){}
    QPushButton *btn2 = new QPushButton(this);
    btn2->setText("aaaaa");
    btn2->move(10, 50);
    // Lambda 匿名表达式 [](){}()
    //匿名表达式修改Text，[=]值传递
    [=]() { btn2->setText("Lambda"); }();

    // mutable关键字 用于修改值传递的 变量，修改的是拷贝而不是本体
    QPushButton *myBtn1 = new QPushButton(this);
    QPushButton *myBtn2 = new QPushButton(this);
    myBtn1->move(150, 100);
    myBtn2->move(250, 100);
    myBtn1->setText("myBtn1");
    myBtn2->setText("myBtn2");
    int m = 10;
    // myBtn1 修改值 加mutable
    connect(myBtn1, &QPushButton::clicked, this, [m]() mutable {
        m = 100 + 10;
        qDebug() << m;
    });
    // myBtn2 打印m值
    connect(myBtn2, &QPushButton::clicked, this, [=]() { qDebug() << m; });
    // 原始m值
    qDebug() << "原始m值：" << m;

    // 返回值
    // ->　指定返回值类型
    int ret = []() -> int { return 10000; }();
    qDebug() << "返回值：　ret = " << ret;

    QPushButton *btn3 = new QPushButton(this);
    btn3->move(200, 200);
    btn3->setText("btn3");
    //做信号槽连接  默认内部变量会进行锁状态，只读状态，如果进行写操作，就会挂掉
    connect(btn3, &QPushButton::clicked, this,
            [=]() { btn3->setText("宫保鸡丁1111"); });

    //无参按钮调用 有参 请客吃饭
    connect(btn3, &QPushButton::clicked, this,
            [=]() { zt->hungry("宫保鸡丁1111"); });

    //点击按钮，关闭窗口
    QPushButton *btn4 = new QPushButton(this);
    btn4->move(10, 300);
    btn4->setText("关闭");
    connect(btn4, &QPushButton::clicked, [=]() { this->close(); });
}

// 下课方法实现
void Widget::classIsOver() {
    //触发老师饿了的信号
    //老师饿了的信号属于自定义信号，
    // 触发自定义信号关键字  emit
    emit zt->hungry();           //触发无参信号
    emit zt->hungry("宫保鸡丁"); // 触发有参信号
}

Widget::~Widget() {}
