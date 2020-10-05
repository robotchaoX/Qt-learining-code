#ifndef SMALLWIDGET_H
#define SMALLWIDGET_H

#include <QWidget>

namespace Ui {
class SmallWidget;
}

class SmallWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SmallWidget(QWidget *parent = 0);
    ~SmallWidget();

    // 对外接口，调用自定义控件方法
    void setValue(int v);
    int getValue();


private:
    Ui::SmallWidget *ui;
};

#endif // SMALLWIDGET_H
