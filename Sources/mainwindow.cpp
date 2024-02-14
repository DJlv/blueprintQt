// Created by admin on 2023/11/1.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "Forms/ui_MainWindow.h"
#include "Scence/BP_GridGroupScence.h"
#include "Item/Node_Port_Style/ItemTest.h"
#include <QGraphicsSimpleTextItem>
#include <QLabel>
#include <QRadioButton>
#include <QPushButton>
#include <QLineEdit>
#include <BP_GroupBox/Bp_GroupBox.h>


MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::init() {
    BP_Variable::qGroupBox = ui->groupBox;
    scene = new BP_GridGroupScence();
    ui->graphicsView->setScene(scene);
    QString st="添加一行";
    ui->textEdit->insertPlainText(st +='\n');
    update();
}


