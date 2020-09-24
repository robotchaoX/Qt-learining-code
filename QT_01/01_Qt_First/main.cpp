#include "mywidget.h"
#include <QApplication> //包含头文件 应用程序

// 快捷键
// 运行  ctrl + R
// 编译  ctrl + B
// 查找  ctrl + F
// 注释快捷键  ctrl + /
// 帮助文档 F1
// 字体缩放  ctrl + 鼠标滚轮
// 格式化选中代码  ctrl + i
// 整行移动 ctrl+ shift + ↑ 或者 ↓
// 同名之间的 .h .cpp切换  F4
// 帮助文档 第一种 ： F1  第二种 ：左侧按钮

// 程序入口 argc命令行变量数量  argv命令行变量数组
int main(int argc, char *argv[]) {
    //应用程序对象  a ，Qt中  有且仅有一个 应用程序对象
    QApplication a(argc, argv);

    //创建 MyWidget对象 w   MyWidget基类 QWidget
    MyWidget w;

    //窗口默认是不会弹出的，如果想弹出 调用 show方法
    w.show();

    // a.exec()进入消息循环机制 pause
    return a.exec();
}
