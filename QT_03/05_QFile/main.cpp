#include "widget.h"
#include <QApplication>
#include "filesystemwatcher.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    //可以通过FileSystemWatcher::addWatchPath()来监控指定的文件/目录，监控之后，就可以在对应的路径进行更新测试了
    FileSystemWatcher::addWatchPath("E:/Test");

    return a.exec();
}
