//
// Created by admin on 2023/11/17.
//

#ifndef TEST_BP_PIN_H
#define TEST_BP_PIN_H
#include <QObject>
#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QFont>
#include <QDebug>
class BP_Pin :public QObject,public QGraphicsItem {
    Q_OBJECT
public:
    explicit BP_Pin(QGraphicsItem *parent = nullptr);


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
public:
    explicit BP_Pin(PinType type, QGraphicsItem *parent = nullptr);
    void setType(PinType type);
    void setInTiTle(QString title);
    void setOutTitle(QString title);
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


#endif //TEST_BP_PIN_H
