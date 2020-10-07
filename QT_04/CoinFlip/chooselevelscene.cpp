#include "chooselevelscene.h"
#include <QSound>
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include <QDebug>
#include <QTimer>
#include <QLabel>

ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    //配置选择关卡场景
    this->setFixedSize(320,588);

    //设置标题
    this->setWindowTitle("选择关卡场景");

    //设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));


    //创建菜单栏
    QMenuBar * bar = menuBar();
    this->setMenuBar(bar);

    //创建开始菜单
    QMenu * startMenu = bar->addMenu("开始");

    //创建退出 菜单项
    QAction *  quitAction = startMenu->addAction("退出");

    //点击退出按钮 实现退出游戏
    connect(quitAction,&QAction::triggered,[=](){
        this->close();
    });

    //选择关卡按钮的音效
    QSound * chooseSound = new QSound(":/res/TapButtonSound.wav",this);
    //返回按钮的音效
    QSound * backSound = new QSound(":/res/BackButtonSound.wav",this);

    //返回按钮
    MyPushButton * backBtn = new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);//依赖的窗口
    backBtn->move(this->width() - backBtn->width(), this->height() - backBtn->height());

    //点击返回按钮
    connect(backBtn,&MyPushButton::clicked,[=](){
        qDebug() << "点击了返回按钮";
        //告诉主场景 我返回了，主场景监听ChooseLevelScene的返回按钮
        //延时返回
        //播放返回按钮的音效
        backSound->play();
        //延时发送返回按钮信号
        QTimer::singleShot(500,this,[=](){
            //发送返回信号（自定义信号）
            emit this->chooseSceneBack();
        });
    });

    //创建选择关卡的按钮
    for( int i = 0 ; i < 20 ;i ++)
    {

        //按钮
        MyPushButton * menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);//依赖的窗口
        menuBtn->move( 25 + i%4 * 70 , 130 + i/4 * 70  );

        //监听每个按钮的点击事件
        connect(menuBtn,&MyPushButton::clicked,[=](){
            chooseSound->play();
            QString str = QString("您选择的是第 %1 关 ").arg( i + 1);
            qDebug() <<str;

            //进入到游戏场景
            //隐藏自身
            this->hide(); //将选关场景隐藏掉
            //进入到具体的场景
            play = new PlayScene(i+1); //创建游戏场景
            //将游戏场景的位置 设为 选择场景的位置
            play->setGeometry(this->geometry());//切换场景后相同的位置显示
            play->show();//显示游戏场景

            connect(play,&PlayScene::chooseSceneBack,[=](){
                //设置选择关卡的位置 为游戏场景的位置
                this->setGeometry(play->geometry());//切换场景后相同的位置显示
                play->close();
                delete play;
                play = NULL;

                this->show();
            });
        });

        //文字标签（覆盖在按钮上）
        QLabel * label = new QLabel;
        label->setParent(this);
        //设置标签大小
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        //设置显示内容
        label->setText(QString::number(i+1));
        //设置位置
        label->move(25 + i%4 * 70 , 130 + i/4 * 70 );
        //设置 label上的文字对齐方式 水平居中和 垂直居中
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        //设置让鼠标进行穿透   51号属性
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }
}

void ChooseLevelScene::paintEvent(QPaintEvent *event)
{
    //加载背景
    QPainter painter(this);
    //背景图片
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //加载标题
    pix.load(":/res/Title.png");
    painter.drawPixmap( (this->width() - pix.width())*0.5,30,pix.width(),pix.height(),pix);
}
