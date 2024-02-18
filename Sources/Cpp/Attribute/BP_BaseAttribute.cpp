//
// Created by admin on 2024/2/15.
//

#include "Variable/BP_Variable.h"

void BP_BaseAttribute::handleButtonClicked(BP_BasePort *nodeport) {

}

BP_BaseAttribute::BP_BaseAttribute(QWidget *parent) {

}

void BP_BaseAttribute::clearLayout(QLayout *layout) {
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

void BP_BaseAttribute::endLayout() {

}

void BP_BaseAttribute::initPortAttribute() {
    QVBoxLayout *groupBoxLayout = qobject_cast<QVBoxLayout *>(BP_Variable::qGroupBox->layout());
    if (groupBoxLayout != nullptr) {
        BP_BaseAttribute::clearLayout(groupBoxLayout);
    }
    this->layout = new QVBoxLayout();
    if (groupBoxLayout == nullptr) {
        BP_Variable::qGroupBox->setLayout(this->layout);
    }
}