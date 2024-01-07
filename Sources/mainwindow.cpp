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
    BP_GroupBox* groupBox = new BP_GroupBox();

    //    QLabel* label = new QLabel("Label Text", ui->groupBox); // 将标签添加到 QGroupBox
//    QPushButton* button = new QPushButton("Button Text", ui->groupBox); // 将按钮添加到 QGroupBox
////
//    QVBoxLayout* layout = new QVBoxLayout(ui->groupBox); // 使用垂直布局管理器
//    lineEdit = new QLineEdit();
//    layout->addWidget(lineEdit);
//    layout->addWidget(button);



//    QObject::connect(button, SIGNAL(clicked()), this, SLOT(handleButtonClicked()));

    ItemTest* vo = new ItemTest;

    QObject::connect(ui->graphicsView, SIGNAL(buttonClicked()), vo, SLOT(handleButtonClicked()));
    QObject::connect(ui->graphicsView, SIGNAL(buttonClicked()), groupBox, SLOT(handleButtonClicked()));
    update();
}
void MainWindow::handleButtonClicked() {
//    setTitle("Button clicked!");
//    QLabel* label = new QLabel("Label Text", ui->groupBox); // 将标签添加到 QGroupBox
//    QPushButton* button = new QPushButton("Button Text", ui->groupBox); // 将按钮添加到 QGroupBox
//
//    QVBoxLayout* layout = new QVBoxLayout(ui->groupBox); // 使用垂直布局管理器
//    layout->addWidget(label);
//    layout->addWidget(button);


//    new ItemTest(ui->groupBox);

    qDebug() << "windows::::"<< lineEdit->text();

}

