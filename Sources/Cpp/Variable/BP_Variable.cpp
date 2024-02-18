//
// Created by admin on 2023/11/18.
//

#include "Variable/BP_Variable.h"


QList<BP_BaseNode*> BP_Variable::NodeLists;
//QList<BP_Edge*> BP_Variable::EdgeLists;
QGroupBox* BP_Variable::qGroupBox;
QTextEdit* BP_Variable::textEdit;
QTextEdit* BP_Variable::console;
QString BP_Variable::pathAll;

void BP_Variable::AddNodeToList(){
    NodeLists.append(new BP_ProgramEntry);
}

void BP_Variable::getPlintConsole(QString str){
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString formattedDateTime = currentDateTime.toString("yyyyMMdd hh:mm:ss");
    QString items = BP_Variable::console->toPlainText()+formattedDateTime + "------:" + str+"\n";
    BP_Variable::console->setPlainText(items);
}

void BP_Variable::getItemFile(){
    if(pathAll == nullptr || pathAll == "") {
        console->setText("请在输入如见所在路径");
    }
    QFile file( pathAll+"/OtherApplication/vue-test-blue-print/src/views/HomeView.vue");
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
QString BP_Variable::getAgesFile(QString path,QString str) {
    if(pathAll == nullptr || pathAll == "") {
        console->setText("请在输入如见所在路径");
    }
    QFile file( pathAll+"/"+path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return "打开测试文件失败";
    } else {
        // 将文件内容读入到字符串变量中
        QString content = "";
        QTextStream in(&file);
        bool flage = false;
        while(!in.atEnd()) {
            QString strcItem = QString(in.readLine());
            if(QString("/--/-*"+str+"*-/-start-/") == strcItem) {
                flage = true;
                continue;
            }
            if(QString("/--/-*"+str+"*-/-end-/") == strcItem) {
                flage = false;
                continue;
            }
            if(flage) {
                content += strcItem+"\n";
            }
        }
        file.close();
        return content;
    }
}

