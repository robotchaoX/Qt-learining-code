#ifndef MYCOIN_H
#define MYCOIN_H

#include <QWidget>
#include <QPushButton>
#include <QPixmap>
#include <QMessageBox>
#include <QString>
#include <QTimer>

//金币类
class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    // explicit MyCoin(QWidget *parent = 0);

    //参数 功能 显示默认是金币还是银币
    MyCoin(QString butImg);

    int posX;  //X坐标
    int posY;  //Y坐标
    bool flag; //正反标志

    void changeFlag();//改变标志,执行翻转效果
    QTimer *timer1; //正面翻反面 定时器
    QTimer *timer2; //反面翻正面 定时器
    int min = 1; //最小图片
    int max = 8; //最大图片

    //创建是否执行动画标志,如果正在执行动画就等待动画执行完
    bool isAnimation  = false; //做翻转动画的标志

    //鼠标按下事件重写
    void mousePressEvent(QMouseEvent *e);

    //是否胜利，每个硬币上,用来禁用胜利后硬币的点击
    bool isWin = false; //是否胜利

signals:

public slots:
};

#endif // MYCOIN_H
