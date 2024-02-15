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
#include <QGroupBox>
#include <QTextEdit>
#include "Edge/BP_Edge.h"

namespace BP_Variable {
    extern QList<BP_BaseNode*> NodeLists;
    extern QList<BP_Edge*> EdgeLists;
    extern QGroupBox* qGroupBox;
    extern QTextEdit* textEdit;
    extern QTextEdit* console;
    void AddNodeToList();
};




#endif //TEST_BP_VARIABLE_H
