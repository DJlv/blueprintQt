//
// Created by admin on 2023/11/16.
//

#ifndef TEST_PRINTNODE_H
#define TEST_PRINTNODE_H

#include "Node/BP_BaseNode.h"
#include "Variable/BP_Variable.h"
#include <QGraphicsItem>
#include <QRectF>
#include <QDebug>
#include <QtWidgets/QGroupBox>
#include <QPushButton>
#include <QCoreApplication>

class BP_PrintNode : public BP_BaseNode {
Q_OBJECT

public:
    explicit BP_PrintNode(QGraphicsItem *parent = nullptr);

protected:
    /**节点图形区域大小*/
    void Simulation();
    void SimulationStyle();
private:
    QString x =0;
    QPushButton* button= nullptr;
    QLineEdit *lineEdit = nullptr;
};


#endif //TEST_PRINTNODE_H
