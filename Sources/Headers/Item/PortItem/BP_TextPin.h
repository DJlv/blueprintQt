//
// Created by admin on 2024/1/6.
//

#ifndef BLUEPRINT_BP_TEXTPIN_H
#define BLUEPRINT_BP_TEXTPIN_H


#include <QGraphicsItem>
#include "Port/BP_BasePort.h"
#include <QtWidgets/QGroupBox>

class BP_TextPin : public BP_BasePort {
Q_OBJECT

public:
    explicit BP_TextPin(QGraphicsItem *parent = nullptr);

    explicit BP_TextPin(PinType type, QGraphicsItem *parent = nullptr);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    /**节点图形区域大小*/
    QRectF boundingRect() const override;
};


#endif //BLUEPRINT_BP_TEXTPIN_H
