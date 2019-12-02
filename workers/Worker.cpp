//
// Created by root on 24.10.2019.
//

#include "Worker.h"

#include <utility>

IOrder* Worker::getNextOrder() {
    if(ordersQueue.empty())
        return nullptr;
    curOrder = ordersQueue.front();
    ordersQueue.pop();
    return curOrder;
}

Worker::Worker(string name) : name(std::move(name)){
}

void Worker::addOrder(IOrder *order) {
    ordersQueue.push(order);
}

IOrder *Worker::getCurOrder() const {
    return curOrder;
}

void Worker::setCurOrder(IOrder *curOrder) {
    Worker::curOrder = curOrder;
}
