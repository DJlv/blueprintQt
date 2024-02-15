//
// Created by admin on 2024/2/15.
//

#ifndef BLUEPRINT_BP_ATTRIBUTE_H
#define BLUEPRINT_BP_ATTRIBUTE_H
#include <QObject>
#include <QGroupBox>
#include <QVBoxLayout>
#include "Port/BP_BasePort.h"

class BP_BasePort;
class BP_Attribute:  public QWidget  {
Q_OBJECT
public:
    explicit BP_Attribute(QWidget *parent = nullptr);

private:
    QVBoxLayout *layout = nullptr;
public slots:
    virtual void handleButtonClicked(BP_BasePort *nodeport);
public:
    virtual void endLayout();
    void initPortAttribute();
    void clearLayout(QLayout *layout);
};


#endif //BLUEPRINT_BP_ATTRIBUTE_H
