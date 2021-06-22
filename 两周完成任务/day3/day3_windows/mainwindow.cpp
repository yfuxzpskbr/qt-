#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    resize(600,400);    //重置窗口大小
    QMenuBar *bar = menuBar(); //创建菜单栏  菜单栏只能有一个
    setMenuBar(bar);    //设置菜单栏，只有设置了才会在窗口中显示

    QMenu *fileMenu = bar->addMenu("文件");  //添加文件菜单
    QMenu *editMenu = bar->addMenu("编辑");  //添加编辑菜单

    QAction *newAction = fileMenu->addAction("新建");  //在文件菜单中新建新建菜单项
    QAction *openAction = fileMenu->addAction("打开");  //在文件菜单中新建打开菜单项

    fileMenu->addSeparator();   //在文件菜单中新建一条分割线，位于打开菜单项下方

    fileMenu->addAction("保存");  //在文件菜单中新建保存菜单项
    fileMenu->addAction("另存为");  //在文件菜单中新建另存为菜单项

    fileMenu->addSeparator();  //在文件菜单中新建一条分割线

    fileMenu->addAction("打印"); //在文件菜单中新建打印菜单项
    fileMenu->addAction("退出"); //在文件菜单中新建退出菜单项

    //在编辑菜单中新建撤销、复制、剪切、粘贴菜单项
    QAction *undoAction = editMenu->addAction("撤销");
    QAction *copyAction = editMenu->addAction("复制");
    editMenu->addSeparator();  //添加分割线
    QAction *catAction = editMenu->addAction("剪切");
    QAction *stickAction = editMenu->addAction("粘贴");
    editMenu->addSeparator();  //添加分割线

    //在编辑菜单中添加删除和全选菜单项
    editMenu->addAction("删除");
    editMenu->addAction("全选");

    QToolBar *tbar = new QToolBar(this);  //创建一个工具栏  工具栏可以有多个
    addToolBar(Qt::LeftToolBarArea,tbar);  //让他默认在窗口左侧停靠

    //添加内容
    tbar->addAction(newAction);
    tbar->addAction(openAction);

    tbar->addAction(undoAction);
    tbar->addAction(copyAction);
    tbar->addAction(catAction);
    tbar->addAction(stickAction);

    tbar->setAllowedAreas(Qt::TopToolBarArea|Qt::LeftToolBarArea);  //设置允许停靠位置为上和左
    /*tbar->setMovable(false);  //设置禁止移动*/
    tbar->setFloatable(false);  //设置禁止浮动

    //还可以添加控件
    QPushButton  *btn = new QPushButton("关闭",this);
    tbar->addWidget(btn);

    connect(btn,&QPushButton::clicked,this,&QMainWindow::close);


    //添加状态栏  最多只能有一个
    QStatusBar *sbar = statusBar();
    setStatusBar(sbar);

    //添加标签
    QLabel *lab = new QLabel("提示信息",this);
    sbar->addWidget(lab);
    //添加右侧标签
    QLabel *lab2 = new QLabel("右侧信息",this);
    sbar->addPermanentWidget(lab2);


    //添加铆接部件 即浮动窗口 可以多个
    QDockWidget *dock = new QDockWidget("铆接部件",this);
    addDockWidget(Qt::RightDockWidgetArea,dock);  //设置默认停靠在右侧
    dock->setAllowedAreas(Qt::RightDockWidgetArea|Qt::BottomDockWidgetArea); //设置允许停靠区域

    //设置核心部件，只能一个
    QTextEdit *text = new QTextEdit(this);
    setCentralWidget(text);

}

MainWindow::~MainWindow()
{
    delete ui;
}
