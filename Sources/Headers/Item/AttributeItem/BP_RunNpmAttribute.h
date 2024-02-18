//
// Created by admin on 2024/2/16.
//

#ifndef BLUEPRINT_BP_RUNNPMATTRIBUTE_H
#define BLUEPRINT_BP_RUNNPMATTRIBUTE_H
#include <QObject>
#include <QGroupBox>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QProcess>
#include <QFile>

#include "Port/BP_BasePort.h"
#include "Attribute/BP_BaseAttribute.h"

class BP_RunNpmAttribute: public BP_BaseAttribute {
Q_OBJECT
public:
    explicit BP_RunNpmAttribute(QWidget *parent = nullptr);
/**
 * 信号
 */
signals:
    void pushStyle(bool text);
/**
 * 槽
 */
public slots:
    void handleButtonClicked(BP_BasePort *nodeport);
    void buttonClicked();
    void buttonCloseClicked();
    void getFile();
    void pathAll();
private:
    BP_BasePort *nodeportItem;

    QLabel *label1 = nullptr;
    QLabel *label2 = nullptr;
    QLineEdit *npmProject = nullptr;
    QPushButton* buttonClose;
    QLineEdit *lineEdit = nullptr;
    QLineEdit *labelTest = nullptr;
    QPushButton* button;
    QPushButton* buttonFile;

    QString orglinight = "";
    bool start = false;
public:
    void endLayout();
public:
    void lableClicked();

};


#endif //BLUEPRINT_BP_RUNNPMATTRIBUTE_H
