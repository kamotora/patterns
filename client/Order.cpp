//
// Created by root on 24.10.2019.
//

#include "Order.h"

Status* Order::getStatus() {
    return status;
}

void Order::setStatus(Status* status) {
    this->status = status;
}

const string* Order::getAddress() {
    return &address;
}

Client* Order::getClient() {
    return client;
}

double Order::countPrice() {
    return 0;
}
