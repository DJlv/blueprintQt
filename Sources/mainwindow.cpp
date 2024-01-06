// Created by admin on 2023/11/1.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "Forms/ui_MainWindow.h"
#include "Scence/BP_GridGroupScence.h"
#include <QGraphicsSimpleTextItem>
MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::init() {
//    BP_Variable::AddNodeToList();
    BP_Variable::NodeLists.append(new BP_ProgramEntry);
    scene = new BP_GridGroupScence();
//    scene->addItem(item);
    for(BP_BaseNode *item: BP_Variable::NodeLists) {
        /** 项添加到场景*/
        item->setPos(160,160);
        scene->addItem(item);
    }

    ui->graphicsView->setScene(scene);
    QString st="添加一行";
    ui->textEdit->insertPlainText(st +='\n');
    update();
}


