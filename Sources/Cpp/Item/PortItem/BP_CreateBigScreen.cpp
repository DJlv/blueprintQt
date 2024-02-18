//
// Created by admin on 2024/2/17.
//

#include "Item/PortItem/BP_CreateBigScreen.h"
#include "Item/AttributeItem/BP_CreateInitBigScreen.h"

BP_CreateBigScreen::BP_CreateBigScreen(QGraphicsItem *parent) : BP_BasePort(parent) {

}

BP_CreateBigScreen::BP_CreateBigScreen(PinType type, QGraphicsItem *parent) : BP_BasePort(type, parent) {
    BP_BasePort::Title ="初始化大屏基本代码";
    BP_BasePort::Color = "#04c9cd";
    BP_BasePort::port_type = type;
    BP_BasePort::attribute = new BP_CreateInitBigScreen;
    signleItem = new BP_CreateInitSignal;
}

void BP_CreateBigScreen::paintChildren(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
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

void BP_CreateBigScreen::Simulation() {
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString formattedDateTime = currentDateTime.toString("yyyyMMdd hh:mm:ss");
    QString str = formattedDateTime + "------:" + signleItem->text+"\n";
    str = BP_Variable::getAgesFile("Sources/Resource/vue.vue","init");
    BP_Variable::textEdit->setPlainText(str);
    update();
}

void BP_CreateBigScreen::slotLineEdit(BP_BaseSignal* signlePasser) {
    signleItem = static_cast<BP_CreateInitSignal *>(signlePasser);
}
