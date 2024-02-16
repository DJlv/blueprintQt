//
// Created by admin on 2023/11/30.
//

#ifndef TEST_DRAGGINGEDGE_H
#define TEST_DRAGGINGEDGE_H
#include <QObject>
#include <QGraphicsItem>
#include <QColor>
#include <QPen>
#include <QPainter>
#include <QGraphicsDropShadowEffect>
#include "Port/PinType.h"
#include "Port/BP_BasePort.h"

/**
 * 移动连接线
 */
class DraggingEdge:public QObject, public QGraphicsItem {
Q_OBJECT
public:
    explicit DraggingEdge(QGraphicsItem* parent = nullptr);
    explicit DraggingEdge(QPointF* source_pos,QPointF* des_pos,BP_BasePort *source_port,BP_BasePort *des_port);
public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    QRectF boundingRect() const override;
    QPainterPath shape() const;
    QPainterPath getPath() const;

public:
    void update_edge_drage(QPointF *position, bool flage);

public:
    PinType source_type = PinType::port_type_in;
    PinType des_type = PinType::port_type_in;
    QPointF *source_pos;
    QPointF *des_pos;
    QColor edge_color = "#ffffff";

    QPen pen_default;
    QColor shadow_color = Qt::yellow;
    QGraphicsDropShadowEffect *shadow;
};


#endif //TEST_DRAGGINGEDGE_H
