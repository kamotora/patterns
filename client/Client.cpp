//
// Created by root on 24.10.2019.
//

#include "Client.h"

#include <utility>
#include <iostream>

void Client::addGoodToOrder() {

}

void Client::pay() {
    cout << "Заказ №" << currentOrder->getNumber() << " оплачен" << endl;
    currentOrder->setStatus(Status::TypeStatus::PAID);
}

void Client::changeInfo() {

}

void Client::chooseDeliveryMethod() {

}

void Client::delGoodFromOrder() {

}

string Client::getAddress() {
    return address;
}

Client::Client(string name, string address, string tel) :name(std::move(name)), address(std::move(address)), tel(std::move(tel)){

}

Order* Client::createNewOrder() {
    if(currentOrder != nullptr && currentOrder->getStatus() == Status::TypeStatus::DECORATED){
        cout << "Клиент "<<name<< "Есть неоплаченный заказ"<< endl;
    }
    Order *order = new Order(this,this->address, TypeDelivery::COURIER);
    ordersHistory.push_back(order);
    currentOrder = order;
    return order;
}

