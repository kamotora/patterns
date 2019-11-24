//
// Created by artem on 11.11.2019.
//

#ifndef PATTERNS_NOTIFIERADAPTER_H
#define PATTERNS_NOTIFIERADAPTER_H


#include "../workers/ICaller.h"
#include "INotifier.h"

class NotifierAdapter : public ICaller {
private:
    INotifier *notifier;
    string name;
public:
    NotifierAdapter(string name, INotifier *iNotifier);
    void call(IOrder *order) override ;
};


#endif //PATTERNS_NOTIFIERADAPTER_H
