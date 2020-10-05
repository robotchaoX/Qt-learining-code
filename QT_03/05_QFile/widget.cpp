#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextCodec>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>
#include <QTextStream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //点击按钮 选取文件
    connect(ui->pushButton,&QPushButton::clicked,[=](){

        //文件对话框
        QString path = QFileDialog::getOpenFileName(this,"打开文件","./");
        if(path.isEmpty())
        {
            QMessageBox::warning(this,"警告","打开失败");
        }
        else
        {
            //将路径 放入到lineEdit
            ui->lineEdit->setText(path);

            // 1.读取文件
            //QFile默认支持UTF-8格式
            //QTextCodec * codec = QTextCodec::codecForName("gbk"); //指定编码格式

            QFile file(path); //参数路径名称
            //指定打开方式(只读)
            //file.open(QIODevice::ReadOnly);
            file.open(QFileDevice::ReadOnly);

            QByteArray array;
            //读取所有数据
            array = file.readAll();

            //读取单行数据
            //            while( !file.atEnd())
            //            {
            //                array += file.readLine();
            //            }

            //设置到 文本编辑框中
            ui->textEdit->setText(array);
            file.close();

            // ui->textEdit->setText( codec->toUnicode(array)); //读指定编码格式


            // 2.写文件
            //重新指定打开方式
            file.open(QFileDevice::Append); //追加写
            file.write("哦哦哦哦哦哦");
            file.close();


            // 3.文件信息
            //通过QFileInfo读取文件信息
            QFileInfo info(path);
            qDebug() << "路径： "<< info.filePath() <<
                        " 名称： "<<info.fileName() <<
                        " 文件大小" << info.size() <<
                        " 后缀名："<<info.suffix();
            qDebug() << "创建日期：" <<info.created().toString("yyyy-MM-dd hh:mm:ss");
            qDebug() << "修改日期：" <<info.lastModified().toString("yyyy/MM/dd hh:mm:ss");
        }

    });



    //文件流读写文件
    //分类：文本流（基础数据类型） 和 数据流 （大型QImage）

    //文本流
    //    QFile file("aaa.txt");
    //    file.open(QFileDevice::WriteOnly);
    //    QTextStream stream(&file);
    //    stream<< QString("hello World") << 123456 ;
    //    file.close();

    //    //读取
    //    file.open(QFileDevice::ReadOnly);
    //    QString str;
    //    //stream >>str; //读取空格 结束
    //    str = stream.readAll();
    //    qDebug() << str;

    //数据流 二进制
    QFile file("bbb.txt");
    file.open(QFileDevice::WriteOnly);
    QDataStream stream(&file);
    stream << QString("hello World") << 123456;
    file.close();

    //读数据
    file.open(QFileDevice::ReadOnly);
    QString str;
    int num;
    stream >>str >> num;
    qDebug() << str << num;

}

Widget::~Widget()
{
    delete ui;
}
