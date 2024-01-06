//
// Created by admin on 2023/11/24.
//

#include "Port/BP_BasePort.h"


void BP_BasePort::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QFont font("Consolas", 12);  // 创建字体对象并指定字体名称和大小
    painter->setFont(font);
    QPen pen_default = QPen(QColor(Color));
    pen_default.setWidthF(1.5);
    QBrush brush_default = QBrush(QColor(Color));
    painter->setPen(pen_default);
    painter->setBrush(Qt::NoBrush);
    if (port_type == PinType::port_type_port_in) {
        painter->drawText(Title.size() * 2 + 20, 12, Title);
    } else if (port_type == PinType::port_type_port_out) {
        painter->drawText(-Title.size() * 2 - 20 - 15, 12, Title);
    }
    if(!flage) {
        painter->drawEllipse(0, 0, 15, 15);
    } else {
        QColor color(Color);
        painter->setBrush(color);  // 设置填充颜色或样式
        painter->drawEllipse(0, 0, 15, 15);
        painter->drawEllipse(0, 0, 15, 15);
    }
    if(edgeList.size() > 0) {
        flage =true;
    } else {
        flage =false;
    }
    QGraphicsSimpleTextItem
    update();
}

void BP_BasePort::add_Edge(BP_Edge* edgeItem)
{
    edgeList.append(edgeItem);
}

BP_BasePort::BP_BasePort(QGraphicsItem* parent){
}

BP_BasePort::BP_BasePort(PinType type, QGraphicsItem *parent) : QGraphicsItem(parent), port_type(type) {
    update();
}

void BP_BasePort::add_to_parent_node(BP_BaseNode* nodeItem) {
    node = nodeItem;
}

void BP_BasePort::Simulation() {
    qDebug() << "print";
}