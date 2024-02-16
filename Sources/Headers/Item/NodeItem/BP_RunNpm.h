//
// Created by admin on 2024/2/15.
//

#ifndef BLUEPRINT_BP_RUNNPM_H
#define BLUEPRINT_BP_RUNNPM_H

#include "Node/BP_BaseNode.h"
#include "Variable/BP_Variable.h"
#include <QGraphicsItem>
#include <QRectF>
#include <QDebug>
#include <QtWidgets/QGroupBox>
#include <QPushButton>
#include <QCoreApplication>
class BP_RunNpm : public BP_BaseNode {
Q_OBJECT

public:
    explicit BP_RunNpm(QGraphicsItem *parent = nullptr);

};


#endif //BLUEPRINT_BP_RUNNPM_H
