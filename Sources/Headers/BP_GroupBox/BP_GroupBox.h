//
// Created by admin on 2024/1/6.
//

#ifndef BLUEPRINT_BP_GROUPBOX_H
#define BLUEPRINT_BP_GROUPBOX_H

#include <QGroupBox>

class BP_GroupBox: public QGroupBox {
    Q_OBJECT
public:
    explicit BP_GroupBox(QWidget *parent = nullptr);

public slots:
    void handleButtonClicked();

private:
    QGroupBox *qGroupBox;
};


#endif //BLUEPRINT_BP_GROUPBOX_H
