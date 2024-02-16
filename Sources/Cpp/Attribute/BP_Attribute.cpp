//
// Created by admin on 2024/2/15.
//

#include "Variable/BP_Variable.h"

void BP_Attribute::handleButtonClicked(BP_BasePort *nodeport) {

}

BP_Attribute::BP_Attribute(QWidget *parent) {

}

void BP_Attribute::clearLayout(QLayout *layout) {
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

void BP_Attribute::endLayout() {

}

void BP_Attribute::initPortAttribute() {
    QVBoxLayout *groupBoxLayout = qobject_cast<QVBoxLayout *>(BP_Variable::qGroupBox->layout());
    if (groupBoxLayout != nullptr) {
        BP_Attribute::clearLayout(groupBoxLayout);
    }
    this->layout = new QVBoxLayout();
    if (groupBoxLayout == nullptr) {
        BP_Variable::qGroupBox->setLayout(this->layout);
    }
}