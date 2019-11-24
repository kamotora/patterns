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
    string email;
    vector<Order *> ordersHistory;
    Order * currentOrder;
public:
    Client(string name, string address, string tel);
    Order* createNewOrder();
    void pay();
    void changeInfo();
    void chooseDeliveryMethod();
    void addGoodToOrder();
    void delGoodFromOrder();
    string getAddress();

    const string &getTel() const;

    const string &getEmail() const;
};


#endif //PATTERNS_CLIENT_H
