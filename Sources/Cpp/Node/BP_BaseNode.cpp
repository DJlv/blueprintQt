//
// Created by admin on 2023/11/15.
//

#include "Node/BP_BaseNode.h"
#include "Item/PortItem/BP_TextPin.h"
#include <QDebug>
#include <QMenu>

BP_BaseNode::BP_BaseNode(QGraphicsItem *parent) : QGraphicsItem(parent) {
    setCacheMode(QGraphicsItem::DeviceCoordinateCache);

    setFlag(ItemIsMovable);  // 允许图形元素被移动
    setFlag(ItemIsSelectable);  // 允许图形元素被选择
    setFlag(ItemSendsGeometryChanges);
}
void BP_BaseNode::add_Edge(BP_Edge *edgeItem) {
    edgeList.append(edgeItem);
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

    int Item1= 0;
    for (BP_BasePort* item: portInList)
    {
        Item1 = item->Title.size() * 25 > Item1 ? item->Title.size() * 25 : Item1;
    }
    int Item2= 0;
    for (BP_BasePort* item: portInList)
    {
        Item2 = item->Title.size() * 25 > Item2 ? item->Title.size() * 25 : Item2;
    }
    width = (Item1 + Item2) > 999 ? 600: (Item1 + Item2);
    width = (Item1 + Item2) > 0 ? (Item1 + Item2): 200;
    width = (Item1 + Item2) < 200 ? 200: (Item1 + Item2) + 30;
    int y = portInList.size() * height > portOutList.size() * height ? portInList.size() * height : portOutList.size() * height;
    if(y == 0) {
        y = 50;
    }
    int yj = 15;
    painter->drawRoundedRect(0, 0, width, y, yj, yj); // 参数依次为矩形左上角坐标、宽度、高度、横向圆角半径、纵向圆角半径
    QColor color(Color); // 设置标题背景色
    painter->setBrush(color);


    QPainterPath path;
    path.moveTo(15, 0);
    path.arcTo(0, 0, yj * 2, yj * 2, 90.0f, 90.0f);
    path.lineTo(0, 30);
    path.lineTo(width, 30);
    path.arcTo(width - 2 * yj, 0, 2 * yj, 2 * yj, 0.0f, 90.0f);
    path.lineTo(yj, 0);
    painter->drawPath(path);

    painter->setPen(Qt::white); // 设置标题文字颜色
    QFont font("SimSun", 16);  // 创建字体对象并指定字体名称和大小
    painter->setFont(font);    // 将字体应用到绘制上下文中
    painter->drawText(width / 3, 22, Title);


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
    int i, m;
    i = 0;
    m = 0;
    for (BP_BasePort *item: portInList) {
        if(PinType::port_type_in == item->port_type) {
            item->setPos(0, 0);
            item->add_to_parent_node(this);
        } else if(PinType::port_type_port_in == item->port_type){
            // 在节点左侧绘制输入连接点
            item->setPos(10, 40 + i * 25);
            item->add_to_parent_node(this);
            i++;
        }
    }
    for (BP_BasePort *item: portOutList) {
        if(PinType::port_type_out == item->port_type) {
            item->setPos(width - 35, 0);
            item->add_to_parent_node(this);
        } else if(PinType::port_type_port_out == item->port_type){
            // 在节点左侧绘制输入连接点
            item->setPos(width - 35, 40 + m * 25);
            item->add_to_parent_node(this);
            m++;
        }

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



QRectF BP_BaseNode::boundingRect() const {
    return QRectF(0, 0,
                  width,
                  BP_BaseNode::portInList.size() * BP_BaseNode::height >
                             BP_BaseNode::portOutList.size() * BP_BaseNode::height ?
                             BP_BaseNode::portInList.size() * BP_BaseNode::height : BP_BaseNode::portOutList.size() *
                                                                                    BP_BaseNode::height); // 定义节点的边界矩形
}

