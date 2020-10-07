#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include "mycoin.h"

//玩游戏的场景（第三个场景界面）
class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    //    explicit PlayScene(QWidget *parent = nullptr);

    PlayScene(int levelNum);

    //关卡号
    int levelIndex ; //记录所选的关卡

    //维护金币或银币标志
    int gameArray[4][4]; //二维数组数据

    //金币按钮数组
    MyCoin * coinBtn[4][4];

    //是否胜利,判断游戏是否胜利
    bool isWin = true;

    //重写paintEvent事件
    void paintEvent(QPaintEvent *event);

signals:
    void chooseSceneBack();

public slots:
};

#endif // PLAYSCENE_H
