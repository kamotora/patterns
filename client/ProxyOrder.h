#ifndef PATTERNS_PROXYORDER_H
#define PATTERNS_PROXYORDER_H

#include "IOrder.h"
#include "Order.h"

class Order;

class ProxyOrder : IOrder{
private:
    Order* order;
public:
    Status* getStatus() override;

private:
    void setStatus(Status *status) override;

    const string *getAddress() override;

public:

    Client* getClient() override;

    double countPrice() override;
};


#endif //PATTERNS_PROXYORDER_H
