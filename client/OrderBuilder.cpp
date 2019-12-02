//
// Created by artem on 30.11.2019.
//

#include "OrderBuilder.h"

void OrderBuilder::setGoods(const vector<Product *> & goods) {
    OrderBuilder::goods = goods;
}

void OrderBuilder::setStatus(Status::TypeStatus status) {
    OrderBuilder::status = status;
}

void OrderBuilder::setDate(tm *date) {
    OrderBuilder::date = date;
}

void OrderBuilder::setNumber(int number) {
    OrderBuilder::number = number;
}

void OrderBuilder::setClient(Client *client) {
    OrderBuilder::client = client;
}

void OrderBuilder::setAddress(const string &address) {
    OrderBuilder::address = address;
}

void OrderBuilder::setDeliver(IDeliver *deliver) {
    OrderBuilder::deliver = deliver;
}

void OrderBuilder::setTypeDelivery(TypeDelivery typeDelivery) {
    OrderBuilder::typeDelivery = typeDelivery;
}

Order* OrderBuilder::build() {
    if(date == nullptr){
        address = client->getAddress();
        status = Status::TypeStatus::DECORATED;
        time_t timeInSeconds;
        time(&timeInSeconds);
        date = localtime(&timeInSeconds);
    }

    if(number == 0){
        number = rand() % 100;
    }
    if(deliver == nullptr){
        auto deliversStorage = Delivers::getInstance();
        //Если тип доставки не указан, берем любого
        if(typeDelivery == NONE){
            deliver = deliversStorage->getFreeCourier();
            if(deliver == nullptr)
                deliver = deliversStorage->getFreeDrone();
            if(deliver == nullptr)
                printf("Error! Нет свободных доставщиков. Придется подождать");
        }
        else if(typeDelivery == COURIER)
            deliver = Delivers::getInstance()->getFreeCourier();
        else
            deliver = Delivers::getInstance()->getFreeDrone();
        if(deliver == nullptr)
            printf("Error! Нет свободных доставщиков данного типа. Попробуйте выбрать другой тип доставки");
    }
    if(client == nullptr){
        printf("Error! Без клиента нельзя");
        return nullptr;
    }

    if(address.empty())
        address = client->getAddress();

    if(status == Status::NONE)
        status = Status::DECORATED;

    auto order =  new Order(goods,status,date,number,client,address,deliver);
    reset();
    return order;
}

void OrderBuilder::addGood(Product *product) {
    goods.push_back(product);
}

void OrderBuilder::reset() {
    goods.resize(0);
    status = Status::TypeStatus::NONE;
    date = nullptr;
    number = 0;
    client = nullptr;
    address = "";
    deliver = nullptr;
    typeDelivery = TypeDelivery::NONE;
}


