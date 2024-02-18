//
// Created by admin on 2024/2/17.
//

#ifndef BLUEPRINT_BP_CREATEBIGSCREEN_H
#define BLUEPRINT_BP_CREATEBIGSCREEN_H

#include <QGraphicsItem>
#include "Port/BP_BasePort.h"
#include "Item/Signal/BP_CreateInitSignal.h"
#include <QtWidgets/QGroupBox>
class BP_CreateBigScreen: public BP_BasePort {
Q_OBJECT
public:
    explicit BP_CreateBigScreen(QGraphicsItem *parent = nullptr);
    explicit BP_CreateBigScreen(PinType type, QGraphicsItem *parent = nullptr);
protected:
    void paintChildren(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void Simulation();
public slots:
    void slotLineEdit(BP_BaseSignal* signleItem);
public:
    BP_CreateInitSignal* signleItem;
};


#endif //BLUEPRINT_BP_CREATEBIGSCREEN_H
