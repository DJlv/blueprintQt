//
// Created by admin on 2023/11/24.
//

#include "Item/PortItem/BP_ExecPort.h"
BP_ExecPort::BP_ExecPort(PinType type,QGraphicsItem* parent): BP_BasePort(parent) {
    BP_BasePort::Title = "print";
    BP_BasePort::Color = "#00EEEE";
    BP_BasePort::port_type = type;
    update();
}

QRectF BP_ExecPort::boundingRect() const {
    return QRectF(0, 0, 15, 15); // 定义节点的边界矩形
}

BP_ExecPort::BP_ExecPort(QGraphicsItem *parent) : BP_BasePort(parent) {
    BP_BasePort::Title = "print";
    BP_BasePort::Color = "#00EEEE";
    BP_BasePort::port_type = PinType::port_type_port_in;
}


void BP_ExecPort::Simulation() {
    qDebug() << "print";
}

void BP_ExecPort::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QFont font("SimSun", 12);  // 创建字体对象并指定字体名称和大小
    painter->setFont(font);
    QPen pen_default = QPen(QColor(port_color));
    pen_default.setWidthF(1.5);
    QBrush brush_default = QBrush(QColor(port_color));
    painter->setPen(pen_default);
    painter->setBrush(Qt::NoBrush);
    if (port_type == PinType::port_type_port_in) {
        painter->drawText(InTiTle.size() * 2 + 20, 12, InTiTle);
    } else if (port_type == PinType::port_type_port_out) {
        painter->drawText(-OutTitle.size() * 2 - 20 - 5, 12, OutTitle);
    }
    if(!flage) {
        painter->drawEllipse(0, 0, 15, 15);
    } else {
        QColor color("#07e006");
        painter->setBrush(color);  // 设置填充颜色或样式
        painter->drawEllipse(0, 0, 15, 15);
        painter->drawEllipse(0, 0, 15, 15);
    }
    if(edgeList.size() > 0) {
        flage = true;
    } else {
        flage = false;
    }
    update();
}