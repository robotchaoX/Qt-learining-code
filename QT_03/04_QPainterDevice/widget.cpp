#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPicture>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //QPixmap 做绘图设备，对不同平台显示做了优化
    QPixmap pix(300,300);
    //设置默认填充色
    pix.fill(Qt::white);
    QPainter painter(&pix);
    painter.setPen(QPen(Qt::green));
    painter.drawEllipse(QPoint(150,150),100,100);
    //保存到本地
    pix.save("./pix.png");


    //QImage 做绘图设备， QImage可以访问像素
    QImage img(300,300,QImage::Format_RGB32);
    img.fill(Qt::white);
    QPainter painter2(&img);
    painter2.setPen(QPen(Qt::blue));
    painter2.drawEllipse(QPoint(150,150),100,100);
    img.save("./img.png");


    //QPicture 做绘图设备，QPicture记录重现绘图指令
    QPicture pic; //用于重现 记录绘图指令
    QPainter painter3;
    painter3.begin(&pic);
    painter3.setPen(QPen(Qt::cyan));
    painter3.drawEllipse(QPoint(150,150),100,100);
    painter3.end();
    //保存
    pic.save("./pic.pmd");
}

void Widget::paintEvent(QPaintEvent *)
{
    // QImage可修改像素
    QImage img;
    //加载图片
    img.load(":/Image/Luffy.png");
    //修改像素
    for(int i = 50 ; i < 100;i++)
    {
        for(int j = 50 ; j < 100 ;j ++)
        {
            QRgb value = qRgb(0,255,0);
            //设置像素点
            img.setPixel(i,j,value);
        }
    }
    QPainter painter(this);
    painter.drawImage(QPoint(0,0),img);


    //重现绘图指令 QPicture
    QPicture pic;
    pic.load("./pic.pmd");
    QPainter painter33(this);
    painter33.drawPicture(0,0,pic);
}

Widget::~Widget()
{
    delete ui;
}
