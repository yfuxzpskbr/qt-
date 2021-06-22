#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionnew->setIcon(QIcon(":/Image/Luffy.png"));
    ui->actionsave->setIcon(QIcon(":/Image/Frame.jpg"));
    connect(ui->actionclose,&QAction::triggered,this,[=](){
        close();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
