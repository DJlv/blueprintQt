//
// Created by admin on 2023/11/24.
//

#include "Port/BP_BasePort.h"


void BP_BasePort::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QFont font("SimSun", 12);  // 创建字体对象并指定字体名称和大小
    painter->setFont(font);
    QPen pen_default = QPen(QColor(Color));
    painter->setPen(pen_default);

    if (edgeList.size() > 0) {
        painter->setBrush(QColor(Color));  // 设置填充颜色或样式
        QRect rect(0, 0, 15, 15); // 圆形的外接矩形
        path.addEllipse(rect);
        painter->drawPath(path);
    } else {
        QRect rect(0, 0, 15, 15); // 圆形的外接矩形
        path.addEllipse(rect);
        painter->drawPath(path);
    }
    QPainterPath pathss;

    pathss.moveTo(18, 3);
    pathss.lineTo(23, 7);
    pathss.lineTo(18, 12);
    pathss.lineTo(18,3);
    pathss.closeSubpath();
    painter->setBrush(QColor(Color));  // 设置填充颜色或样式
    painter->drawPath(pathss);
    path.addPath(pathss);
    QPainterPath pathText;
    if (port_type == PinType::port_type_port_in) {
        pathText.addText(Title.size() + 10 + 15, 12,font, Title);
        painter->drawText(Title.size() + 10 + 15, 12,Title);
    } else if (port_type == PinType::port_type_port_out) {
        pathText.addText(-Title.size() * 9, 12,font, Title);
        painter->drawText(-Title.size() * 9, 12,Title);
    }
    path.addPath(pathText);
    this->update();
}

void BP_BasePort::add_Edge(BP_Edge *edgeItem) {
    edgeList.append(edgeItem);
}

BP_BasePort::BP_BasePort(QGraphicsItem *parent) {
    update();
}

BP_BasePort::BP_BasePort(PinType type, QGraphicsItem *parent) : QGraphicsItem(parent), port_type(type) {
    setCacheMode(QGraphicsItem::DeviceCoordinateCache);

    update();
}

void BP_BasePort::add_to_parent_node(BP_BaseNode *nodeItem) {
    node = nodeItem;
}

void BP_BasePort::Simulation() {
    qDebug() << "print";
}