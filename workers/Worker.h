//
// Created by root on 24.10.2019.
//

#ifndef PATTERNS_WORKER_H
#define PATTERNS_WORKER_H

#include <vector>
#include "../client/IOrder.h"

class Worker {
protected:
    vector<IOrder *> ordersQueue;
    IOrder *curOrder;
    string name;
public:
    Worker(string name);
    IOrder*  getNextOrder();
    void addOrder(IOrder *order);

    IOrder *getCurOrder() const;
};


#endif //PATTERNS_WORKER_H
