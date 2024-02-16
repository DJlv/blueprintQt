//
// Created by admin on 2023/11/18.
//

#ifndef TEST_BP_VARIABLE_H
#define TEST_BP_VARIABLE_H
#include "Node/BP_BaseNode.h"
#include "Item/NodeItem/BP_ProgramEntry.h"
#include "Item/NodeItem/BP_PrintNode.h"
#include <QList>
#include <QString>
#include <QFile>
#include <QGroupBox>
#include <QTextEdit>
#include <QDateTime>
#include "Edge/BP_Edge.h"

namespace BP_Variable {
    extern QList<BP_BaseNode*> NodeLists;
    extern QList<BP_Edge*> EdgeLists;
    extern QGroupBox* qGroupBox;
    extern QTextEdit* textEdit;
    extern QTextEdit* console;
    extern QString pathAll;

    void getItemFile();
    void AddNodeToList();

    void getPlintConsole(const QString str);
};




#endif //TEST_BP_VARIABLE_H
