//
// Created by admin on 2023/11/24.
//

#ifndef TEST_BP_EXECPORT_H
#define TEST_BP_EXECPORT_H
#include "Port/BP_BasePort.h"
#include "Port/PinType.h"
class BP_ExecPort: public BP_BasePort{
public:
    explicit BP_ExecPort(QGraphicsItem *parent = nullptr);
    explicit BP_ExecPort(PinType type, QGraphicsItem *parent = nullptr);

    void setInTiTle(QString title);
    void setOutTitle(QString title);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;


public:
    QString InTiTle;
    QString OutTitle;

    QString port_lable;
    QColor port_color;
    int port_type{};
    int font_size = 12;
    bool flage = false;
    QList<BP_Edge*> edgeList;
    BP_BaseNode* node{};
    void add_Edge(BP_Edge* edgeItem);
    void add_to_parent_node(BP_BaseNode* nodeItem);
};


#endif //TEST_BP_EXECPORT_H
