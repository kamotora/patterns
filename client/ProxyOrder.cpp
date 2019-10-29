//
// Created by root on 24.10.2019.
//

#include <iostream>
#include "ProxyOrder.h"


Client* ProxyOrder::getClient() {
    return order->getClient();
}

double ProxyOrder::countPrice() {
    return order->countPrice();
}

ProxyOrder::ProxyOrder(Order *order) {
    if(order == nullptr){
        std::cerr << "order == null in ProxyOrder constructor";
        return;
    }
    this->order = order;
}

int ProxyOrder::getNumber() {
    return order->getNumber();
}

void ProxyOrder::addGood(Good *good) {
    order->addGood(good);
}

vector<Good *> ProxyOrder::getGoods() {
    return order->getGoods();
}

TypeDelivery ProxyOrder::getTypeDelivery() {
    if(order->getStatus() <= Status::TypeStatus::COOK){
        cout << "Передать заказ №" << order->getNumber() << " в доставку пока что нельзя" << endl;
        return TypeDelivery::NONE;
    }
    return order->getTypeDelivery();
}

Status::TypeStatus ProxyOrder::getStatus() {
    return order->getStatus();
}

void ProxyOrder::setStatus(Status::TypeStatus status) {
    order->setStatus(status);
}

string ProxyOrder::getAddress() {
    return order->getAddress();
}