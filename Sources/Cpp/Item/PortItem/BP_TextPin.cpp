//
// Created by admin on 2024/1/6.
//

#include <QPushButton>
#include <QCoreApplication>
#include <QDateTime>
#include "Item/PortItem/BP_TextPin.h"
#include "Variable/BP_Variable.h"

BP_TextPin::BP_TextPin(QGraphicsItem *parent) : BP_BasePort(parent) {
}

QRectF BP_TextPin::boundingRect() const {
    return BP_BasePort::path.boundingRect();
}

BP_TextPin::BP_TextPin(PinType type, QGraphicsItem *parent) : BP_BasePort(type, parent) {
    BP_BasePort::Title ="打印日志";
    BP_BasePort::Color = "#fbf123";
    BP_BasePort::port_type = type;
    BP_BasePort::attribute = new ItemTest;
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
//            QRect rect(0, 0, 40, 20); // 圆形的外接矩形
            QRectF rect(0, 0, 60, 15);
            path.addRect(rect);
            painter->drawPath(path);

        } else {
            QRectF rect(0, 0, 60, 15);

//            QRect rect(0, 0, 40, 20); // 圆形的外接矩形
            path.addRect(rect);
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
            pathText.addText(Title.size() + 60, 12,font, Title);
            painter->drawText(Title.size() + 60, 12,Title);
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
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString formattedDateTime = currentDateTime.toString("yyyyMMdd hh:mm:ss");
    QString str = BP_Variable::console->toPlainText()+formattedDateTime + "------打印日志:" + itemssd+"\n";
    BP_Variable::console->setPlainText(str);
    update();
}

void BP_TextPin::slotLineEdit(QString text) {
    itemssd = text;
}