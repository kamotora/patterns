//
// Created by root on 24.10.2019.
//

#ifndef PATTERNS_IDELIVER_H
#define PATTERNS_IDELIVER_H

#include "../client/IOrder.h"

class IDeliver {
public:
    virtual void deliver(IOrder *order) = 0;
    virtual IOrder *getCurOrder() = 0;
};


#endif //PATTERNS_IDELIVER_H
