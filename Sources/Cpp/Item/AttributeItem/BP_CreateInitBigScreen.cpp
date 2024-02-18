//
// Created by admin on 2024/2/17.
//

#include "Item/AttributeItem/BP_CreateInitBigScreen.h"

BP_CreateInitBigScreen::BP_CreateInitBigScreen(QWidget *parent) : BP_BaseAttribute(parent) {

}

void BP_CreateInitBigScreen::handleButtonClicked(BP_BasePort *nodeport) {
    BP_BaseAttribute::initPortAttribute();
    nodeportItem = nodeport;

    label = new QLabel("日志文本:", BP_Variable::qGroupBox); // 将标签添加到 QGroupBox
    label->setFixedSize(70, 30);
    lineEdit = new QLineEdit();
    lineEdit->setFixedSize(250, 30);
    lineEdit->setPlaceholderText("请输入文本"); // 设置占位符文本;

    connect(lineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(lableClicked()));
    endLayout();
}
void BP_CreateInitBigScreen::endLayout() {
    QVBoxLayout *groupBoxLayout = qobject_cast<QVBoxLayout *>(BP_Variable::qGroupBox->layout());
    QHBoxLayout *qHBoxLayout1 = new QHBoxLayout();
    qHBoxLayout1->addWidget(label);
    qHBoxLayout1->addWidget(lineEdit);
    groupBoxLayout->addLayout(qHBoxLayout1);
    groupBoxLayout->addStretch();
}


void BP_CreateInitBigScreen::lableClicked() {
    connect(this, SIGNAL(pushStyle(BP_BaseSignal*)), nodeportItem, SLOT(slotLineEdit(BP_BaseSignal*)));
    signleItem = new BP_CreateInitSignal;
    if (lineEdit->text() != orglinight) {
        signleItem->text = lineEdit->text();
        emit(pushStyle(signleItem));
        orglinight = lineEdit->text();
    }
    disconnect(this, SIGNAL(pushStyle(BP_BaseSignal*)), nodeportItem, SLOT(slotLineEdit(BP_BaseSignal*)));
    update();
}
