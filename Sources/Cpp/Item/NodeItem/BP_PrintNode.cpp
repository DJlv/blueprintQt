//
// Created by admin on 2023/11/16.
//

#include "Item/NodeItem/BP_PrintNode.h"
#include "Item/PortItem/BP_TextPin.h"
#include <QPushButton>
#include <QCoreApplication>
#include <QLabel>
#include <QVBoxLayout>
#include <QLineEdit>

BP_PrintNode::BP_PrintNode(QGraphicsItem *parent) : BP_BaseNode(parent) {
    BP_BaseNode::Title = "print";
    BP_BaseNode::Color = "#00EEEE";

    BP_BaseNode::portInList = {
            new BP_TextPin(PinType::port_type_in, this),
            new BP_TextPin(PinType::port_type_port_in, this)
    };
    BP_BaseNode::portOutList = {
            new BP_TextPin(PinType::port_type_out, this)
    };
}


void BP_PrintNode::Simulation() {
    qDebug() << "BP_PrintNode---------开始执行Simulation 函数:" << itemNode;
}
