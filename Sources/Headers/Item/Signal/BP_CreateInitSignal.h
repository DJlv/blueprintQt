//
// Created by admin on 2024/2/17.
//

#ifndef BLUEPRINT_BP_CREATEINITSIGNAL_H
#define BLUEPRINT_BP_CREATEINITSIGNAL_H


#include <QString>
#include "Signals/BP_BaseSignal.h"

class BP_CreateInitSignal: public BP_BaseSignal{
public:
    BP_CreateInitSignal();
public:
    QString text = "";
};


#endif //BLUEPRINT_BP_CREATEINITSIGNAL_H
