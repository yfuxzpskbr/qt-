#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QtDebug>
#include <QString>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    connect(ui->actionnew,&QAction::triggered,[=](){
//        QDialog *dlg = new QDialog(this);
//        dlg->resize(200,200);
//        dlg->setWindowTitle("模态对话框");
//        qDebug()<<"模态对话框弹出";
//        dlg->exec();


//        QDialog *dlg2 = new QDialog(this);
//        dlg2->resize(300,400);
//        dlg2->show();
//        dlg2->setAttribute(Qt::WA_DeleteOnClose);



//        QMessageBox::information(this,"这是秘密","我爱你哦",QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
//        if(QMessageBox::warning(this,"警告","不要点ok",QMessageBox::No|QMessageBox::Ok,QMessageBox::No)==QMessageBox::Ok){
//            this->close();
//        }

//    if(QMessageBox::Yes == QMessageBox::question(this,"死亡疑问","你爱我吗？",QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes))
//    {
//        QMessageBox::about(this,"太好了","嘻嘻，我也爱你哦");
//    }
//    else {
//        QMessageBox::about(this,"可恶","哼哼，你居然不爱我");
//    }




//        QColor color = QColorDialog::getColor(QColor(255,0,0));
//        qDebug()<<"r = "<<color.red()<<"g = "<<color.green()<<"b = "<<color.blue();

        QString path =  QFileDialog::getOpenFileName(this,"选择文件","D:\\Dev C++","*.cpp");
        qDebug()<<path.toUtf8().data();

    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
