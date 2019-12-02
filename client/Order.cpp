#include "Order.h"
#include "../workers/Courier.h"
#include "../workers/Drone.h"
#include "../goods/ProductIterator.h"

#include <utility>
#include <iostream>

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
    double salePrice = 0.0;
    for(Product * good : goods)
        salePrice += good->getSaleCost();
    ProductIterator *iterator = new ProductIterator(&goods);
    double primePrice = 0.0;
    while(iterator->hasNext()){
        iterator->getNext();
        primePrice += iterator->getPrimeCostCur();
    }
    std::cout << "Для заказа №" << this->number << " цена продажи = " << salePrice << ", цена себестоимости = " << primePrice << std::endl;
    return salePrice;
}

int Order::getNumber() {
    return number;
}

void Order::addGood(Product *good) {
    goods.push_back(good);
}

vector<Product *> Order::getGoods() {
    return goods;
}


Order::Order(Client *client, TypeDelivery typeDelivery) : client(client){
    address = client->getAddress();
    status = Status::TypeStatus::DECORATED;
    time_t timeInSeconds;
    time(&timeInSeconds);
    date = localtime(&timeInSeconds);
    number = rand() % 100;
    setTypeDelivery(typeDelivery);
}

Order::Order(Client *client, string address, TypeDelivery typeDelivery) : Order(client,typeDelivery){
    address = std::move(address);
}

Order::Order(Client *client, string address, TypeDelivery typeDelivery, vector<Product *> goods) : Order(client, address, typeDelivery){
    this->goods = std::move(goods);
}

IDeliver* Order::getDeliver() {
    return deliver;
}

void Order::setTypeDelivery(TypeDelivery typeDelivery) {
    switch(typeDelivery){
        case COURIER:
            deliver = Delivers::getInstance()->getFreeCourier();
            break;
        case DRONE:
            deliver = Delivers::getInstance()->getFreeDrone();
            break;
        case NONE:
            printf("Error! Неизвестный тип доставщика при создании заказа");
    }
    if(deliver == nullptr)
        printf("Error! Нет свободных доставщиков данного типа. Попробуйте выбрать другой тип доставки");
}

Order::Order(vector<Product *>  goods, Status::TypeStatus status, tm * date,
        int number, Client * client, string address,IDeliver *deliver):
        goods (std::move(goods)), status(status), date(date), number(number), client(client), address(std::move(address)), deliver(deliver) {}



