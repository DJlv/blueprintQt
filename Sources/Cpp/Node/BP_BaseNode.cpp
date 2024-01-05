//
// Created by admin on 2023/11/15.
//

#include "Node/BP_BaseNode.h"
#include <QDebug>
#include <QMenu>

BP_BaseNode::BP_BaseNode(QGraphicsItem *parent) : QGraphicsItem(parent) {
    setCacheMode(QGraphicsItem::DeviceCoordinateCache);
    setFlag(ItemIsMovable);  // 允许图形元素被移动
    setFlag(ItemIsSelectable);  // 允许图形元素被选择
    setFlag(ItemSendsGeometryChanges);
}

void BP_BaseNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    // 绘制节点的外观
    QBrush brush(QColor(0, 0, 30, 30));
    painter->setBrush(brush);
    if (option->state & QStyle::State_Selected) {
        QColor color("#00BFFF");
        QPen pen(color);
        pen.setWidth(2);
        painter->setPen(pen);
    }
    int x = 200;
    int y = 100;
    if (Title == "Run") {
        y = 80;
    }
    int yj = 15;
    painter->drawRoundedRect(0, 0, x, y, yj, yj); // 参数依次为矩形左上角坐标、宽度、高度、横向圆角半径、纵向圆角半径
//                painter->setBrush(Qt::red); // 设置标题背景色
    // 创建线性渐变
    QLinearGradient gradient(10, 10, 110, 110);
    gradient.setColorAt(0, Qt::red);
    gradient.setColorAt(1, Qt::blue);

    QPainterPath path;

    path.moveTo(0, 15);
    path.arcTo(0, 0, yj * 2, yj * 2, 90.0f, 90.0f);
    path.lineTo(0, 30);
//    path.lineTo(x,yj);
    path.lineTo(200, 30);

//                QRect rect1(x - 2 * yj ,0,2 * yj,2 * yj);
    path.arcTo(x - 2 * yj, 0, 2 * yj, 2 * yj, 0.0f, 90.0f);
    path.lineTo(yj, 0);
    painter->drawPath(path);
    painter->fillPath(path, QBrush(gradient));

    painter->setPen(Qt::white); // 设置标题文字颜色
    QFont font("Arial", 16);  // 创建字体对象并指定字体名称和大小
    painter->setFont(font);    // 将字体应用到绘制上下文中
    painter->drawText(200 / 3, 22, Title);

    // 绘制函数输入输出连接点
    if (Title != "Run") {
        drawInputPins(painter);

    }
    drawOutputPins(painter);


    // 绘制变量输入输出连接点
    drawChangePins(painter);

    update();

}

QString BP_BaseNode::getNodeTitle() const {
    return Title;
}

void BP_BaseNode::setNodeTitle(const QString &title) {
    Title = title;
}


void BP_BaseNode::drawInputPins(QPainter *painter) {
    // 在节点左侧绘制输入连接点
//    BP_Pin *pin = new BP_Pin(BP_Pin::Input, this);
//    pin->setPos(10, 5);
}

void BP_BaseNode::drawOutputPins(QPainter *painter) {
    // 在节点右侧绘制输出连接点
//    BP_Pin *pin = new BP_Pin(BP_Pin::Output, this);
//    pin->setPos(175, 5);
}

void BP_BaseNode::Simulation() {
    printf("Add Code \n virtual void Simulation() noexcept\n {\n //Simulation Code \n} in class");
}

void BP_BaseNode::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsItem::mouseMoveEvent(event);
}

void BP_BaseNode::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsItem::mouseReleaseEvent(event);
}

void BP_BaseNode::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    setSelected(true);
}

void BP_BaseNode::drawChangePins(QPainter *pPainter) {
    if (Title == "Run") {
        return;
    }
    int i,m;
    i = 0;
    m =0;
    pushPins(PinType::port_type_port_in,&i,&m);
    pushPins(PinType::port_type_port_out,&i,&m);
    pushPins(PinType::port_type_port_in,&i,&m);
    pushPins(PinType::port_type_port_out,&i,&m);
}
void BP_BaseNode::pushPins(PinType type,int *i,int *m) {
//    qDebug() << "PinType::"<< type;
    if(type == PinType::port_type_port_in) {
        // 在节点左侧绘制输入连接点
        BP_BasePort *pin = new BP_BasePort(type, this);
        pin->setPos(10, 40 + (*i) * 25);
        pin->add_to_parent_node(this);
        portInList.append(pin);
        (*i)++;
    }
    if(type == PinType::port_type_port_out) {
        // 在节点左侧绘制输入连接点
        BP_BasePort *pin = new BP_BasePort(type, this);
        pin->setPos(175, 40 + *m * 25);
        pin->add_to_parent_node(this);
        portOutList.append(pin);
        (*m)++;
    }
}

QVariant BP_BaseNode::itemChange(GraphicsItemChange change, const QVariant &value) {
    if (change == QGraphicsItem::ItemPositionChange) {
        if (edgeList.size() > 0) {
            for (BP_Edge *edge :edgeList) {
                edge->update();
            }
        }
    }
    return QGraphicsItem::itemChange(change, value);
}