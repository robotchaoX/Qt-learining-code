#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
#include "mypushbutton.h"
#include "chooselevelscene.h"
#include <QDebug>
#include <QTimer>
#include <QSound>

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    //配置主场景

    //设置主界面固定大小
    this->setFixedSize(320,588);

    //设置标题栏图标
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    //设置标题
    this->setWindowTitle("翻金币主场景");

    //准备出开始按钮的音效
    QSound *startSound = new QSound(":/res/TapButtonSound.wav",this);
    //     startSound->play(); //播放一次
    startSound->setLoops(2);//设置循环次数  -1是无线循环

    //    //退出按钮 实现
    //    connect(ui->actionQuit,&QAction::triggered,[=](){
    //        this->close(); //关闭
    //    });

    //开始按钮
    MyPushButton * startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this); //依赖的窗口
    startBtn->move( this->width() * 0.5 - startBtn->width() * 0.5 ,this->height() * 0.7 );

    //实例化选择关卡场景
    chooseScene = new ChooseLevelScene;

    //监听第二个选择场景返回按钮发出的信号
    connect(chooseScene,&ChooseLevelScene::chooseSceneBack,this,[=](){
        chooseScene->hide(); //将选择关卡场景 隐藏掉
        //自身位置设为 关卡场景位置
        this->setGeometry(chooseScene->geometry()); //切换场景后相同的位置显示
        this->show(); //重新显示主场景
    });

    //点击开始按钮事件
    connect(startBtn,&MyPushButton::clicked,[=](){
        qDebug() << "点击了开始";
        //播放开始按钮
        startSound->play(); //开始音效
        //按键按下弹出动态特效
        startBtn->zoomdown();
        startBtn->zoomup();

        //延时进入到选择关卡场景中
        QTimer::singleShot(500,this,[=](){
            //隐藏主页场景（自身隐藏）
            this->hide();
            //显示选择关卡场景
            chooseScene->setGeometry((this->geometry()));//切换场景后相同的位置显示
            //进入第二个 选择关卡场景中
            chooseScene->show();
        });
    });
}

MainScene::~MainScene()
{
    delete ui;
}

//设置开始页面背景
void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    //画背景图片
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix); //指定长宽
    //画主题logo图
    pix.load(":/res/Title.png");
    pix = pix.scaled( pix.width() * 0.5 , pix.height() * 0.5); //缩放
    painter.drawPixmap(10,30,pix);
}

//退出按钮实现
//信号与槽的方式
//connect(ui->actionQuit,&QAction::triggered,[=]()this->close();});
//退出按钮实现，重载ui控件触发事件的方式 on_xxx_triggered
void MainScene::on_actionQuit_triggered()
{
    this->close();
}
