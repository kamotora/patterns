//
// Created by root on 24.10.2019.
//

#ifndef PATTERNS_WORKER_H
#define PATTERNS_WORKER_H

#include <vector>
#include "../client/IOrder.h"

class Worker {
private:
    vector<IOrder *> ordersQueue;
    string name;
public:
    IOrder*  getNextOrder();
};


#endif //PATTERNS_WORKER_H
