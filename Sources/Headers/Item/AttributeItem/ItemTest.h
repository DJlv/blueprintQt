//
// Created by admin on 2024/1/7.
//

#ifndef BLUEPRINT_ITEMTEST_H
#define BLUEPRINT_ITEMTEST_H
#include <QObject>
#include <QGroupBox>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>

#include "Port/BP_BasePort.h"
#include "Attribute/BP_Attribute.h"

class ItemTest:  public BP_Attribute {
    Q_OBJECT
public:
    explicit ItemTest(QWidget *parent = nullptr);

/**
 * 信号
 */
signals:
    void pushStyle(QString text);
/**
 * 槽
 */
public slots:
    void handleButtonClicked(BP_BasePort *nodeport);
    void buttonClicked();
private:
    BP_BasePort *nodeportItem;
    QLabel *label = nullptr;
    QLineEdit *lineEdit = nullptr;

    QString orglinight = "";
    void endLayout();
};


#endif //BLUEPRINT_ITEMTEST_H
