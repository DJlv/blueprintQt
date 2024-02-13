//
// Created by admin on 2023/11/15.
//

#include "Node/BP_BaseNode.h"
#include "Item/PortItem/BP_ExecPort.h"
#include "Item/PortItem/BP_Pin.h"
#include "Item/PortItem/BP_TextPin.h"
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

    int y = portInList.size() * height > portOutList.size() * height ? portInList.size() * height : portOutList.size() * height;
    if (Title == "Run") {
        y = 80;
    }
    int yj = 15;
    painter->drawRoundedRect(0, 0, x, y, yj, yj); // 参数依次为矩形左上角坐标、宽度、高度、横向圆角半径、纵向圆角半径
    QColor color(Color); // 设置标题背景色
    painter->setBrush(color);


    QPainterPath path;
    path.moveTo(15, 0);
    path.arcTo(0, 0, yj * 2, yj * 2, 90.0f, 90.0f);
    path.lineTo(0, 30);
    path.lineTo(x, 30);
    path.arcTo(x - 2 * yj, 0, 2 * yj, 2 * yj, 0.0f, 90.0f);
    path.lineTo(yj, 0);
    painter->drawPath(path);

    painter->setPen(Qt::white); // 设置标题文字颜色
    QFont font("SimSun", 16);  // 创建字体对象并指定字体名称和大小
    painter->setFont(font);    // 将字体应用到绘制上下文中
    painter->drawText(x / 3, 22, Title);


    // 绘制变量输入输出连接点
    drawChangePins(painter);

    update();

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
    int i, m;
    i = 0;
    m = 0;

    for (BP_BasePort *item: portInList) {
        // 在节点左侧绘制输入连接点
        item->setPos(10, 40 + i * 25);
        item->add_to_parent_node(this);
        i++;
    }
    for (BP_BasePort *item: portOutList) {
        // 在节点左侧绘制输入连接点
        item->setPos(175, 40 + m * 25);
        item->add_to_parent_node(this);
        m++;
    }
}

QVariant BP_BaseNode::itemChange(GraphicsItemChange change, const QVariant &value) {
    if (change == QGraphicsItem::ItemPositionChange) {
        if (edgeList.size() > 0) {
            for (BP_Edge *edge: edgeList) {
                edge->update();
            }
        }
    }
    return QGraphicsItem::itemChange(change, value);
}

void BP_BaseNode::SimulationStyle() {

}
