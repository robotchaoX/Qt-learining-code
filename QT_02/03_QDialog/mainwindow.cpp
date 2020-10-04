#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog> // 颜色对话框
#include <QDebug>
#include <QDialog>     // 对话框
#include <QFileDialog> // 文件对话框
#include <QFontDialog> // 字体对话框
#include <QMessageBox> // 标准对话框

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // 点击-新建-菜单项 弹出对话框
    connect(ui->actionNew, &QAction::triggered, this, [=]() {
        //创建对话框，对话框有两种 模态对话框 和 非模态对话框
        // 1.模态对话框 （不可以对其他窗口进行操作，阻塞）
        /* 会阻塞，创建到栈上，没有问题
            QDialog dlg(this);  // 对象
            dlg.resize(200,100);
            dlg.exec(); //阻塞，模态对话框
            qDebug() << "弹出对话框！";
        */
        // 开辟到堆上
        //        QDialog *dlg = new QDialog(this); // 指针
        //        dlg->resize(200, 100);
        //        dlg->exec(); //阻塞，模态对话框
        //        qDebug() << "弹出对话框！";
        //        //需要设置属性（关闭后释放对话框）55号
        //        dlg->setAttribute(Qt::WA_DeleteOnClose); // 关掉时就释放内存

        // 2.非模态对话框（可以对其他窗口操作）
        // 不会阻塞，创建到栈上，有问题
        // QDialog dlg2(this);  // error 这种方式创建到栈上 一闪而过
        // 开辟到堆上
        QDialog *dlg2 = new QDialog(this);
        dlg2->resize(200, 100);
        dlg2->show(); // 非模态对话框显示
        qDebug() << "弹出对话框！";
        //需要设置属性（关闭后释放对话框）55号
        dlg2->setAttribute(Qt::WA_DeleteOnClose);//关闭后释放对话框，防止一直点击弹出new占满内存
    });

    // 点击-打开-菜单项 弹出对话框
    connect(ui->actionOpen, &QAction::triggered, this, [=](){
        // 3.标准对话框  QMessageBox

        // 3.1错误对话框
        QMessageBox::critical(this,"错误！","critical");

        // 3.2信息对话框
        //        QMessageBox::information(this,"信息","info");

        // 3.3警告对话框
        //        QMessageBox::warning(this, "警告！", "warning");

        // 3.4询问对话框
        // 参数1: 父亲， 参数2: 标题， 参数3: 提示内容， 参数4: 按键类型， 参数5: 默认关联回车按键
        //        if (QMessageBox::Save ==
        //                QMessageBox::question(this, "问题", "question",
        //                                      QMessageBox::Save | QMessageBox::Cancel,
        //                                      QMessageBox::Cancel)) {
        //            qDebug() << "点击的是Save保存";
        //        } else {
        //            qDebug() << "点击的是Cancel取消";
        //        }

        // 4.文件对话框
        // 参数：父窗口，标题，默认文件路径，打开的文件类型
        //        QString path = QFileDialog::getOpenFileName(
        //                    this, "打开文件", "/home/chao/Desktop", "(*.txt *.png,*.doc)");
        //        qDebug() << path;

        // 5.选择颜色对话框
        //        QColor color = QColorDialog::getColor(QColor(255, 0, 0));
        //        qDebug() << color.red() << color.green() << color.blue();

        // 6.字体对话框
        //        bool flag;
        //        QFont font = QFontDialog::getFont(&flag, QFont("Noto Sans", 30));
        //        qDebug() << "字体" << font.family().toUtf8().data() << "字号"
        //                 << font.pointSize() << "是否加粗" << font.bold() <<
        //                    "是否斜体"
        //                 << font.italic();
    });
}

MainWindow::~MainWindow() { delete ui; }
