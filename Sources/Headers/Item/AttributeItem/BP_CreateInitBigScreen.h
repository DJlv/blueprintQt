//
// Created by admin on 2024/2/17.
//

#ifndef BLUEPRINT_BP_CREATEINITBIGSCREEN_H
#define BLUEPRINT_BP_CREATEINITBIGSCREEN_H

#include <QObject>
#include <QGroupBox>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QProcess>

#include "Port/BP_BasePort.h"
#include "Variable/BP_Variable.h"
#include "Attribute/BP_BaseAttribute.h"
#include "Signals/BP_BaseSignal.h"
#include "Item/Signal/BP_CreateInitSignal.h"

class BP_CreateInitBigScreen: public BP_BaseAttribute {
Q_OBJECT
public:
    explicit BP_CreateInitBigScreen(QWidget *parent = nullptr);
/**
 * 信号
 */
signals:
    void pushStyle(BP_BaseSignal* signlePasser);
/**
 * 槽
 */
public slots:
    void handleButtonClicked(BP_BasePort *nodeport);
    void lableClicked();

private:
    BP_CreateInitSignal* signleItem;
    BP_BasePort *nodeportItem;
    QLabel *label = nullptr;
    QLineEdit *lineEdit = nullptr;
    QString orglinight = "";
public:
    void endLayout();
};


#endif //BLUEPRINT_BP_CREATEINITBIGSCREEN_H
