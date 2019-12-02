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

IOrder* Client::createNewOrder(CreatorOrder *creator) {

}

const string &Client::getTel() const {
    return tel;
}

const string &Client::getEmail() const {
    return email;
}

Client::Client(string name, string address, string tel, string email) :Client(std::move(name),std::move(address),std::move(tel)){
    this->email = std::move(email);
}

bool Client::equals(std::string name, std::string address, std::string tel) {
    return this->name == name && this->address == address && this->tel == tel;
}

bool Client::equals(std::string name, std::string address, std::string tel, std::string email) {
    return equals(name,address,tel) && this->email == email;
}

void Client::addOrder(IOrder *order) {
    ordersHistory.push_back(order);
    currentOrder = order;
}

const string &Client::getName() const {
    return name;
}



