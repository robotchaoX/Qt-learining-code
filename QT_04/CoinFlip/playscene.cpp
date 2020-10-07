#include "playscene.h"
#include <QDebug>
#include <QPropertyAnimation>
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include "mycoin.h"
#include "dataconfig.h"
#include <QTimer>
#include <QLabel>
#include <QSound>

//PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
//{
//}

PlayScene::PlayScene(int levelNum)
{
    QString str = QString("进入了第 %1 关 ").arg(levelNum);
    qDebug() << str;
    //保存本关 关卡号
    this->levelIndex = levelNum;

    //初始化游戏场景
    //设置固定大小
    this->setFixedSize(320,588);
    //设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    //设置标题
    this->setWindowTitle("翻金币场景");

    //创建菜单栏
    QMenuBar * bar = menuBar();
    this->setMenuBar(bar);

    //创建开始菜单
    QMenu * startMenu = bar->addMenu("开始");

    //创建退出 菜单项
    QAction *  quitAction = startMenu->addAction("退出");

    //点击退出 实现退出游戏
    connect(quitAction,&QAction::triggered,[=](){
        this->close();
    });

    //翻金币音效
    QSound *flipSound = new QSound(":/res/ConFlipSound.wav",this);
    //胜利按钮音效
    QSound *winSound = new QSound(":/res/LevelWinSound.wav",this);
    //返回按钮的音效
    QSound *backSound = new QSound(":/res/BackButtonSound.wav",this);

    //返回按钮
    MyPushButton * backBtn = new MyPushButton(":/res/BackButton.png" , ":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width() , this->height() - backBtn->height());

    //点击返回
    connect(backBtn,&MyPushButton::clicked,[=](){
        qDebug() << "翻金币场景中：点击了返回按钮";
        //播放返回按钮的音效
        backSound->play();
        //延时发送返回按钮信号
        QTimer::singleShot(500,this,[=](){
            emit this->chooseSceneBack();
        });

    });

    //显示当前关卡数
    QLabel * label = new QLabel;
    label->setParent(this);
    //设置字体
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    QString str1 = QString("Level: %1").arg(this->levelIndex);
    //将字体设置到标签控件中
    label->setFont(font);
    label->setText( str1);
    //设置几何形状（移动位置）
    label->setGeometry(QRect( 30, this->height() - 50,140, 50));

    dataConfig data;
    //初始化游戏中的二维数据
    for(int i = 0; i < 4;i++)
    {
        for(int j = 0; j <4;j++)
        {
            this->gameArray[i][j] = data.mData[this->levelIndex][i][j];
        }
        qDebug()<<""; //??
    }

    //创建胜利的图片
    QLabel* winLabel = new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/res/LevelCompletedDialogBg.png");
    winLabel->setGeometry(0,0,tmpPix.width(),tmpPix.height());
    winLabel->setPixmap(tmpPix);
    winLabel->setParent(this);
    //移动位置（移到屏幕外，看不到）
    winLabel->move( (this->width() - tmpPix.width())*0.5 , -tmpPix.height());

    //创建金币的背景图片
    for(int i = 0 ; i < 4;i++)
    {
        for(int j = 0 ; j < 4; j++)
        {
            //QLabel显示图片,绘制背景图片
            QLabel* bg = new QLabel(this);
            QPixmap pix;
            pix.load(":/res/BoardNode.png");
            bg->setPixmap(pix);
            //设置几何形状
            bg->setGeometry(0,0,pix.width(),pix.height());
            //移动位置
            bg->move(57 + i*50,200+j*50);

            //金币对象
            QString str;    //区分金银币

            if(this->gameArray[i][j] == 1)
            {
                str = ":/res/Coin0001.png"; //金币
            }
            else
            {
                str = ":/res/Coin0008.png"; //银币
            }

            MyCoin * coin = new MyCoin(str);
            coin->posX = i; //记录x坐标
            coin->posY = j; //记录y坐标
            coin->flag = this->gameArray[i][j]; //记录正反标志
            coin->setParent(this);
            coin->move(59 + i*50,204+j*50);

            //将创建的coin放到数组中
            coinBtn[i][j] = coin;

            connect(coin,&MyCoin::clicked,[=]()
            {
                //点击后，先将所有的按钮禁用，不能点击
                //PlayScene里面的isWin --- 判断整个游戏是否胜利
                //MyCoin里面的isWin属性 ---目的时为了游戏胜利后不可再次点击
                //禁用所有金币按钮
                for(int i = 0 ; i < 4;i++)
                {
                    for(int j = 0 ; j < 4; j++)
                    {
                        coinBtn[i][j]->isWin = true;
                    }
                }
                //翻被点击的硬币
                flipSound->play();
                coin->changeFlag();
                //同步内部维护的二维数组
                gameArray[i][j] = gameArray [i][j] == 0?1:0;

                //延时翻zhouwei的硬币
                QTimer::singleShot(300, this,[=]()
                {
                    //右侧
                    if(coin->posX+1 <=3)
                    {
                        coinBtn[coin->posX+1][coin->posY]->changeFlag();
                        gameArray[coin->posX+1][coin->posY] = gameArray[coin->posX+1][coin->posY]== 0 ? 1 : 0;
                    }
                    //左侧
                    if(coin->posX-1>=0)
                    {
                        coinBtn[coin->posX-1][coin->posY]->changeFlag();
                        gameArray[coin->posX-1][coin->posY] = gameArray[coin->posX-1][coin->posY]== 0 ? 1 : 0;
                    }
                    //下侧
                    if(coin->posY+1<=3)
                    {
                        coinBtn[coin->posX][coin->posY+1]->changeFlag();
                        gameArray[coin->posX][coin->posY+1] = gameArray[coin->posX+1][coin->posY]== 0 ? 1 : 0;
                    }
                    //上侧
                    if(coin->posY-1>=0)
                    {
                        coinBtn[coin->posX][coin->posY-1]->changeFlag();
                        gameArray[coin->posX][coin->posY-1] = gameArray[coin->posX+1][coin->posY]== 0 ? 1 : 0;
                    }
                    
                    //翻完所有硬币后 将所有硬币解禁
                    //释放所有金币按钮
                    for(int i = 0 ; i < 4;i++)
                    {
                        for(int j = 0 ; j < 4; j++)
                        {
                            coinBtn[i][j]->isWin = false;
                        }
                    }

                    //翻完金币判断是否胜利,如果全是金币则胜利
                    this->isWin = true; //假设胜利
                    for(int i = 0 ; i < 4;i++)
                    {
                        for(int j = 0 ; j < 4; j++)
                        {
                            //qDebug() << coinBtn[i][j]->flag ;
                            if( coinBtn[i][j]->flag == false)//有一个不对就没有胜利
                            {
                                this->isWin = false;
                                break;
                            }
                        }
                    }

                    if(this->isWin == true)
                    {
                        //播放胜利的音效
                        qDebug() << "胜利";
                        winSound->play();
                        //将所有硬币胜利标志 都设置为true
                        for(int i = 0; i < 4; i++)
                        {
                            for(int j = 0; j < 4; j++)
                            {
                                coinBtn[i][j]->isWin = true; //硬币isWin不可再点击了
                            }
                        }

                        //将胜利的图片显示出来（动画跳动）
                        QPropertyAnimation * animation1 =  new QPropertyAnimation(winLabel,"geometry");//winLabel跳
                        animation1->setDuration(1000);
                        animation1->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));
                        animation1->setEndValue(QRect(winLabel->x(),winLabel->y()+114,winLabel->width(),winLabel->height()));
                        animation1->setEasingCurve(QEasingCurve::OutBounce);
                        animation1->start(); // 启动动画
                    }

                });

            });
        }
    }

}

//重写绘图事件
void PlayScene::paintEvent(QPaintEvent *event)
{
    //绘制背景图片
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //绘制标题
    pix.load(":/res/Title.png");
    //缩放
    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap( 10,30,pix.width(),pix.height(),pix);

}
