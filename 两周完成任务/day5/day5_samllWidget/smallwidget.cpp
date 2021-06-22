#include "smallwidget.h"
#include "ui_smallwidget.h"
#include "QSpinBox"
#include <QSlider>
smallwidget::smallwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::smallwidget)
{
    ui->setupUi(this);
    void (QSpinBox:: *signal)(int)=&QSpinBox::valueChanged;
    connect(ui->spinBox,signal,[=](int a){
        ui->horizontalSlider->setValue(a);
    });
    connect(ui->horizontalSlider,QSlider::valueChanged,[=](int a){
       ui->spinBox->setValue(a);
    });
}

void smallwidget::setValue(int value){
    ui->spinBox->setValue(value);
}

int smallwidget::getValue(){
    return ui->spinBox->value();
}




smallwidget::~smallwidget()
{
    delete ui;
}
