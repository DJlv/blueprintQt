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
/**
 * 移动连接线
 */
class DraggingEdge:public QObject, public QGraphicsItem {
Q_OBJECT
public:
    explicit DraggingEdge(QGraphicsItem* parent = nullptr);
    explicit DraggingEdge(QPointF* source_pos,QPointF* des_pos,QColor dege_color="#ffffff");
public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) override;
    QRectF boundingRect() const override;
public:
    void update_edge_drage(QPointF *position, bool flage);

public:
    QPointF *source_pos;
    QPointF *des_pos;
    QColor edge_color;

    QPen pen_default;
    QColor shadow_color;
    QGraphicsDropShadowEffect *shadow;
};


#endif //TEST_DRAGGINGEDGE_H
