//
// Created by admin on 2023/11/25.
//

#ifndef TEST_BP_EDGE_H
#define TEST_BP_EDGE_H
#include <QGraphicsItem>
#include <QObject>
#include <QPen>
#include <QColor>
#include <QString>
#include "Port/BP_BasePort.h"
#include <QPointF>
#include <QGraphicsDropShadowEffect>
#include <Node/BP_BaseNode.h>

class BP_BaseNode;
class BP_BasePort;
class BP_Edge:public QObject, public QGraphicsItem{
Q_OBJECT

public:
    explicit BP_Edge(QGraphicsItem *parent = nullptr);
    explicit BP_Edge(BP_BasePort *source_port = nullptr,BP_BasePort *des_port = nullptr, QGraphicsItem *parent = nullptr);

    /**
    * 返回连接线区域 显示区域
    * @return
    */
    QRectF boundingRect() const override;
    /**
     * 返回连接线区域 可被选中
     * @return
     */
    QPainterPath shape() const;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

public:
    BP_BasePort *source_port;
    BP_BasePort *des_port;
    BP_BaseNode *scence;
    QColor edge_color;
    QPen pen_default;
    QPainterPath paths;

    QColor shadow_color;
    QGraphicsDropShadowEffect *shadow;
    /**
     * 计算连接线路径
     */
    void update_edge_path();
};


#endif //TEST_BP_EDGE_H
