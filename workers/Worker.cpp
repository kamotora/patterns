//
// Created by root on 24.10.2019.
//

#include "Worker.h"

IOrder* Worker::getNextOrder() {
    if(ordersQueue.empty())
        return nullptr;
    return ordersQueue.front();
}
