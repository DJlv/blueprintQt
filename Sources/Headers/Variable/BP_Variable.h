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
#include "Edge/BP_Edge.h"

namespace BP_Variable {
    extern QList<BP_BaseNode*> NodeLists;
    extern QList<BP_Edge*> EdgeLists;
    void AddNodeToList();
};




#endif //TEST_BP_VARIABLE_H
