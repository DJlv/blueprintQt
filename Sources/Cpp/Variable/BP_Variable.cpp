//
// Created by admin on 2023/11/18.
//

#include "Variable/BP_Variable.h"


QList<BP_BaseNode*> BP_Variable::NodeLists;
QList<BP_Edge*> BP_Variable::EdgeLists;
QGroupBox* BP_Variable::qGroupBox;
QTextEdit* BP_Variable::textEdit;
QTextEdit* BP_Variable::console;
void BP_Variable::AddNodeToList(){
    NodeLists.append(new BP_ProgramEntry);
}