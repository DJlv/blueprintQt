//
// Created by admin on 2023/11/18.
//

#include "Item/NodeItem/BP_ProgramEntry.h"
BP_ProgramEntry::BP_ProgramEntry(QGraphicsItem* parent): BP_BaseNode(parent) {
    setNodeTitle("Run");
}

QRectF BP_ProgramEntry::boundingRect() const {
    return QRectF(0, 0, 200, 100); // 定义节点的边界矩形
}

void BP_ProgramEntry::Simulation() {
    qDebug() << "Run";
}