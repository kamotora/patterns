//
// Created by root on 24.10.2019.
//

#ifndef PATTERNS_ORDER_H
#define PATTERNS_ORDER_H

#include "IOrder.h"
#include "Client.h"
#include "../workers/Delivers.h"

class Good;
class Client;


class Order : public IOrder {
public:

private:
    vector<Good *> goods;
    Status::TypeStatus status;
    struct tm * date;
    int number;
    Client* client;
    string address;
    IDeliver *deliver;

public:
    Order(Client *client, TypeDelivery typeDelivery) ;
    Order(Client *client, string address, TypeDelivery typeDelivery);
    Order(Client *client, string address, TypeDelivery typeDelivery, vector<Good *> goods);
    Status::TypeStatus getStatus() override;

    void setStatus(Status::TypeStatus status) override;

    string getAddress() override;

    Client* getClient() override;

    double countPrice() override;

    int getNumber() override;

    void addGood(Good *godd) override;

    vector<Good *> getGoods() override;

    IDeliver* getDeliver() override;

    void setTypeDelivery(TypeDelivery typeDelivery) override;
};


#endif //PATTERNS_ORDER_H
