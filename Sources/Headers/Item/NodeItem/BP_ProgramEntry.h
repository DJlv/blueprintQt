//
// Created by admin on 2023/11/18.
//

#ifndef TEST_BP_PROGRAMENTRY_H
#define TEST_BP_PROGRAMENTRY_H
#include "Node/BP_BaseNode.h"
#include <QGraphicsItem>
#include <QRectF>
#include <QDebug>
class BP_ProgramEntry : public BP_BaseNode {
    Q_OBJECT
public:
    explicit BP_ProgramEntry(QGraphicsItem* parent = nullptr);
protected:
    void Simulation();
};

#endif //TEST_BP_PROGRAMENTRY_H
