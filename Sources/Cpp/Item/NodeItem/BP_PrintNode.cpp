//
// Created by admin on 2023/11/16.
//

#include "Item/NodeItem/BP_PrintNode.h"
BP_PrintNode::BP_PrintNode(QGraphicsItem* parent): BP_BaseNode(parent) {
    setNodeTitle("print");
}

QRectF BP_PrintNode::boundingRect() const {
    return QRectF(0, 0, 200, 100); // 定义节点的边界矩形
}

void BP_PrintNode::Simulation() {
    qDebug() << "print";
}
