#ifndef PATTERNS_MANAGER_H
#define PATTERNS_MANAGER_H

#include "Worker.h"

class Order;
class IDeliver;

class Manager : public Worker {
private:
    vector<IDeliver *> delivers;
public:
    Manager(string name,vector<IDeliver *> delivers);
    void packOrder();
    void sendToDelivery();
    Client* addClient();
};


#endif //PATTERNS_MANAGER_H
