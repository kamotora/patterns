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

void ProxyOrder::addGood(Product *good) {
    order->addGood(good);
}

vector<Product *> ProxyOrder::getGoods() {
    return order->getGoods();
}


Status::TypeStatus ProxyOrder::getStatus() {
    return order->getStatus();
}

void ProxyOrder::setStatus(Status::TypeStatus status) {
    order->setStatus(status);
}

string ProxyOrder::getAddress() {
    if(order->getStatus() <= Status::TypeStatus::COOK){
        cout << "Передать заказ №" << order->getNumber() << " в доставку пока что нельзя" << endl;
        return "";
    }
    return order->getAddress();
}

IDeliver *ProxyOrder::getDeliver() {
    if(order->getStatus() <= Status::TypeStatus::COOK){
        cout << "Передать заказ №" << order->getNumber() << " в доставку пока что нельзя" << endl;
        return nullptr;
    }
    return order->getDeliver();
}

void ProxyOrder::setTypeDelivery(TypeDelivery typeDelivery) {
    order->setTypeDelivery(typeDelivery);
}
