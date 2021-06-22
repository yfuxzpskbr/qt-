/**
 * @note 主函数
 */

#include "mainscene.h"
#include <QApplication>

/**
 * 程序的入口
 * @brief qMain
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char *argv[])
{
    ///新建一个应用程序a
    QApplication a(argc, argv);
    ///新建一个主场景对象
    MainScene w;
    ///显示主场景
    w.show();
    ///返回消息循环
    return a.exec();
}
