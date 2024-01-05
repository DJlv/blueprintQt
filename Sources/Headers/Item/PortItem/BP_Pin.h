//
// Created by admin on 2023/11/17.
//

#ifndef TEST_BP_PIN_H
#define TEST_BP_PIN_H
#include "Port/BP_BasePort.h"
#include "Port/PinType.h"
#include <Node/BP_BaseNode.h>
#include "Port/PinType.h"
#include "Edge/BP_Edge.h"


class BP_BaseNode;
class BP_Edge;
class BP_Pin: public BP_BasePort{
    Q_OBJECT
public:
    explicit BP_Pin(PinType type, QGraphicsItem *parent = nullptr);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    QRectF boundingRect() const override;
private:
    QString InTiTle;
    QString OutTitle;
    QString port_lable;
    QString port_class;
    QColor port_color;
    int prot_lable_size;
    int prot_icon_size = 20;
    PinType m_type;
};


#endif //TEST_BP_PIN_H
