#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include "playscene.h"

//选择关卡场景页面（第二个页面）
class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);

    //重写绘图事件
    void paintEvent(QPaintEvent *event);

    //游戏场景对象指针
    PlayScene * play = NULL;

signals:
    //写一个自定义信号，告诉主场景  点击了返回
    void chooseSceneBack();

public slots:
};

#endif // CHOOSELEVELSCENE_H
