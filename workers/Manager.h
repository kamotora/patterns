#ifndef PATTERNS_MANAGER_H
#define PATTERNS_MANAGER_H

#include "Worker.h"

class Order;

class Manager : public Worker {
public:
    void packOrder();
    void sendToDelivery();
    Client* addClient();
    Order* addOrder();
};


#endif //PATTERNS_MANAGER_H
