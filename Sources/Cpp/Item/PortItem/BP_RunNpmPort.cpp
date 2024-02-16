//
// Created by admin on 2024/2/16.
//

#include "Item/PortItem/BP_RunNpmPort.h"
#include "Item/AttributeItem/BP_RunNpmAttribute.h"
#include "Variable/BP_Variable.h"

BP_RunNpmPort::BP_RunNpmPort(QGraphicsItem *parent) : BP_BasePort(parent) {

}

BP_RunNpmPort::BP_RunNpmPort(PinType type, QGraphicsItem *parent) : BP_BasePort(type, parent) {
    BP_BasePort::Title ="设置NPM参数";
    BP_BasePort::Color = "#46e407";
    BP_BasePort::port_type = type;
    BP_BasePort::attribute = new BP_RunNpmAttribute;
}


void BP_RunNpmPort::paintChildren(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    if(BP_BasePort::port_type == PinType::port_type_port_out || BP_BasePort::port_type == PinType::port_type_port_in) {
        QFont font("SimSun", 12);  // 创建字体对象并指定字体名称和大小
        painter->setFont(font);
        QPen pen_default = QPen(QColor(Color));
        painter->setPen(pen_default);
        if (edgeList.size() > 0) {
            painter->setPen(pen_default);
            painter->setBrush(QColor(Color));  // 设置填充颜色或样式
        }
        QRectF rect(0, 0, 15, 15);
        path.addEllipse(rect);
        painter->drawPath(path);
        QPainterPath pathss;
        pathss.moveTo(18, 3);
        pathss.lineTo(23, 7);
        pathss.lineTo(18, 12);
        pathss.lineTo(18,3);
        pathss.closeSubpath();
        painter->setBrush(QColor(Color));  // 设置填充颜色或样式
        painter->drawPath(pathss);
        path.addPath(pathss);
        QPainterPath pathText;
        if (port_type == PinType::port_type_port_in) {
            pathText.addText(Title.size() + 30, 12,font, Title);
            painter->drawText(Title.size() + 30, 12,Title);
        } else if (port_type == PinType::port_type_port_out) {
            pathText.addText(-Title.size() * 10 - 25, 12,font, Title);
            painter->drawText(-Title.size() * 10 - 25, 12,Title);
        }
        path.addPath(pathText);
    }
}

void BP_RunNpmPort::Simulation() {
    if(!item) {
        BP_Variable::getPlintConsole("请启动浏览器程序,之后才可查看");
    } else{
        BP_Variable::getPlintConsole("浏览器程序已启动,查看地址:http://localhost:8080/#/");
    }
}
void BP_RunNpmPort::slotLineEdit(bool text) {
    item = text;
}