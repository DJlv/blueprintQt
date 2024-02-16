// s
// Created by admin on 2023/11/25.
//

#include "Edge/BP_Edge.h"

BP_Edge::BP_Edge(QGraphicsItem *parent): QGraphicsItem(parent){
}
void BP_Edge::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsItem::mousePressEvent(event);
}
void BP_Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setRenderHint(QPainter::Antialiasing, true);
    update_edge_path();
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

void BP_Edge::update_edge_path(){
    getPath();
}


QPainterPath BP_Edge::getPath() const {

    QPainterPath path = QPainterPath();
    long xwidth = abs(source_port->scenePos().x()-des_port->scenePos().x());
    long yheight = abs(source_port->scenePos().y()-des_port->scenePos().y());
    float tangent = float(yheight) / xwidth * 0.5;
    if(tangent >= 1) tangent =1;
    tangent *= xwidth;
    QPointF * pos_001;
    QPointF * des_001;

    switch (source_port->port_type) {
        case PinType::port_type_out:
            pos_001 = new QPointF(source_port->scenePos().x() + 30, source_port->scenePos().y() + 15);
            break;
        case PinType::port_type_port_out:
            pos_001 = new QPointF(source_port->scenePos().x() + 25, source_port->scenePos().y() + 7);
            break;
        case PinType::port_type_in:
            pos_001 = new QPointF(source_port->scenePos().x() + 15, source_port->scenePos().y() + 15);
            break;
        case PinType::port_type_port_in:
            pos_001 = new QPointF(source_port->scenePos().x() + 7, source_port->scenePos().y() + 7);
            break;
    }
    switch (des_port->port_type) {
        case PinType::port_type_out:
            des_001 = new QPointF(des_port->scenePos().x() + 30, des_port->scenePos().y() + 15);
            break;
        case PinType::port_type_port_out:
            des_001 = new QPointF(des_port->scenePos().x() + 15, des_port->scenePos().y() + 7);
            break;
        case PinType::port_type_in:
            des_001 = new QPointF(des_port->scenePos().x() + 15, des_port->scenePos().y() + 15);
            break;
        case PinType::port_type_port_in:
            des_001 = new QPointF(des_port->scenePos().x() + 7, des_port->scenePos().y() + 7);
            break;
    }
    path.moveTo(pos_001->x(),pos_001->y());
    path.cubicTo(QPointF(pos_001->x() + tangent,pos_001->y()),QPointF(des_001->x()-tangent,des_001->y()),QPointF(des_001->x(),des_001->y()));
    return path;
}



BP_Edge::BP_Edge(BP_BasePort *source_port_item,BP_BasePort *des_port_item,QGraphicsItem *parent) {

    setCacheMode(QGraphicsItem::DeviceCoordinateCache);
    setFlag(ItemIsMovable);  // 允许图形元素被移动
    setFlag(ItemIsSelectable);  // 允许图形元素被选择
    setFlag(ItemSendsGeometryChanges);
    setAcceptHoverEvents(false);  // 允许接受鼠标悬停事件


    source_port = source_port_item;
    des_port = des_port_item;

    edge_color = "#FFFFFF";
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
    shadow->setBlurRadius(2);
    setFlags(QGraphicsItem::ItemIsSelectable);
    update_edge_path();
}

QRectF BP_Edge::boundingRect() const {
    return getPath().boundingRect();
}

QPainterPath BP_Edge::shape() const {
    return getPath();
}
