//
// Created by admin on 2024/2/16.
//

#ifndef BLUEPRINT_BP_RUNNPMPORT_H
#define BLUEPRINT_BP_RUNNPMPORT_H


#include <QGraphicsItem>
#include "Port/BP_BasePort.h"
#include <QtWidgets/QGroupBox>
class BP_RunNpmPort : public BP_BasePort {
Q_OBJECT

public:
    explicit BP_RunNpmPort(QGraphicsItem *parent = nullptr);
    explicit BP_RunNpmPort(PinType type, QGraphicsItem *parent = nullptr);
protected:
    void paintChildren(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void Simulation();
public slots:
    void slotLineEdit(bool text);
public:
    bool item = false;

    void InOutStyle(QPainter *painter);
};


#endif //BLUEPRINT_BP_RUNNPMPORT_H
