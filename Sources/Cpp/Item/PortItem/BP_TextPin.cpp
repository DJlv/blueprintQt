//
// Created by admin on 2024/1/6.
//

#include <QPushButton>
#include <QCoreApplication>
#include "Item/PortItem/BP_TextPin.h"

BP_TextPin::BP_TextPin(QGraphicsItem *parent) : BP_BasePort(parent) {
}

QRectF BP_TextPin::boundingRect() const {
    return BP_BasePort::path.boundingRect();
}

BP_TextPin::BP_TextPin(PinType type, QGraphicsItem *parent) : BP_BasePort(type, parent) {
    BP_BasePort::Title ="text";
    BP_BasePort::Color = "#fbf123";
    BP_BasePort::port_type = type;
}

void BP_TextPin::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    path.clear();

    if(BP_BasePort::port_type == PinType::port_type_port_out || BP_BasePort::port_type == PinType::port_type_port_in) {
        QFont font("SimSun", 12);  // 创建字体对象并指定字体名称和大小
        painter->setFont(font);
        QPen pen_default = QPen(QColor(Color));
        painter->setPen(pen_default);
        if (edgeList.size() > 0) {
            painter->setPen(pen_default);
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
    }
    if(BP_BasePort::port_type == PinType::port_type_out || BP_BasePort::port_type == PinType::port_type_in) {
        QFont font("SimSun", 12);  // 创建字体对象并指定字体名称和大小
        painter->setFont(font);
        QPen pen_default = QPen("#FFFFFF");
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
    this->update();
}

void BP_TextPin::Simulation() {
    qDebug() << "开始执行Simulation 函数" << itemssd;
}

void BP_TextPin::slotLineEdit(QString text) {
//    qDebug() << "点击按钮修改节点数据:" << text;
    itemssd = text;
}