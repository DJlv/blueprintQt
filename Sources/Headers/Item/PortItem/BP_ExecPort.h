//
// Created by admin on 2023/11/24.
//

#ifndef TEST_BP_EXECPORT_H
#define TEST_BP_EXECPORT_H
#include "Port/BP_BasePort.h"

class BP_ExecPort: public BP_BasePort{
public:

    enum PinType {
        Input,
        Output
    };

    enum PinvType {
        port_type_in = 1001,
        port_type_out = 1002,
        port_type_param = 1003,
        port_type_output = 1004
    };
    explicit BP_ExecPort(QGraphicsItem *parent = nullptr);
    explicit BP_ExecPort(QString lable="",QString port_class="str",QColor color="#FFFFFF",int port_type = PinvType::port_type_in,QGraphicsItem* parent= nullptr);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;

private:
    PinType m_type;
    QString InTiTle;
    QString OutTitle;



    QString port_lable;
    QString port_class;
    QColor port_color;
    int port_type;
    int prot_width;
    int prot_lable_size;
    int prot_icon_size = 20;
    int font_size = 12;
};


#endif //TEST_BP_EXECPORT_H
