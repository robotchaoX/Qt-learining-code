#include "widget.h"
#include "ui_widget.h"
#include <QMovie>
Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    //设置默认选中第0项
    ui->stackedWidget->setCurrentIndex(0);

    // stackWidget
    connect(ui->btnScroll, &QPushButton::clicked,
            [=]() { ui->stackedWidget->setCurrentIndex(0); });

    connect(ui->btnTab, &QPushButton::clicked,
            [=]() { ui->stackedWidget->setCurrentIndex(1); });

    connect(ui->btnToolBox, &QPushButton::clicked,
            [=]() { ui->stackedWidget->setCurrentIndex(2); });

    //下拉框使用
    ui->comboBox->addItem("下拉框");
    ui->comboBox->addItem("宝马");
    ui->comboBox->addItem("拖拉机");

    //点击拖拉机按钮
    connect(ui->btnChoose, &QPushButton::clicked,
            [=]() { ui->comboBox->setCurrentText("拖拉机"); });

    ////--利用QLabel显示图片--////
    //    ui->img->setPixmap(QPixmap(":/Image/Luffy.png"));

    ////--利用QLabel显示图片--////
    QImage *img2 = new QImage;
    img2->load(":/Image/Luffy.png");
    ui->img->setPixmap(QPixmap::fromImage(*img2));

    ////--利用QLabel显示gif图片--////
    QMovie *movie = new QMovie(":/Image/mario.gif");
    ui->movie->setMovie(movie);
    // start播放gif
    movie->start();//gif默认不会播放
}

Widget::~Widget() { delete ui; }
