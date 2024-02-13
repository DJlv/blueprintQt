//
// Created by admin on 2023/11/30.
//

#include "DraggingEdge/DraggingEdge.h"
#include <QDebug>
void DraggingEdge::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QPainterPath path = QPainterPath();
    long xwidth = abs(source_pos->x()-des_pos->x());
    long yheight = abs(source_pos->y()-des_pos->y());

    float tangent = float(yheight) / xwidth * 0.5;
    if(tangent >= 1) tangent =1;
    tangent *= xwidth;
    path.moveTo(source_pos->x() + 7,source_pos->y() + 7);
    path.cubicTo(QPointF(source_pos->x() + 7 + tangent,source_pos->y() + 7),QPointF(des_pos->x()-tangent + 7,des_pos->y() + 7),QPointF(des_pos->x() + 7,des_pos->y() + 7));


    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(pen_default);

    painter->setBrush(Qt::NoBrush);
    painter->drawPath(path);
    if(this->isSelected()) {
        shadow->setColor(shadow_color);
        setGraphicsEffect(shadow);
    } else {
        shadow->setColor("#00000000");
        setGraphicsEffect(shadow);
    }
    update();
}

DraggingEdge::DraggingEdge(QGraphicsItem *parent) : QGraphicsItem(parent) {

}

DraggingEdge::DraggingEdge(QPointF *source_pos_Item, QPointF *des_pos_Item, QColor edge_color_Item) {
    setCacheMode(QGraphicsItem::DeviceCoordinateCache);
    setFlag(ItemIsMovable);  // 允许图形元素被移动
    setFlag(ItemIsSelectable);  // 允许图形元素被选择
    setFlag(ItemSendsGeometryChanges);
    setAcceptHoverEvents(false);  // 允许接受鼠标悬停事件

    source_pos = source_pos_Item;
    des_pos = des_pos_Item;
    edge_color = edge_color_Item;

    pen_default = QPen(QColor(edge_color));
    pen_default.setWidthF(4);
    setZValue(-1);

    //实例阴影shadow
    shadow = new QGraphicsDropShadowEffect(this);
    //设置阴影距离
    shadow->setOffset(0, 0);
    //设置阴影颜色
    shadow_color = Qt::yellow;
    shadow->setColor(shadow_color);
    //设置阴影圆角
    shadow->setBlurRadius(20);
    setFlags(QGraphicsItem::ItemIsSelectable);
}


void DraggingEdge::update_edge_drage(QPointF* position,bool flage) {
    if(flage) {
        source_pos = position;
    } else {
        des_pos =  position;
    }
    update();
}
QRectF DraggingEdge::boundingRect() const{
    QPainterPath path = QPainterPath();
    long xwidth = abs(source_pos->x()-des_pos->x());
    long yheight = abs(source_pos->y()-des_pos->y());

    float tangent = float(yheight) / xwidth * 0.5;
    if(tangent >= 1) tangent =1;
    tangent *= xwidth;
    path.moveTo(source_pos->x()  + 15,source_pos->y() + 7);
    path.cubicTo(QPointF(source_pos->x() + 7 + tangent,source_pos->y() + 7),QPointF(des_pos->x()-tangent + 7,des_pos->y() + 7),QPointF(des_pos->x(),des_pos->y() + 7));

    return path.boundingRect();
}

QPainterPath DraggingEdge::shape() const {
    QPainterPath path = QPainterPath();
    long xwidth = abs(source_pos->x()-des_pos->x());
    long yheight = abs(source_pos->y()-des_pos->y());

    float tangent = float(yheight) / xwidth * 0.5;
    if(tangent >= 1) tangent =1;
    tangent *= xwidth;
    path.moveTo(source_pos->x() + 7,source_pos->y() + 7);
    path.cubicTo(QPointF(source_pos->x() + 7 + tangent,source_pos->y() + 7),QPointF(des_pos->x()-tangent + 7,des_pos->y() + 7),QPointF(des_pos->x() + 7,des_pos->y() + 7));
    return path;
}
