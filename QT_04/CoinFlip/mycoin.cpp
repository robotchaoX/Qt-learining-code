#include "mycoin.h"
#include<QDebug>
#include<QTimer>

MyCoin::MyCoin(QString butImg)
{
    QPixmap pixmap;
    bool ret = pixmap.load(butImg);
    if(!ret)
    {
        QString str = QString("图片加载失败 %1").arg(butImg);
        QMessageBox::critical(this,"加载失败",str);
        return;
    }

    this->setFixedSize( pixmap.width(), pixmap.height() );
    this->setStyleSheet("QPushButton{border:0px;}"); //CSS风格
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));

    //执行翻转定时器
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    //初始化按钮是否执行动画
    this->isAnimation = false;

    //初始化没有胜利
    this->isWin = false;

    //监听正面翻转的信号槽
    connect(timer1,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1.png").arg(this->min++);
        pix.load(str);
        this->setFixedSize(pix.width(),pix.height() );
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));

        //如果显示到 最后一张图片 ，停止定时器
        if(this->min > this->max) //如果大于最大值，重置最小值，并停止定时器
        {
            this->min = 1; //重置最小值
            this->isAnimation = false; //做完动画后将 标志设置为false
            timer1->stop(); //定时器停止
        }
    });

    //监听银币翻金币信号
    connect(timer2,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%8.png").arg((this->max)-- );
        pix.load(str);
        this->setFixedSize(pix.width(),pix.height() );
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));

        //如果显示到 最后一张图片 ，停止定时器
        if(this->max < this->min) //如果小于最小值，重置最大值，并停止定时器
        {
            this->max = 8; //重置最大值
            this->isAnimation = false; //做完动画后将 标志设置为false
            timer2->stop(); //定时器停止
        }
    });

}

//改变标志,执行翻转效果
void MyCoin::changeFlag()
{
    if(this->flag) //当前是正面
    {
        //开启 正面 翻 反面的定时器
        timer1->start(30);
        //同步标志
        this->flag = false;
    }
    else //当前是反面
    {
        //开启 反面 翻 正面的定时器
        timer2->start(30);
        //同步标志
        this->flag = true;
    }
    //同步执行动画标志
    isAnimation = true;
}

//鼠标按下事件重写
void MyCoin::mousePressEvent(QMouseEvent *e)
{
    if(this->isAnimation || this->isWin)
    {
        //正在做动画，不做鼠标响应
        return;
    }
    else
    {
        //交给父类 做默认处理
        return QPushButton::mousePressEvent(e);
    }
}
