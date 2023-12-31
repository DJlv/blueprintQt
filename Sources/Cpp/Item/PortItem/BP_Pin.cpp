//
// Created by admin on 2023/11/17.
//

#include "Item/PortItem/BP_Pin.h"


void BP_Pin::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QFont font("Consolas", 12);  // 创建字体对象并指定字体名称和大小
    painter->setFont(font);


    QPen pen_default = QPen(QColor(port_color));
    pen_default.setWidthF(1.5);
    QBrush brush_default = QBrush(QColor(port_color));
    QPainterPath path;
    QPolygonF poly;
    poly.append(QPointF(0,0.2 * prot_icon_size));
    poly.append(QPointF(0.4 * prot_icon_size,0.2 * prot_icon_size));
    poly.append(QPointF(0.7 * prot_icon_size,0.5 * prot_icon_size));
    poly.append(QPointF(0.4 * prot_icon_size,0.8 * prot_icon_size));
    poly.append(QPointF(0,0.8 * prot_icon_size));
    poly.append(QPointF(0,0.2 * prot_icon_size));

    path.addPolygon(poly);
    painter->setPen(pen_default);
    painter->setBrush(Qt::NoBrush);
    painter->drawPath(path);
}

QRectF BP_Pin::boundingRect() const
{
    return QRectF(0, 0, 10, 10); // 定义连接点的边界矩形
}



BP_Pin::BP_Pin(PinType type, QGraphicsItem *parent) : m_type(type) {

    port_color = QColor("#FFFFFF");
    port_type = PinType::port_type_in;

    prot_lable_size = port_lable.size();
    update();
}
