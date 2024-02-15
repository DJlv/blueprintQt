//
// Created by admin on 2024/1/7.
//

#include <QPushButton>
#include <QCoreApplication>
#include "Variable/BP_Variable.h"
#include "Item/PortItem/BP_TextPin.h"
#include "Item/AttributeItem/ItemTest.h"


ItemTest::ItemTest(QWidget *parent) {

}

void ItemTest::handleButtonClicked(BP_BasePort *nodeport) {
    BP_Attribute::initPortAttribute();
    nodeportItem = nodeport;
    label = new QLabel("需要打印的日志", BP_Variable::qGroupBox); // 将标签添加到 QGroupBox
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("请输入文本"); // 设置占位符文本;
//    connect(lineEdit, SIGNAL(editingFinished()), this, SLOT(buttonClicked()));
    connect(lineEdit, &QLineEdit::textChanged, this, &ItemTest::buttonClicked);

//    QLabel *label = new QLabel("Label Text", BP_Variable::qGroupBox); // 将标签添加到 QGroupBox
//    label->setFixedSize(200, 30);
//    QLabel *label1 = new QLabel("Label Text1", BP_Variable::qGroupBox); // 将标签添加到 QGroupBox
//    label1->setFixedSize(200, 30);
//    button = new QPushButton("打印x", BP_Variable::qGroupBox); // 将按钮添加到 QGroupBox
//    button->setFixedSize(100, 30);
//    connect(button, &QPushButton::clicked, this, &ItemTest::buttonClicked);

    endLayout();

}

void ItemTest::endLayout() {
    QVBoxLayout *groupBoxLayout = qobject_cast<QVBoxLayout *>(BP_Variable::qGroupBox->layout());
    groupBoxLayout->addWidget(lineEdit);
    groupBoxLayout->addWidget(label);
    groupBoxLayout->addStretch();
}


void ItemTest::buttonClicked() {
    connect(this, SIGNAL(pushStyle(QString)), nodeportItem, SLOT(slotLineEdit(QString)));
    connect(lineEdit, SIGNAL(editingFinished()), this, SLOT(buttonClicked()));
    if(lineEdit->text() != orglinight) {
        emit(pushStyle(lineEdit->text()));
        orglinight = lineEdit->text();
    }
    disconnect(lineEdit, SIGNAL(editingFinished()), this, SLOT(buttonClicked()));
    disconnect(this, SIGNAL(pushStyle(QString)), nodeportItem, SLOT(slotLineEdit(QString)));
    update();
}


