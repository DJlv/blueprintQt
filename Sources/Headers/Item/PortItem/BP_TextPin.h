//
// Created by admin on 2024/1/6.
//

#ifndef BLUEPRINT_BP_TEXTPIN_H
#define BLUEPRINT_BP_TEXTPIN_H



#include <QGraphicsItem>
#include "Port/BP_BasePort.h"

class BP_TextPin: public BP_BasePort {
Q_OBJECT
public:
    explicit BP_TextPin(QGraphicsItem* parent = nullptr);
    explicit BP_TextPin(PinType type, QGraphicsItem *parent = nullptr);

protected:
    /**节点图形区域大小*/
    QRectF boundingRect() const override;
};


#endif //BLUEPRINT_BP_TEXTPIN_H
