#include <QApplication>
#include "mainwindow.h"
#include <QDebug>

#include<iostream>
#include <QGraphicsScene>
#include <QGraphicsView>
using namespace std;
int main (int argc, char *argv[])
{
    QApplication a (argc, argv);
    a.setStyleSheet("background-color: red;"); // 设置背景色为红色
    MainWindow w;
    w.show ();
    return QApplication::exec ();
}
