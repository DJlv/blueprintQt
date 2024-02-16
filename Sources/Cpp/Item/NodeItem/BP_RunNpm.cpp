//
// Created by admin on 2024/2/15.
//

#include "Item/NodeItem/BP_RunNpm.h"
#include "Item/PortItem/BP_TextPin.h"
#include "Item/PortItem/BP_RunNpmPort.h"

BP_RunNpm::BP_RunNpm(QGraphicsItem *parent) : BP_BaseNode(parent) {
    BP_BaseNode::Title = "RunNpm";
    BP_BaseNode::Color = "#46e407";

    BP_BaseNode::portInList = {
            new BP_RunNpmPort(PinType::port_type_in, this),
            new BP_RunNpmPort(PinType::port_type_port_in, this)
    };
    BP_BaseNode::portOutList = {
            new BP_RunNpmPort(PinType::port_type_out, this)
    };
}
