//
// Created by admin on 2023/11/24.
//

#ifndef TEST_BP_EXECPORT_H
#define TEST_BP_EXECPORT_H
#include "Port/BP_BasePort.h"
#include "Port/PinType.h"
#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QWidget>
class BP_ExecPort: public BP_BasePort {
    Q_OBJECT
public:
    explicit BP_ExecPort(QGraphicsItem* parent = nullptr);
    explicit BP_ExecPort(PinType type,QGraphicsItem *parent = nullptr);

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    void Simulation();
};


#endif //TEST_BP_EXECPORT_H
