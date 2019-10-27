//
// Created by root on 24.10.2019.
//

#ifndef PATTERNS_CLIENT_H
#define PATTERNS_CLIENT_H
#include <string>
#include <vector>
#include "Order.h"


using namespace std;

class Order;

class Client {
private:
    string name;
    string address;
    string tel;
    vector<Order *> prevOrders;
    Order * currentOrder;
public:
    Client();
    void pay();
    void changeInfo();
    void chooseDeliveryMethod();
    void addGoodToOrder();
    void delGoodFromOrder();
};


#endif //PATTERNS_CLIENT_H
