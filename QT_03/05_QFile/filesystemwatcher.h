#ifndef FILESYSTEMWATCHER_H
#define FILESYSTEMWATCHER_H

#include <QObject>
#include <QObject>
#include <QMap>
#include <QFileSystemWatcher>

class FileSystemWatcher : public QObject
{
    Q_OBJECT

private:
    explicit FileSystemWatcher(QObject *parent = nullptr); // 单例

public:
    static void addWatchPath(QString path); // 单例，对外接口


signals:

public slots:
    void directoryUpdated(const QString &path);  // 目录件被修改时调用，path是监控的路径
    void fileUpdated(const QString &path);   // 文件被修改时调用，path是监控的路径

private:
    static FileSystemWatcher *m_pInstance; // 单例
    QFileSystemWatcher *m_pSystemWatcher;  // QFileSystemWatcher变量
    QMap<QString, QStringList> m_currentContentsMap; // 当前每个监控的内容目录列表
};

#endif // FILESYSTEMWATCHER_H
