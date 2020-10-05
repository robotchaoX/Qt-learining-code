#include "smallwidget.h"
#include "ui_smallwidget.h"

SmallWidget::SmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWidget)
{
    ui->setupUi(this);

    // 自定义控件 SmallWidget
    // 将QSpinBox 和 Slider 绑定为一个新的自定义控件 SmallWidget

    //QSpinBox移动 Slider跟着移动
    void(QSpinBox:: * signal)(int) = &QSpinBox::valueChanged; // 有重载，成员函数指针
    connect(ui->spinBox,signal,ui->horizontalSlider,&QSlider::setValue);

    //Slider移动  SpinBox跟着移动
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);

}

void SmallWidget::setValue(int v)
{
    ui->spinBox->setValue(v);
}

int SmallWidget::getValue()
{
    return ui->spinBox->value();

}

SmallWidget::~SmallWidget()
{
    delete ui;
}
