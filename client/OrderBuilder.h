//
// Created by artem on 30.11.2019.
//

#ifndef PATTERNS_ORDERBUILDER_H
#define PATTERNS_ORDERBUILDER_H
#include "Client.h"
#include "../workers/Delivers.h"
#include "Order.h"
class Product;
class Client;

//TODO использовать где нибудь
class OrderBuilder {
private:
    vector<Product *> goods;
    Status::TypeStatus status = Status::TypeStatus::NONE;
    struct tm * date = nullptr;
    int number = 0;
    Client* client = nullptr;
    string address = "";
    IDeliver *deliver = nullptr;
    TypeDelivery typeDelivery = TypeDelivery::NONE;
public:
    void addGood(Product *product);
    void setGoods(const vector<Product *> & goods);

    void setStatus(Status::TypeStatus status);

    void setDate(tm *date);

    void setNumber(int number);

    void setClient(Client *client);

    void setAddress(const string &address);

    void setDeliver(IDeliver *deliver);

    void setTypeDelivery(TypeDelivery typeDelivery);

    Order* build();
    void reset();
};


#endif //PATTERNS_ORDERBUILDER_H
