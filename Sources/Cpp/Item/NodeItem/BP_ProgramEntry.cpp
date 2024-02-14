//
// Created by admin on 2023/11/18.
//

#include "Item/NodeItem/BP_ProgramEntry.h"
#include "Item/PortItem/BP_TextPin.h"

BP_ProgramEntry::BP_ProgramEntry(QGraphicsItem* parent): BP_BaseNode(parent) {
    BP_BaseNode::Title = "Run";
    BP_BaseNode::Color = "#0000EE";
    BP_BaseNode::portOutList = {
            new BP_TextPin(PinType::port_type_out, this)
    };
}



void BP_ProgramEntry::Simulation() {
    qDebug() << "Run";
}

