#ifndef PATTERNS_PROXYORDER_H
#define PATTERNS_PROXYORDER_H

#include "IOrder.h"
#include "Order.h"

class Order;

class ProxyOrder : public IOrder{
private:
    Order* order;

public:
    ProxyOrder(Order *order);

    Client* getClient() override;

    double countPrice() override;

    int getNumber() override;

    void addGood(Product *good) override;

    vector<Product *> getGoods() override;


    Status::TypeStatus getStatus() override;

    void setStatus(Status::TypeStatus status) override;

    string getAddress() override;

    IDeliver *getDeliver() override;

    void setTypeDelivery(TypeDelivery typeDelivery) override;

    void setClient(Client *client) override;
};


#endif //PATTERNS_PROXYORDER_H
