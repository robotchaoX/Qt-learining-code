#include "mainwindow.h"
#include <QDockWidget> // 浮动窗口
#include <QLabel>      // 标签
#include <QMenuBar>    // 菜单栏
#include <QPushButton> // 按键
#include <QStatusBar>  // 状态栏
#include <QTextEdit>   // 文本编辑
#include <QToolBar>    // 工具栏

// MainWindow() 构造函数 ： 初始化列表
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // 重置窗口大小
    resize(600, 400);

    // 1.菜单栏
    // 菜单栏 只能有一个
    // 创建菜单栏
    QMenuBar *bar = menuBar();
    // 当前窗口 设置菜单栏（将菜单栏放入到当前窗口中）
    this->setMenuBar(bar); // 关联当前窗口

    //菜单栏 添加文件菜单
    QMenu *fileMenu = bar->addMenu("菜单栏-文件");
    QMenu *editMenu = bar->addMenu("编辑");

    //文件-菜单 添加菜单项Action
    QAction *newAction = fileMenu->addAction("新建");
    //文件-菜单 添加分割线
    fileMenu->addSeparator();
    //文件-菜单 添加菜单项Action
    QAction *openAction = fileMenu->addAction("打开");
    //编辑-菜单 添加菜单项Action
    QAction *copyAction = editMenu->addAction("复制文字");


    // 2.工具栏
    // 工具栏  可以有多个
    // 创建工具栏
    QToolBar *toolBar = new QToolBar (this);
    // 当前窗口 添加工具栏（将工具栏放入到当前窗口中）
    this->addToolBar(Qt::LeftToolBarArea, toolBar); //关联当前窗口 //默认停靠范围

    //工具栏 只允许左右侧停靠
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    //工具栏 设置可否浮动
    toolBar->setFloatable(false); // 默认true
    //设置移动 （可否移动总开关）
    toolBar->setMovable(false);

    //创建工具项Action
    QAction *editAction = toolBar->addAction("编辑");
    //工具栏 添加工具项Action
    toolBar->addAction(editAction); //编辑

    // 工具栏 添加小控件
    QPushButton *btn = new QPushButton("控件", this); // 按钮
    toolBar->addWidget(btn);

    //工具栏 添加工具项Action（菜单项Actio）
    toolBar->addAction(newAction); // 新建
    //工具栏 添加分割线
    toolBar->addSeparator();
    //工具栏 添加工具项Action（菜单项Actio）
    toolBar->addAction(openAction); //打开


    // 3.状态栏
    //状态栏 只能有一个
    // 创建状态栏
    QStatusBar *stBar = statusBar();
    // 当前窗口 设置状态栏（将状态栏放入到当前窗口中）
    this->setStatusBar(stBar); // 关联当前窗口
    // 创建标签控件
    QLabel *label = new QLabel("状态栏-提示信息", this);
    // 状态栏 添加标签
    stBar->addWidget(label); //添加提示信息到左侧
    // 创建标签控件
    QLabel *label2 = new QLabel("右侧提示信息", this);
    stBar->addPermanentWidget(label2); //添加右侧提示信息


    // 4.浮动窗口
    // 浮动窗口 可以有多个
    // 创建浮动窗口
    QDockWidget *dock = new QDockWidget("浮动窗口",this);

    // 当前窗口 添加浮动窗口（将浮动窗口放入到当前窗口中）
    this->addDockWidget(Qt::BottomDockWidgetArea, dock); // 关联当前窗口

    //设置停靠范围
    dock->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);


    // 5.文本框(核心部件)
    // 创建文本框
    QTextEdit *edit = new QTextEdit; //文本编辑框
    // 设置核心部件 只能一个（将文本框放入到当前窗口中，作为核心部件）
    this->setCentralWidget(edit); // 关联当前窗口
}

MainWindow::~MainWindow() {}
