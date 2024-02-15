//
// Created by admin on 2023/11/15.
//

#include "View/BP_GridBackgroundView.h"
#include "Item/AttributeItem/ItemTest.h"
#include <QMenu>
#include <QtMath>
#include <QVector>
#include <Qpainter>
#include <Edge/BP_Edge.h>
#include <QVBoxLayout>
#include <QLayoutItem>

BP_GridBackgroundView::BP_GridBackgroundView(QWidget *parent) : QGraphicsView(parent) {
    setDragMode(QGraphicsView::NoDrag);
    m_dOriScale = 1;//图形原始比例为1
    setStyleSheet("padding: 0px; border: 0px;");//无边框
    setMouseTracking(true);//允许跟踪鼠标位置

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏水平条
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏竖条
    setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform);

    setSceneRect(0, 0, width, height);
    normal_line_pen = QPen(QColor("#313131")); // wi 1.0 1.5 30 10
    normal_line_pen.setWidthF(1.0);
    dark_line_pen = QPen(QColor("#151515"));
    dark_line_pen.setWidthF(1.5);
}


void BP_GridBackgroundView::drawBackground(QPainter *painter, const QRectF &rect) {
    long left = qFloor(rect.left());
    long right = qFloor(rect.right());
    long top = qFloor(rect.top());
    long bottom = qFloor(rect.bottom());
    long first_left = left - (left % grid_size);
    long first_top = top - (top % grid_size);

    QVector<QLine> lines;
    QVector<QLine> darklines;
    // 画横线
    for (int i = first_top; i < bottom;) {
        QLine line = QLine(left, i, right, i);
        if (i % (grid_size * chunk_size) == 0) {
            darklines.append(line);
        } else {
            lines.append(line);
        }
        i = i + grid_size;
    }
    // 画竖线
    for (int i = first_left; i < right;) {
        QLine line = QLine(i, top, i, bottom);
        if (i % (grid_size * chunk_size) == 0) {
            darklines.append(line);
        } else {
            lines.append(line);
        }
        i = i + grid_size;
    }
    painter->setPen(normal_line_pen);
    painter->drawLines(lines);
    painter->setPen(dark_line_pen);
    painter->drawLines(darklines);
    viewport()->update();
}

void BP_GridBackgroundView::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::MiddleButton) {
        setDragMode(QGraphicsView::NoDrag);
        drag_mode = false;
        QMouseEvent realse_event = QMouseEvent(QEvent::MouseButtonRelease, event->localPos(), Qt::LeftButton,
                                               Qt::NoButton, event->modifiers());
        mouseReleaseEvent(&realse_event);
    }

    QGraphicsView::mouseReleaseEvent(event);
}

void BP_GridBackgroundView::mousePressEvent(QMouseEvent *event) {
    dealmouseRight(event); // 点击右键
    if (event->button() == Qt::MiddleButton) {
        middleButton(event);
    }
    // 获取鼠标点击位置的图形项
    QGraphicsItem *item = itemAt(event->pos());
    // 尝试将图形项转换为蓝图节点类
    BP_BaseNode *blueprintNode = dynamic_cast<BP_BaseNode *>(item);
    BP_BasePort *nodeport = dynamic_cast<BP_BasePort *>(item);
    BP_Edge *edge = dynamic_cast<BP_Edge *>(item);

    if (event->button() == Qt::LeftButton && edge) {
        BP_BasePort *startEdgePort = edge->source_port;
        BP_BasePort *endEdgePort = edge->des_port;
        scene()->removeItem(edge);
        BP_BaseNode *node = startEdgePort->node;
        startEdgePort->edgeList.removeAll(edge);
        endEdgePort->edgeList.removeAll(edge);
        node->edgeList.removeAll(edge);
        startEdgePort->edgeList.removeAll(edgeItem);
        startEdgePort->update();
        endEdgePort->update();
    }
    if (event->button() == Qt::LeftButton && nodeport) {
        n++;
        leftButton(event);
    }
    update();
}

void BP_GridBackgroundView::leftButton(const QMouseEvent *event) {
    drag_edge_mode = true;
    // 获取鼠标点击位置的图形项
    QGraphicsItem *item = itemAt(event->pos());

    BP_BasePort *nodeport = dynamic_cast<BP_BasePort *>(item);
    if (nodeport) {
        nodeport->flage = true;
        creat_dragging_edge(nodeport, event);
    }

}

void BP_GridBackgroundView::creat_dragging_edge(BP_BasePort *item, const QMouseEvent *event) {

    QPointF *source = new QPointF(item->scenePos());
    if (item_drage) {
        if (item->port_type == PinType::port_type_in || item->port_type == PinType::port_type_out) {

            QPoint port_source_pos = mapFromScene(QPoint(item_drage->source_pos->x(), item_drage->source_pos->y()));
            QPoint port_dos_pos = mapFromScene(QPoint(item_drage->des_pos->x(), item_drage->des_pos->y()));

            QGraphicsItem *port_source_pos_item = itemAt(port_source_pos);
            QGraphicsItem *port_dos_pos_item = itemAt(port_dos_pos);

            BP_BasePort *nodeport2 = dynamic_cast<BP_BasePort *>(port_dos_pos_item);
            BP_BasePort *nodeport1 = dynamic_cast<BP_BasePort *>(port_source_pos_item);
            if (!nodeport2) {
                nodeport2 = nodeportItem;
            }
            if (!nodeport1) {
                nodeport1 = nodeportItem;
            }
            if (nodeport1 && nodeport2) {
                if (nodeport1->port_type == PinType::port_type_in || nodeport1->port_type == PinType::port_type_out) {
                    if ((nodeport2->port_type == PinType::port_type_in ||
                         nodeport2->port_type == PinType::port_type_out)) {
                        addNodeEdge(nodeport1->node, nodeport2->node, nodeport1, nodeport2);
                    }
                }
            }
        }
    }
    if (!item_drage) {
        if (item->port_type == PinType::port_type_in || item->port_type == PinType::port_type_out) {
            QGraphicsItem *item = itemAt(event->pos());
            BP_BasePort *nodeport1 = dynamic_cast<BP_BasePort *>(item);
            item_drage = new DraggingEdge(source, source);
            nodeportItem = nodeport1;
        }
    }

    if (item->port_type == PinType::port_type_port_in || item->port_type == PinType::port_type_in) {
        drage_from_edge = true;
    } else if (item->port_type == PinType::port_type_port_out || item->port_type == PinType::port_type_out) {
        drage_from_edge = false;
    }
    if (fledge) {
        scene()->addItem(item_drage);
    } else {
        scene()->removeItem(item_drage);
        fledge = true;
    }
    update();
}

void BP_GridBackgroundView::middleButton(const QMouseEvent *event) {
    QMouseEvent realse_event = QMouseEvent(QEvent::MouseButtonRelease, event->localPos(), Qt::LeftButton,
                                           Qt::NoButton, event->modifiers());
    mouseReleaseEvent(&realse_event);
    setDragMode(ScrollHandDrag);
    drag_mode = true;
    QMouseEvent click_event = QMouseEvent(QEvent::MouseButtonRelease, event->localPos(), Qt::LeftButton,
                                          Qt::NoButton, event->modifiers());

    mousePressEvent(&click_event);
}

// 放大缩小 存在Bug 当前不使用
void BP_GridBackgroundView::wheelEvent(QWheelEvent *event) {
    if (!drag_mode) {
        if ((event->angleDelta().y() > 0) && (m_dOriScale >= 15))//最大放大到原始图像的50倍
            return;
        else if ((event->angleDelta().y() < 0) && (m_dOriScale <= 0.5))//图像缩小到自适应大小之后就不继续缩小
            return;
        QTransform transform;
        qreal scaleFactor = transform.m11();
        m_dOriScale = scaleFactor;
        int wheelDeltaValue = event->angleDelta().y();
        if (wheelDeltaValue > 0)//放大
            this->scale(1.2, 1.2);
        else//缩小
            this->scale(1.0 / 1.2, 1.0 / 1.2);
        update();
    }
}

void BP_GridBackgroundView::mouseMoveEvent(QMouseEvent *event) {
    // 获取鼠标点击位置的图形项
    QGraphicsItem *item = itemAt(event->pos());
    // 尝试将图形项转换为蓝图节点类
    BP_BaseNode *blueprintNode = dynamic_cast<BP_BaseNode *>(item);
    if (!blueprintNode) {
        for (BP_BaseNode *item: BP_Variable::NodeLists) {
            item->setSelected(false);
        }
    }
    if (drag_edge_mode) {
        update_drage_edge(event);
    }
    QGraphicsView::mouseMoveEvent(event);
}

void BP_GridBackgroundView::update_drage_edge(QMouseEvent *event) {
    QPointF *pos = new QPointF(mapToScene(event->pos()));
    if (item_drage) {
        item_drage->update_edge_drage(pos, drage_from_edge);
    }
    if (n == 2) {
        item_drage = nullptr;
        n = 0;
    }
}


void BP_GridBackgroundView::dealmouseRight(QMouseEvent *event) {
    // 获取鼠标点击位置的图形项
    QGraphicsItem *item = itemAt(event->pos());
    // 尝试将图形项转换为蓝图节点类
    BP_BaseNode *blueprintNode = dynamic_cast<BP_BaseNode *>(item);
    BP_BasePort *nodeport = dynamic_cast<BP_BasePort *>(item);

    viewRightButton(event, blueprintNode, nodeport); // 右键点击空白区域
    nodeRightButton(event, blueprintNode, nodeport); // 右键点击节点
    portRightButton(event, nodeport); // 右键点击节点

    update();

    QGraphicsView::mousePressEvent(event);
}

void BP_GridBackgroundView::portRightButton(QMouseEvent *event, BP_BasePort *nodeport) {
    QGraphicsItem *item = itemAt(event->pos());
    if (event->button() == Qt::RightButton && nodeport) {
        connect(this, SIGNAL(buttonClicked(BP_BasePort * )), nodeport->attribute,
                SLOT(handleButtonClicked(BP_BasePort * )));
        emit(buttonClicked(nodeport));
        item->setSelected(false);
    }

}

void BP_GridBackgroundView::viewRightButton(const QMouseEvent *event, const BP_BaseNode *blueprintNode,
                                            BP_BasePort *nodeport) const {

    if (event->button() == Qt::RightButton && !blueprintNode && !nodeport) {

        QMenu menu;
        menu.setStyleSheet("QMenu { background-color: #696969;border-radius: 10px; }");
        QAction *print = menu.addAction("print");
        QAction *run = menu.addAction("run");
        QAction *text = menu.addAction("text");
        QAction *action4 = menu.addAction("Action 2");

        QAction *selectedAction = menu.exec(event->globalPos());
        if (selectedAction == print) {
            BP_BaseNode *item = new BP_PrintNode;
            item->setPos(mapToScene(event->pos()).x(), mapToScene(event->pos()).y());
            scene()->addItem(item);
            BP_Variable::NodeLists.append(item);
        } else if (selectedAction == run) {
            bool items = true;
            for (BP_BaseNode *item: BP_Variable::NodeLists) {
                if (item->Title.compare("Run") == 0) {
                    items = false;
                }
            }
            if (items) {
                BP_BaseNode *item = new BP_ProgramEntry;
                item->setPos(mapToScene(event->pos()).x(), mapToScene(event->pos()).y());
                scene()->addItem(item);
                BP_Variable::NodeLists.append(item);
            }

        } else if (selectedAction == text) {
            QGraphicsSimpleTextItem *simpleTextItem = new QGraphicsSimpleTextItem;
            simpleTextItem->setBrush(Qt::white);
            simpleTextItem->setText("QGraphicsSimpleTextItem Engine 中文 123");
            simpleTextItem->setFont(QFont("SimSun", 12));
            simpleTextItem->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
            simpleTextItem->setPos(mapToScene(event->pos()).x(), mapToScene(event->pos()).y());
            scene()->addItem(simpleTextItem);
        }
    }
}

void BP_GridBackgroundView::nodeRightButton(const QMouseEvent *event, const BP_BaseNode *blueprintNode,
                                            BP_BasePort *nodeport) {

    if (event->button() == Qt::RightButton && blueprintNode && blueprintNode->Title != "Run" && !nodeport) {

        QMenu menu;
        menu.setStyleSheet("QMenu { background-color: #696969;border-radius: 10px; }");
        QAction *print = menu.addAction("color");
        QAction *action2 = menu.addAction("Action 2");
        QAction *action3 = menu.addAction("Action 2");
        QAction *action4 = menu.addAction("Action 2");

        QAction *selectedAction = menu.exec(event->globalPos());
        if (selectedAction == print) {
            qDebug() << "color被点击了";
        } else if (selectedAction == action2) {
            // 执行 Action 2 对应的操作
        }
    }

    if (event->button() == Qt::RightButton && blueprintNode && blueprintNode->Title == "Run") {

        QMenu menu;
        menu.setStyleSheet("QMenu { background-color: #696969;border-radius: 10px; }");
        QAction *print = menu.addAction("Run");
        QAction *selectedAction = menu.exec(event->globalPos());
        QList<BP_BaseNode *> NodeListsItems = BP_Variable::NodeLists;
        if (selectedAction == print) {
            if (blueprintNode->Title == "Run") {
                for (BP_BaseNode *item: NodeListsItems) {
                    if (item->Title == "Run") {
                        NodeListsItems.removeAll(item);
                        for (BP_Edge *itemEdge: item->edgeList) {
                            childrenSimulation(itemEdge, NodeListsItems);
                        }
                    }
                }
            }
        }
    }

    update();
}

void BP_GridBackgroundView::childrenSimulation(BP_Edge *itemEdge, QList<BP_BaseNode *> NodeListsItems) const {

    if (!(itemEdge->des_port->port_type == PinType::port_type_in ||
          itemEdge->des_port->port_type == PinType::port_type_out)) {
        return;
    }

    for (BP_BaseNode *item: NodeListsItems) {
        if (itemEdge->des_port->node == item) {
            for (BP_BasePort *itemPort: itemEdge->des_port->node->portInList) {
                if (itemPort->port_type == PinType::port_type_port_in) {
                    itemPort->Simulation();
                }
            }
            for (BP_BasePort *itemPort: itemEdge->des_port->node->portOutList) {
                if (itemPort->port_type == PinType::port_type_port_out) {
                    itemPort->Simulation();
                }
            }

            NodeListsItems.removeAll(item);
            for (BP_Edge *itemEdge: item->edgeList) {
                childrenSimulation(itemEdge, NodeListsItems);
            }
        }
    }
}

void BP_GridBackgroundView::addNodeEdge(BP_BaseNode *startNode, BP_BaseNode *endNode, BP_BasePort *source_port,
                                        BP_BasePort *des_port) {
    edge = new BP_Edge(source_port, des_port);
    source_port->add_Edge(edge);
    des_port->add_Edge(edge);

    startNode->add_Edge(edge);
    endNode->add_Edge(edge);
    scene()->addItem(edge);
    BP_Variable::EdgeLists.append(edge);
    fledge = false;
    source_port->update();
    des_port->update();
}
