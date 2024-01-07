//
// Created by admin on 2024/1/7.
//

#ifndef BLUEPRINT_ITEMTEST_H
#define BLUEPRINT_ITEMTEST_H
#include <QObject>
#include <QGroupBox>
#include <QLineEdit>

class ItemTest:  public QWidget {
    Q_OBJECT
public:
    explicit ItemTest(QWidget *parent = nullptr);
public slots:
    void handleButtonClicked();
    void buttonClicked();
signals:
    void pushStyle(QString text);

private:
    QString x =0;
    QPushButton* button= nullptr;
    QLineEdit *lineEdit = nullptr;
};


#endif //BLUEPRINT_ITEMTEST_H
