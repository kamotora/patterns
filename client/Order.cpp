//
// Created by root on 24.10.2019.
//

#include "Order.h"

#include <utility>

Status::TypeStatus  Order::getStatus() {
    return status;
}

void Order::setStatus(Status::TypeStatus  status) {
    this->status = status;
}

string Order::getAddress() {
    return address;
}

Client* Order::getClient() {
    return client;
}

double Order::countPrice() {
    double price = 0.0;
    for(Good *good : goods)
        price += good->getCost();
    return price;
}

int Order::getNumber() {
    return number;
}

void Order::addGood(Good *good) {
    goods.push_back(good);
}

vector<Good *> Order::getGoods() {
    return goods;
}


Order::Order(Client *client, TypeDelivery typeDelivery) : client(client), typeDelivery(typeDelivery){
    address = client->getAddress();
    status = Status::TypeStatus::DECORATED;
    time_t timeInSeconds;
    time(&timeInSeconds);
    date = localtime(&timeInSeconds);
    number = rand() % 100;
}

Order::Order(Client *client, string address, TypeDelivery typeDelivery) : Order(client,typeDelivery){
    address = std::move(address);
}

Order::Order(Client *client, string address, TypeDelivery typeDelivery, vector<Good *> goods) :Order(client,address,typeDelivery){
    this->goods = std::move(goods);
}

TypeDelivery Order::getTypeDelivery() {
    return typeDelivery;
}

void Order::setTypeDelivery(TypeDelivery typeDelivery) {
    Order::typeDelivery = typeDelivery;
}

