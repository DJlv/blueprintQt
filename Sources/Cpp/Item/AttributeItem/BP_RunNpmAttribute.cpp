//
// Created by admin on 2024/2/16.
//

#include "Item/AttributeItem/BP_RunNpmAttribute.h"
#include "Variable/BP_Variable.h"

BP_RunNpmAttribute::BP_RunNpmAttribute(QWidget *parent) : BP_BaseAttribute(parent) {

}

void BP_RunNpmAttribute::handleButtonClicked(BP_BasePort *nodeport) {
    BP_BaseAttribute::initPortAttribute();
    nodeportItem = nodeport;
    label1 = new QLabel("软件目录:", BP_Variable::qGroupBox); // 将标签添加到 QGroupBox
    label1->setFixedSize(70, 30);
    labelTest = new QLineEdit("D:\\newProject\\Qt\\blueprint");
    labelTest->setFixedSize(250, 30);
    label2 = new QLabel("npm目录:", BP_Variable::qGroupBox); // 将标签添加到 QGroupBox
    label2->setFixedSize(70, 30);
    npmProject = new QLineEdit("C:\\Users\\12141\\AppData\\Roaming\\npm");
    npmProject->setFixedSize(250, 30);


    button = new QPushButton("启动npm", BP_Variable::qGroupBox);
    button->setFixedSize(100, 30);
    buttonClose = new QPushButton("关闭npm", BP_Variable::qGroupBox);
    buttonClose->setFixedSize(100, 30);
    buttonFile = new QPushButton("打开测试文件", BP_Variable::qGroupBox);
    buttonFile->setFixedSize(100, 30);
    connect(button, &QPushButton::clicked, this, &BP_RunNpmAttribute::buttonClicked);
    connect(buttonClose, &QPushButton::clicked, this, &BP_RunNpmAttribute::buttonCloseClicked);
    connect(buttonFile, &QPushButton::clicked, this, &BP_RunNpmAttribute::getFile);

    connect(lineEdit, &QLineEdit::textChanged, this, &BP_RunNpmAttribute::pathAll);

    endLayout();
}
void BP_RunNpmAttribute::pathAll() {
    BP_Variable::pathAll = label1->text();
}
void BP_RunNpmAttribute::buttonClicked() {
    if (!start) {
        BP_Variable::console->setText("开始启动程序:执行 npm run serve 命令");
        QProcess process;
        QString program = npmProject->text() + "\\npm.cmd";  // CMD程序路径
        QStringList arguments;
        arguments << "run" << "serve";  // CMD命令和参数
        QString workingDirectory = labelTest->text() + "\\OtherApplication\\vue-test-blue-print";
        process.setWorkingDirectory(workingDirectory);
        process.start(program, arguments);
        if (process.waitForStarted()) {
            start = true;
            lableClicked();
        } else {
            start = false;
            lableClicked();
        }
        process.waitForFinished();
        BP_Variable::console->setText(QString::fromLocal8Bit(process.readAllStandardOutput()));
    }
}
void BP_RunNpmAttribute::getFile() {
    BP_Variable::pathAll = labelTest->text();
    QFile file(labelTest->text()+"/OtherApplication/vue-test-blue-print/src/views/HomeView.vue");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        BP_Variable::textEdit->setText("打开测试文件失败");
    } else {
        // 将文件内容读入到字符串变量中
        QString content = "";
        QTextStream in(&file);
        while(!in.atEnd()) {
            content += in.readLine()+"\n";
        }
        file.close();
        BP_Variable::textEdit->setText(content);
    }
}

void BP_RunNpmAttribute::lableClicked() {
    connect(this, SIGNAL(pushStyle(bool)), nodeportItem, SLOT(slotLineEdit(bool)));
    emit(pushStyle(start));
    disconnect(this, SIGNAL(pushStyle(bool)), nodeportItem, SLOT(slotLineEdit(bool)));
    update();
}

void BP_RunNpmAttribute::buttonCloseClicked() {
    QProcess process;
    if (start) {
        process.start("taskkill", QStringList() << "/f" << "/im" << "node.exe");
        process.waitForStarted();
        process.waitForFinished();
        BP_Variable::textEdit->setText(QString::fromLocal8Bit(process.readAllStandardOutput()));
    }
}

void BP_RunNpmAttribute::endLayout() {
    QVBoxLayout *groupBoxLayout = qobject_cast<QVBoxLayout *>(BP_Variable::qGroupBox->layout());

    QHBoxLayout *qHBoxLayout2 = new QHBoxLayout();
    qHBoxLayout2->addWidget(label1);
    qHBoxLayout2->addWidget(labelTest);
    groupBoxLayout->addLayout(qHBoxLayout2);

    QHBoxLayout *qHBoxLayout3 = new QHBoxLayout();
    qHBoxLayout3->addWidget(label2);
    qHBoxLayout3->addWidget(npmProject);
    groupBoxLayout->addLayout(qHBoxLayout3);

    QHBoxLayout *qHBoxLayout4 = new QHBoxLayout();
    qHBoxLayout4->addWidget(button);
    qHBoxLayout4->addWidget(buttonClose);
    qHBoxLayout4->addWidget(buttonFile);

    groupBoxLayout->addLayout(qHBoxLayout4);
    groupBoxLayout->addStretch();
}
