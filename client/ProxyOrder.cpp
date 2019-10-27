//
// Created by root on 24.10.2019.
//

#include "ProxyOrder.h"


Client* ProxyOrder::getClient() {
    return order->getClient();
}

double ProxyOrder::countPrice() {
    return 0;
}

void ProxyOrder::setStatus(Status *status) {

}

const string *ProxyOrder::getAddress() {
    return nullptr;
}
