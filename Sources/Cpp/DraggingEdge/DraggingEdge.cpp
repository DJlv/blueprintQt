//
// Created by admin on 2023/11/30.
//

#include "DraggingEdge/DraggingEdge.h"
#include <QDebug>
void DraggingEdge::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(pen_default);

    painter->setBrush(Qt::NoBrush);
    painter->drawPath(getPath());
    if(this->isSelected()) {
        shadow->setColor(shadow_color);
        setGraphicsEffect(shadow);
    } else {
        shadow->setColor("#00000000");
        setGraphicsEffect(shadow);
    }
    update();
}

QPainterPath DraggingEdge::getPath() const {
    long xwidth = abs(source_pos->x() - des_pos->x());
    long yheight = abs(source_pos->y() - des_pos->y());

    float tangent = float(yheight) / xwidth * 0.5;
    if(tangent >= 1) tangent =1;
    tangent *= xwidth;
    QPointF * pos_001;
    QPointF * des_001;

    QPainterPath path = QPainterPath();
    switch (source_type) {
        case PinType::port_type_out:
            pos_001 = new QPointF(source_pos->x() + 30, source_pos->y() + 15);
            break;
        case PinType::port_type_port_out:
            pos_001 = new QPointF(source_pos->x() + 25, source_pos->y() + 7);
            break;
        case PinType::port_type_in:
            pos_001 = new QPointF(source_pos->x() + 15, source_pos->y() + 15);
            break;
        case PinType::port_type_port_in:
            pos_001 = new QPointF(source_pos->x() + 7, source_pos->y() + 7);
            break;
        case PinType::port_type_item:
            pos_001 = new QPointF(source_pos->x(), source_pos->y());
            break;
    }
    switch (des_type) {
        case PinType::port_type_out:
            des_001 = new QPointF(des_pos->x() + 30, des_pos->y() + 15);
            break;
        case PinType::port_type_port_out:
            des_001 = new QPointF(des_pos->x() + 7, des_pos->y() + 7);
            break;
        case PinType::port_type_in:
            des_001 = new QPointF(des_pos->x() + 15, des_pos->y() + 15);
            break;
        case PinType::port_type_port_in:
            des_001 = new QPointF(des_pos->x() + 7, des_pos->y() + 7);
            break;
        case PinType::port_type_item:
            des_001 = new QPointF(des_pos->x(), des_pos->y());
            break;
    }
    path.moveTo(pos_001->x(),pos_001->y());
    path.cubicTo(QPointF(pos_001->x() + tangent,pos_001->y()),QPointF(des_001->x()-tangent,des_001->y()),QPointF(des_001->x(),des_001->y()));
    return path;
}

DraggingEdge::DraggingEdge(QGraphicsItem *parent) : QGraphicsItem(parent) {

}

DraggingEdge::DraggingEdge(QPointF *source_pos_Item, QPointF *des_pos_Item,BP_BasePort *source_port,BP_BasePort *des_port) {
    source_type = source_port->port_type;
    source_type = des_port->port_type;

    setCacheMode(QGraphicsItem::DeviceCoordinateCache);
    setFlag(ItemIsMovable);  // 允许图形元素被移动
    setFlag(ItemIsSelectable);  // 允许图形元素被选择
    setFlag(ItemSendsGeometryChanges);
    setAcceptHoverEvents(false);  // 允许接受鼠标悬停事件

    source_pos = source_pos_Item;
    des_pos = des_pos_Item;

    pen_default = QPen(QColor(edge_color));
    pen_default.setWidthF(4);
    setZValue(-1);

    //实例阴影shadow
    shadow = new QGraphicsDropShadowEffect(this);
    //设置阴影距离
    shadow->setOffset(0, 0);
    //设置阴影颜色
    shadow->setColor(shadow_color);
    //设置阴影圆角
    shadow->setBlurRadius(20);
    setFlags(QGraphicsItem::ItemIsSelectable);
}


void DraggingEdge::update_edge_drage(QPointF* position,bool flage) {
    if(flage) {
        source_pos = position;
        source_type = PinType::port_type_item ;
    } else {
        des_pos =  position;
        des_type = PinType::port_type_item ;
    }
    update();
}
QRectF DraggingEdge::boundingRect() const{
    return getPath().boundingRect();
}

QPainterPath DraggingEdge::shape() const {
    return getPath();
}
