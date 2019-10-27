//
// Created by root on 24.10.2019.
//

#ifndef PATTERNS_ORDER_H
#define PATTERNS_ORDER_H

#include "IOrder.h"
#include "Client.h"

class Good;
class Client;

class Order : public IOrder {
private:
    vector<Good *> goods;
    Status * status;
    int date;
    int number;
    Client* client;
    string address;
public:
    Status* getStatus() override;

    void setStatus(Status* status) override;

    const string* getAddress() override;

    Client* getClient() override;

    double countPrice() override;
};


#endif //PATTERNS_ORDER_H
