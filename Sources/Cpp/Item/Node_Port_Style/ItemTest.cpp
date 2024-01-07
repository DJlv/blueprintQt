//
// Created by admin on 2024/1/7.
//

#include <QPushButton>
#include <QCoreApplication>
#include <QLabel>
#include <QVBoxLayout>
#include "Item/Node_Port_Style/ItemTest.h"
#include "Variable/BP_Variable.h"
#include "Item/NodeItem/BP_PrintNode.h"

ItemTest::ItemTest(QWidget *parent) {

}

void ItemTest::handleButtonClicked() {
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("请输入文本"); // 设置占位符文本;
//    lineEdit->setText("12333333");
    connect(lineEdit, SIGNAL(editingFinished()), this,  SLOT(buttonClicked()));
//    connect(lineEdit, SIGNAL(editingFinished()), x,  SLOT(slotLineEdit(QString)));
    qDebug() << "init--------x::::"<< lineEdit->text();


    QLabel* label = new QLabel("Label Text", BP_Variable::qGroupBox); // 将标签添加到 QGroupBox
    label->setFixedSize(200, 30);
    QLabel* label1 = new QLabel("Label Text1", BP_Variable::qGroupBox); // 将标签添加到 QGroupBox
    label1->setFixedSize(200, 30);
    button = new QPushButton("打印x", BP_Variable::qGroupBox); // 将按钮添加到 QGroupBox
    button->setFixedSize(100, 30);
    connect(button,  &QPushButton::clicked, this,  &ItemTest::buttonClicked);

    QVBoxLayout* layout = new QVBoxLayout(BP_Variable::qGroupBox); // 使用垂直布局管理器

    layout->addWidget(lineEdit);
    layout->addWidget(button);
    layout->addWidget(label1);
    layout->addWidget(label);
    layout->addStretch();
    BP_PrintNode* x = new BP_PrintNode;

    connect(this,SIGNAL(pushStyle(QString)),x, SLOT(slotLineEdit(QString)));
}

void ItemTest::buttonClicked() {

//    qDebug() << "lineEdit->text()--------" <<lineEdit->text();
    emit(pushStyle(lineEdit->text()));
}



