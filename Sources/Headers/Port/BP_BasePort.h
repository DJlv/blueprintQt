//
// Created by admin on 2023/11/24.
//

#ifndef TEST_BP_BASEPORT_H
#define TEST_BP_BASEPORT_H
#include <QObject>
#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QFont>
#include <QDebug>
#include <QPointF>
#include <QMouseEvent>
#include <Node/BP_BaseNode.h>
#include "Port/PinType.h"
#include "Edge/BP_Edge.h"
#include "Attribute/BP_Attribute.h"

class  BP_BaseNode;
class BP_Edge;
class BP_Attribute;
class BP_BasePort :public QObject,public QGraphicsItem {
    Q_OBJECT
public:
    explicit BP_BasePort(QGraphicsItem *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    QRectF boundingRect() const override;

public:
    explicit BP_BasePort(PinType type, QGraphicsItem *parent = nullptr);
    void add_Edge(BP_Edge* edgeItem);
    void add_to_parent_node(BP_BaseNode* nodeItem);
    void InOutStyle(QPainter *painter);
    virtual void Simulation();

    virtual void paintChildren(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public:
    int n = 0;
    QPainterPath path;
    QString Title;
    QString Color;
    QString InTiTle;
    QString OutTitle;

    PinType port_type;
    bool flage = false;
    QList<BP_Edge*> edgeList;
    BP_BaseNode* node;
    BP_Attribute* attribute;

};


#endif //TEST_BP_BASEPORT_H
