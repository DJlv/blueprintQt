//
// Created by admin on 2024/1/7.
//

#include <QPushButton>
#include <QCoreApplication>
#include "Variable/BP_Variable.h"
#include "Item/AttributeItem/BP_ItemTest.h"


BP_ItemTest::BP_ItemTest(QWidget *parent) {

}

void BP_ItemTest::handleButtonClicked(BP_BasePort *nodeport) {
    BP_BaseAttribute::initPortAttribute();
    nodeportItem = nodeport;
    label = new QLabel("日志文本:", BP_Variable::qGroupBox); // 将标签添加到 QGroupBox
    label->setFixedSize(70, 30);
    lineEdit = new QLineEdit();
    lineEdit->setFixedSize(250, 30);
    lineEdit->setPlaceholderText("请输入文本"); // 设置占位符文本;
    connect(lineEdit, &QLineEdit::textChanged, this, &BP_ItemTest::lableClicked);

    endLayout();
}

void BP_ItemTest::endLayout() {
    QVBoxLayout *groupBoxLayout = qobject_cast<QVBoxLayout *>(BP_Variable::qGroupBox->layout());
    QHBoxLayout *qHBoxLayout1 = new QHBoxLayout();
    qHBoxLayout1->addWidget(label);
    qHBoxLayout1->addWidget(lineEdit);
    groupBoxLayout->addLayout(qHBoxLayout1);
    groupBoxLayout->addStretch();
}


void BP_ItemTest::lableClicked() {
    connect(this, SIGNAL(pushStyle(QString)), nodeportItem, SLOT(slotLineEdit(QString)));
    connect(lineEdit, SIGNAL(editingFinished()), this, SLOT(buttonClicked()));
    if (lineEdit->text() != orglinight) {
        emit(pushStyle(lineEdit->text()));
        orglinight = lineEdit->text();
    }
    disconnect(lineEdit, SIGNAL(editingFinished()), this, SLOT(buttonClicked()));
    disconnect(this, SIGNAL(pushStyle(QString)), nodeportItem, SLOT(slotLineEdit(QString)));
    update();
}

void BP_ItemTest::buttonClicked() {
    if (!start) {
        BP_Variable::console->setText("开始启动程序:执行 npm run serve 命令");
        update();
        QProcess process;
        QString program = npmProject->text()+"\\npm.cmd";  // CMD程序路径
        QStringList arguments;
        arguments << "run" << "serve";  // CMD命令和参数
        QString workingDirectory = labelTest->text()+ "\\OtherApplication\\vue-test-blue-print";
        process.setWorkingDirectory(workingDirectory);
        process.start(program, arguments);
        if (process.waitForStarted()) {
            start = true;
        } else {
            start = false;
        }
        process.waitForFinished();
        BP_Variable::textEdit->setText(QString::fromLocal8Bit(process.readAllStandardOutput()));
    }
}


