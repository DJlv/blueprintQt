//
// Created by admin on 2023/11/16.
//

#include "Item/NodeItem/BP_PrintNode.h"
#include <QPushButton>
#include <QCoreApplication>
#include <QLabel>
#include <QVBoxLayout>
#include <QLineEdit>
BP_PrintNode::BP_PrintNode(QGraphicsItem* parent): BP_BaseNode(parent) {
    BP_BaseNode::Title = "print";
    BP_BaseNode::Color = "#00EEEE";
}

QRectF BP_PrintNode::boundingRect() const {
    return QRectF(0, 0, 200, 100); // 定义节点的边界矩形
}

void BP_PrintNode::Simulation() {

}

void BP_PrintNode::SimulationStyle() {

}

void BP_PrintNode::slotButton() {
    QString text =  lineEdit->text();
    x = text;
    qDebug() << "print--------x::::"<< x;
}
void BP_PrintNode::slotLineEdit(QString text) {
    qDebug() << "lineEdit->text()--------lineEdit->text()::::"<< text;

}
void BP_PrintNode::mousePressEvent(QGraphicsSceneMouseEvent *event) {
}

