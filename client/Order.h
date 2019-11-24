//
// Created by root on 24.10.2019.
//

#ifndef PATTERNS_ORDER_H
#define PATTERNS_ORDER_H

#include "IOrder.h"
#include "Client.h"
#include "../workers/Delivers.h"

class Product;
class Client;


class Order : public IOrder {
public:

private:
    vector<Product *> goods;
    Status::TypeStatus status;
    struct tm * date;
    int number;
    Client* client;
    string address;
    IDeliver *deliver;

public:
    Order(Client *client, TypeDelivery typeDelivery) ;
    Order(Client *client, string address, TypeDelivery typeDelivery);
    Order(Client *client, string address, TypeDelivery typeDelivery, vector<Product *> goods);
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

};


#endif //PATTERNS_ORDER_H
