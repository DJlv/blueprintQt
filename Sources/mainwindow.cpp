// Created by admin on 2023/11/1.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "Forms/ui_MainWindow.h"
#include "Scence/BP_GridGroupScence.h"

MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::init() {
    BP_Variable::AddNodeToList();
    scene = new BP_GridGroupScence();

    for(BP_BaseNode *item: BP_Variable::NodeLists) {
        /** 项添加到场景*/
        item->setPos(16000,16000);
        scene->addItem(item);
        scene->clearSelection();
        item->setSelected(false);
    }

//    testAddNode();
    scene->clearSelection();

    ui->graphicsView->setScene(scene);
}

void MainWindow::testAddNode() {
    BP_BaseNode *item01= new BP_PrintNode;
    item01->setPos(15900,15900);
    scene->addItem(item01);

    BP_BaseNode *item02= new BP_PrintNode;
    item02->setPos(16150,16150);
    scene->addItem(item02);
    scene->clearSelection();
    item01->setSelected(false);
    item02->setSelected(false);

    BP_Variable::NodeLists.append(item01);
    BP_Variable::NodeLists.append(item02);
}

