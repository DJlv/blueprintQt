//
// Created by admin on 2024/1/7.
//

#include <QPushButton>
#include <QCoreApplication>
#include <QLabel>
#include "Item/Node_Port_Style/ItemTest.h"
#include "Variable/BP_Variable.h"
#include "Item/PortItem/BP_TextPin.h"

ItemTest::ItemTest(QWidget *parent) {
    QVBoxLayout *groupBoxLayout = qobject_cast<QVBoxLayout *>(BP_Variable::qGroupBox->layout());
    if (groupBoxLayout != nullptr) {
        clearLayout(groupBoxLayout);
    }
    layout = new QVBoxLayout();
    BP_Variable::qGroupBox->setLayout(layout);
}

void ItemTest::handleButtonClicked(BP_BasePort *nodeport) {
    nodeportItem = nodeport;
    lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("请输入文本"); // 设置占位符文本;
    connect(lineEdit, SIGNAL(editingFinished()), this, SLOT(buttonClicked()));
    QLabel *label = new QLabel("Label Text", BP_Variable::qGroupBox); // 将标签添加到 QGroupBox
    label->setFixedSize(200, 30);
    QLabel *label1 = new QLabel("Label Text1", BP_Variable::qGroupBox); // 将标签添加到 QGroupBox
    label1->setFixedSize(200, 30);
    button = new QPushButton("打印x", BP_Variable::qGroupBox); // 将按钮添加到 QGroupBox
    button->setFixedSize(100, 30);
    connect(button, &QPushButton::clicked, this, &ItemTest::buttonClicked);

    layout->addWidget(lineEdit);
    layout->addWidget(button);
    layout->addWidget(label1);
    layout->addWidget(label);
    layout->addStretch();

    connect(this, SIGNAL(pushStyle(QString)), nodeportItem, SLOT(slotLineEdit(QString)));
}

void ItemTest::buttonClicked() {
    emit(pushStyle(lineEdit->text()));
    disconnect(this, SIGNAL(pushStyle(QString)), nodeportItem, SLOT(slotLineEdit(QString)));
    nodeportItem = nullptr;
    update();
}


void ItemTest::clearLayout(QLayout *layout) {
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr) {
        if (item->widget() != nullptr) {
            delete item->widget();
        }
        if (item->layout() != nullptr) {
            clearLayout(item->layout());
        }
        delete item;
    }
}

ItemTest &ItemTest::operator=(const ItemTest *po) {
    delete po;
    ItemTest *item = new ItemTest;
    return *this;
}
