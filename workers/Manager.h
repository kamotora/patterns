#ifndef PATTERNS_MANAGER_H
#define PATTERNS_MANAGER_H

#include "IVisitorElement.h"
#include "Worker.h"
#include "../client/Client.h"
#include "../client/IObserver.h"
#include "IVisitor.h"

class Order;
class IDeliver;

class Manager : public Worker, public IObserver, public IVisitorElement {
public:
    Manager() = default;
    Manager(string name);
    void packOrder();

    void sendToDelivery();

    void handleEvent(Status::TypeStatus typeStatusOrder, IOrder *order) override;

    void preparePacks();

    void accept(IVisitor *visitor) override;
};


#endif //PATTERNS_MANAGER_H
