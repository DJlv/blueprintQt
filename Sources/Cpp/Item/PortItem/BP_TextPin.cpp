//
// Created by admin on 2024/1/6.
//

#include "Item/PortItem/BP_TextPin.h"

BP_TextPin::BP_TextPin(QGraphicsItem *parent) : BP_BasePort(parent) {
}

QRectF BP_TextPin::boundingRect() const {
    return QRectF(0,0,15,15);
}

BP_TextPin::BP_TextPin(PinType type, QGraphicsItem *parent) : BP_BasePort(type, parent) {
    qDebug() << "1111111111";
    BP_BasePort::Title ="text1111";
    BP_BasePort::Color = "#8B008B";
}
