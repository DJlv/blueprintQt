//
// Created by admin on 2023/11/16.
//

#include "Item/NodeItem/BP_PrintNode.h"
#include "Item/PortItem/BP_TextPin.h"
#include <QPushButton>
#include <QCoreApplication>
#include <QLabel>
#include <QVBoxLayout>
#include <QLineEdit>

BP_PrintNode::BP_PrintNode(QGraphicsItem *parent) : BP_BaseNode(parent) {
    BP_BaseNode::Title = "print";
    BP_BaseNode::Color = "#00EEEE";

    BP_BaseNode::portInList = {new BP_TextPin(PinType::port_type_port_in, this),
                               new BP_TextPin(PinType::port_type_port_in, this)};
    BP_BaseNode::portOutList = {
            new BP_TextPin(PinType::port_type_port_out, this),
            new BP_TextPin(PinType::port_type_port_out, this),
            new BP_TextPin(PinType::port_type_port_out, this),
            new BP_TextPin(PinType::port_type_port_out, this),
            new BP_TextPin(PinType::port_type_port_out, this),
            new BP_TextPin(PinType::port_type_port_out, this),
            new BP_TextPin(PinType::port_type_port_out, this),
            new BP_TextPin(PinType::port_type_port_out, this),
            new BP_TextPin(PinType::port_type_port_out, this),
            new BP_TextPin(PinType::port_type_port_out, this),
            new BP_TextPin(PinType::port_type_port_out, this),
            new BP_TextPin(PinType::port_type_port_out, this),
            new BP_TextPin(PinType::port_type_port_out,this)
    };
}

QRectF BP_PrintNode::boundingRect() const {
    return QRectF(0, 0, 200, BP_BaseNode::portInList.size() * BP_BaseNode::height > BP_BaseNode::portOutList.size() * BP_BaseNode::height ?
                             BP_BaseNode::portInList.size() * BP_BaseNode::height : BP_BaseNode::portOutList.size() * BP_BaseNode::height); // 定义节点的边界矩形
}

void BP_PrintNode::Simulation() {

}

void BP_PrintNode::SimulationStyle() {

}

void BP_PrintNode::slotButton() {
    QString text = lineEdit->text();
    x = text;
    qDebug() << "print--------x::::" << x;
}

void BP_PrintNode::slotLineEdit(QString text) {
    qDebug() << "lineEdit->text()--------lineEdit->text()::::" << text;

}

void BP_PrintNode::mousePressEvent(QGraphicsSceneMouseEvent *event) {
}

