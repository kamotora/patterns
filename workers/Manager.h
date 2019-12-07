#ifndef PATTERNS_MANAGER_H
#define PATTERNS_MANAGER_H

#include "Worker.h"
#include "../client/Client.h"
#include "../client/IObserver.h"
class Order;
class IDeliver;

class Manager : public Worker, public IObserver {
public:
    Manager() = default;
    Manager(string name);
    void packOrder();

    void sendToDelivery();
    Client* addClient();

    void handleEvent(Status::TypeStatus typeStatusOrder, IOrder *order) override;
};


#endif //PATTERNS_MANAGER_H
