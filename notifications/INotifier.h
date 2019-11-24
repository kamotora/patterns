//
// Created by artem on 11.11.2019.
//

#ifndef PATTERNS_INOTIFIER_H
#define PATTERNS_INOTIFIER_H

#include "../client/IOrder.h"
#include "../client/Client.h"

class INotifier {
public:
    virtual void notify(IOrder *order) = 0;
};


#endif //PATTERNS_INOTIFIER_H
