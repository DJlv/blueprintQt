//
// Created by admin on 2024/1/6.
//

#include "BP_GroupBox/BP_GroupBox.h"
#include "Variable/BP_Variable.h"
#include "Item/Node_Port_Style/ItemTest.h"

void BP_GroupBox::handleButtonClicked() {
    for (BP_BaseNode *item: BP_Variable::NodeLists) {
        item->SimulationStyle();
    }
}

BP_GroupBox::BP_GroupBox(QWidget *parent) : QGroupBox(parent) {

}