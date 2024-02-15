//
// Created by admin on 2024/1/7.
//

#ifndef BLUEPRINT_ITEMTEST_H
#define BLUEPRINT_ITEMTEST_H
#include <QObject>
#include <QGroupBox>
#include <QLineEdit>
#include <QVBoxLayout>

#include "Port/BP_BasePort.h"

class ItemTest:  public QWidget {
    Q_OBJECT
public:
    explicit ItemTest(QWidget *parent = nullptr);
    void clearLayout(QLayout *layout);
    ItemTest& operator=(const ItemTest *po);

public slots:
    void handleButtonClicked(BP_BasePort *nodeport);
    void buttonClicked();

signals:
    void pushStyle(QString text);

private:
    BP_BasePort *nodeportItem;
    QVBoxLayout *layout = nullptr;
    QString x =0;
    QPushButton* button= nullptr;
    QLineEdit *lineEdit = nullptr;

};


#endif //BLUEPRINT_ITEMTEST_H
