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


void BP_BasePort::InOutStyle(QPainter *painter) {
    if(port_type == port_type_out || port_type == port_type_in) {
        QFont font("SimSun", 12);  // 创建字体对象并指定字体名称和大小
        painter->setFont(font);
        QPen pen_default = QPen("#FFFFFF");
        if (edgeList.size() > 0) {
            painter->setPen(pen_default);
            painter->setBrush(QColor("#FFFFFF"));  // 设置填充颜色或样式
        }
        pen_default.setWidth(2);
        painter->setPen(pen_default);
        QPainterPath pathss;
        pathss.moveTo(10,5);
        pathss.lineTo(20, 5);
        pathss.lineTo(30, 15);
        pathss.lineTo(20, 25);
        pathss.lineTo(10, 25);
        pathss.lineTo(10, 5);
        pathss.closeSubpath();
        path.addPath(pathss);
        painter->drawPath(pathss);
    }
}

void BP_BasePort::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    path.clear();
    BP_BasePort::InOutStyle(painter);
    paintChildren(painter,option,widget);
    this->update();
}
void BP_BasePort::paintChildren(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

}

QRectF BP_BasePort::boundingRect() const {
    return BP_BasePort::path.boundingRect();
}
