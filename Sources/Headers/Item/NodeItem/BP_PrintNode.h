//
// Created by admin on 2023/11/16.
//

#ifndef TEST_PRINTNODE_H
#define TEST_PRINTNODE_H
#include "Node/BP_BaseNode.h"
#include <QGraphicsItem>
#include <QRectF>
#include <QDebug>
class BP_PrintNode: public BP_BaseNode {
    Q_OBJECT
public:
    explicit BP_PrintNode(QGraphicsItem* parent = nullptr);
protected:
    /**节点图形区域大小*/
    QRectF boundingRect() const override;

    void Simulation();
};


#endif //TEST_PRINTNODE_H
