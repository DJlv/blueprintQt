//
// Created by admin on 2023/11/24.
//

#include "Item/PortItem/BP_ExecPort.h"

BP_ExecPort::BP_ExecPort(QGraphicsItem *parent) {

}

BP_ExecPort::BP_ExecPort(QString lable, QString port_class, QColor color,int port_type, QGraphicsItem *parent) {

    setInTiTle("in");
    setOutTitle("out");

    port_color = QColor("#07e006");
    port_type = PinvType::port_type_in;

    prot_lable_size = port_lable.size() * font_size;
    prot_width = prot_icon_size + prot_lable_size;
}
void BP_ExecPort::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    QFont font("Consolas", 12);  // 创建字体对象并指定字体名称和大小
    painter->setFont(font);


    QPen pen_default = QPen(QColor(port_color));
    pen_default.setWidthF(1.5);
    QBrush brush_default = QBrush(QColor(port_color));
    painter->setPen(pen_default);
    painter->setBrush(Qt::NoBrush);
//    if (m_type == Input) {
//        painter->drawText(InTiTle.size() * 2 + 20, 12, InTiTle);
//    } else if (m_type == Output) {
//        painter->drawText(-OutTitle.size() * 2 - 20 - 5, 12, OutTitle);
//    }
    painter->drawEllipse(0, 0, 15, 15);

}

QRectF BP_ExecPort::boundingRect() const {
    return QRectF(0, 0, 15, 15); // 定义连接点的边界矩形
}
