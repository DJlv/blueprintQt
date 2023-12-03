//
// Created by admin on 2023/11/1.
//

#ifndef TEST_MAINWINDOW_H
#define TEST_MAINWINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include "Variable/BP_Variable.h"
#include "View/BP_GridBackgroundView.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    void init();
private:
    QGraphicsScene *scene;
    Ui::MainWindow *ui;

    void testAddNode();
};


#endif //TEST_MAINWINDOW_H
