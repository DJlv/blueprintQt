//
// Created by admin on 2024/1/7.
//

#ifndef BLUEPRINT_BP_ITEMTEST_H
#define BLUEPRINT_BP_ITEMTEST_H
#include <QObject>
#include <QGroupBox>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QProcess>

#include "Port/BP_BasePort.h"
#include "Attribute/BP_Attribute.h"

class BP_ItemTest: public BP_Attribute {
    Q_OBJECT
public:
    explicit BP_ItemTest(QWidget *parent = nullptr);

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
    void lableClicked();
    void buttonCloseClicked();
private:
    BP_BasePort *nodeportItem;
    QLabel *label = nullptr;
    QLabel *label1 = nullptr;
    QLabel *label2 = nullptr;
    QLineEdit *labelTest = nullptr;
    QLineEdit *npmProject = nullptr;

    QPushButton* button;
    QPushButton* buttonClose;


    QLineEdit *lineEdit = nullptr;


    QString orglinight = "";
    bool start = false;
public:
    void endLayout();
};


#endif //BLUEPRINT_BP_ITEMTEST_H
