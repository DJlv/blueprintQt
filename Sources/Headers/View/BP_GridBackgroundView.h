//
// Created by admin on 2023/11/15.
//

#ifndef TEST_BP_GRIDBACKGROUNDVIEW_H
#define TEST_BP_GRIDBACKGROUNDVIEW_H


#include <QObject>
#include<QGraphicsView>
#include <QRect>
#include <QPen>
#include <QBrush>
#include <QPointF>
#include <QPainter>
#include <QMenu>
#include <QMouseEvent>
#include <DraggingEdge/DraggingEdge.h>
#include "Node/BP_BaseNode.h"
#include "Item/NodeItem/BP_PrintNode.h"
#include "Port/BP_BasePort.h"
#include <QPoint>

/**
 * GridBackgroundView
 * 网格背景
 * 右键点击
 */

class BP_GridBackgroundView : public QGraphicsView {
    Q_OBJECT
public:
    explicit BP_GridBackgroundView(QWidget *parent = nullptr);
protected:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void drawBackground(QPainter *painter, const QRectF &rect);
    void wheelEvent(QWheelEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *mouseEvent) override;
private:
    void dealmouseRight(QMouseEvent *event);  // 点击右键


signals:
    void buttonClicked();
public:
    bool drag_mode = false;

    long width;
    long height;
    QPen normal_line_pen;
    QPen dark_line_pen;
    int chunk_size = 10;
    int grid_size = 20;

    bool drag_edge_mode =false;
    bool drage_from_edge = true;
    DraggingEdge* item_drage = nullptr;
private:

    bool fledge =true;
    BP_Edge *edge;
    BP_Edge *edgeItem;
    int n = 0; // 左键点击次数
    bool m_bIsPressed = false;//记录鼠标是否按下
    double m_dOriScale;//视图的原始比例

    void nodeRightButton(const QMouseEvent *event, const BP_BaseNode *blueprintNode);

    /**
     * 右键点击不是 蓝图节点 todo 差判断是否引脚 连接线等
     * @param event
     * @param blueprintNode
     */
    void viewRightButton(const QMouseEvent *event, const BP_BaseNode *blueprintNode) const;

    void addNodeEdge(BP_BaseNode *startNode, BP_BaseNode *endNode, BP_BasePort *source_port, BP_BasePort *des_port);

    void middleButton(const QMouseEvent *event);

    void leftButton(const QMouseEvent *event);

    void creat_dragging_edge(BP_BasePort *item,const QMouseEvent *event);

    void update_drage_edge(QMouseEvent *event);
};


#endif //TEST_BP_GRIDBACKGROUNDVIEW_H
