//
// Created by admin on 2023/11/22.
//

#ifndef TEST_BP_GRIDGROUPSCENCE_H
#define TEST_BP_GRIDGROUPSCENCE_H
#include <QGraphicsScene>
#include <QObject>
#include <QMouseEvent>
#include <QWidget>
#include <QPainter>



class BP_GridGroupScence: public QGraphicsScene {
    Q_OBJECT
public:
    explicit BP_GridGroupScence(QWidget *parent = nullptr);

};


#endif //TEST_BP_GRIDGROUPSCENCE_H
