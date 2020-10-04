#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    // treeWidget控件使用
    // 添加头
    ui->treeWidget->setHeaderLabels(QStringList() << "英雄姓名"
                                    << "英雄介绍");

    // 添加项目
    QTreeWidgetItem *liItem = new QTreeWidgetItem(QStringList() << "力量");
    // 添加顶层项目(根节点)
    ui->treeWidget->addTopLevelItem(liItem);
    QTreeWidgetItem *minItem = new QTreeWidgetItem(QStringList() << "敏捷");
    ui->treeWidget->addTopLevelItem(minItem);
    QTreeWidgetItem *zhiItem = new QTreeWidgetItem(QStringList() << "智力");
    ui->treeWidget->addTopLevelItem(zhiItem);

    //字符串
    QStringList heroL1;
    QStringList heroL2;
    QStringList heroM1;
    QStringList heroM2;
    QStringList heroZ1;
    QStringList heroZ2;
    heroL1 << "刚被猪"
           << "前排坦克，能在吸收伤害的同时造成可观的范围输出";
    heroL2 << "船长"
           << "前排坦克，能肉能输出能控场的全能英雄";

    heroM1 << "月骑"
           << "中排物理输出，可以使用分裂利刃攻击多个目标";
    heroM2 << "小鱼人"
           << "前排战士，擅长偷取敌人的属性来增强自身战力";

    heroZ1 << "死灵法师"
           << "前排法师坦克，魔法抗性较高，拥有治疗技能";
    heroZ2 << "巫医"
           << "后排辅助法师，可以使用奇特的巫术诅咒敌人与治疗队友";

    // 追加子项目（子节点） 子项也是QTreeWidgetItem
    QTreeWidgetItem *li1 = new QTreeWidgetItem(heroL1);
    liItem->addChild(li1);
    QTreeWidgetItem *li2 = new QTreeWidgetItem(heroL2);
    liItem->addChild(li2);
    QTreeWidgetItem *Min1 = new QTreeWidgetItem(heroM1);
    minItem->addChild(Min1);
    QTreeWidgetItem *Min2 = new QTreeWidgetItem(heroM2);
    minItem->addChild(Min2);
    QTreeWidgetItem *Zhi1 = new QTreeWidgetItem(heroZ1);
    zhiItem->addChild(Zhi1);
    QTreeWidgetItem *Zhi2 = new QTreeWidgetItem(heroZ2);
    zhiItem->addChild(Zhi2);
}

Widget::~Widget() { delete ui; }
