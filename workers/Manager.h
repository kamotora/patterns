#ifndef PATTERNS_MANAGER_H
#define PATTERNS_MANAGER_H

#include "Worker.h"
#include "../client/Client.h"

class Order;
class IDeliver;

class Manager : public Worker {
public:
    Manager() = default;
    Manager(string name);
    void packOrder();

    void sendToDelivery();
    Client* addClient();

};


#endif //PATTERNS_MANAGER_H
