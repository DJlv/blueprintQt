//
// Created by admin on 2023/11/15.
//

#ifndef TEST_NODE_H
#define TEST_NODE_H
#include <QGraphicsItem>
#include <QObject>
#include <QStyleOptionGraphicsItem>
#include <QPainter>
#include <QRectF>
#include <QPainterPath>
#include <QWidget>
#include <QString>
#include <QGraphicsSceneMouseEvent>
#include "Port/BP_BasePort.h"
//#include <Item/PortItem/BP_Pin.h>
#include <Edge/BP_Edge.h>
#include "Port//PinType.h"
#include <QtWidgets/QGroupBox>

class BP_BasePort;
class BP_Edge;
/**
 * 父节点
 */
class BP_BaseNode:public QObject, public QGraphicsItem {
    Q_OBJECT
public:
    /**
     * 允许元素移动
     * 允许图形元素被选择
     * 允许接受鼠标悬停事件
     * @param parent
     */
    explicit BP_BaseNode(QGraphicsItem *parent = nullptr);
    virtual void Simulation();
    virtual void SimulationStyle();

    QList<BP_BasePort*> portInList;
    QList<BP_BasePort*> portOutList;


    QList<BP_Edge*> edgeList;

    int  height = 30;
public:
    QString Title; /**标题*/
    QString Color; /*标题背景色*/
protected:
    /**节点图形区域大小*/
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);


    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    void drawChangePins(QPainter *pPainter);
};


#endif //TEST_NODE_H
