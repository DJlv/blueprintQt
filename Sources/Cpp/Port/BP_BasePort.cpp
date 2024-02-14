//
// Created by admin on 2023/11/24.
//

#include "Port/BP_BasePort.h"




void BP_BasePort::add_Edge(BP_Edge *edgeItem) {
    n++;
    qDebug() << "n的数据为：" << n;
    edgeList.append(edgeItem);
}

BP_BasePort::BP_BasePort(QGraphicsItem *parent) {
//    update();
}

BP_BasePort::BP_BasePort(PinType type, QGraphicsItem *parent) : QGraphicsItem(parent), port_type(type) {
    setCacheMode(QGraphicsItem::DeviceCoordinateCache);
}

void BP_BasePort::add_to_parent_node(BP_BaseNode *nodeItem) {
    node = nodeItem;
}

void BP_BasePort::Simulation() {
    qDebug() << "print";
}


