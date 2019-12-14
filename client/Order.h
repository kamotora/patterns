//
// Created by root on 24.10.2019.
//

#ifndef PATTERNS_ORDER_H
#define PATTERNS_ORDER_H

#include "IOrder.h"
#include "Client.h"
#include "../workers/Delivers.h"
#include "IObservable.h"
#include <map>
#include "../workers/Courier.h"
#include "../workers/Drone.h"
#include "../goods/ProductIterator.h"
#include "../goods/sort/BubbleSort.h"
#include <utility>
#include <iostream>

class Product;
class Client;


class Order : public IOrder, public IObservable {
private:
    vector<Product *> goods;
    Status::TypeStatus status;
    struct tm * date;
    int number;
    Client* client;
    string address;
    IDeliver *deliver;
    std::map<IObserver *, Status::TypeStatus> observers;

public:
    Order(Client *client, TypeDelivery typeDelivery) ;
    Order(Client *client, string address, TypeDelivery typeDelivery);
    Order(Client *client, string address, TypeDelivery typeDelivery, vector<Product *> goods);

    Order(vector<Product*>  goods, Status::TypeStatus status, tm * date,
            int number, Client * client, string  address, IDeliver *deliver);

    Status::TypeStatus getStatus() override;

    void setStatus(Status::TypeStatus status) override;

    string getAddress() override;

    Client* getClient() override;

    double countPrice() override;

    int getNumber() override;

    void addGood(Product *good) override;

    vector<Product *> getGoods() override;

    IDeliver* getDeliver() override;

    void setTypeDelivery(TypeDelivery typeDelivery) override;

    void addObserver(IObserver *observer,Status::TypeStatus typeStatusOrder) override;

    void removeObserver(IObserver *observer) override;

    void notifyObservers() override;

    void setClient(Client *client) override ;
};


#endif //PATTERNS_ORDER_H
