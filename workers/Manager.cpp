#include <iostream>
#include "Manager.h"
#include "Drone.h"

void Manager::sendToDelivery() {
    IDeliver *deliver = curOrder->getDeliver();
    deliver->deliver(curOrder);
}

Manager::Manager(string name) : Worker(name) {}

void Manager::packOrder() {
    std::cout << "Заказ №" << curOrder->getNumber() << " упаковывается" << endl;
}

void Manager::handleEvent(Status::TypeStatus typeStatusOrder, IOrder *order) {
    if(typeStatusOrder == Status::TypeStatus::COOKED){
        this->curOrder = order;
        packOrder();
        order->setStatus(Status::TypeStatus::IN_DELIVERY_QUEUE);
        sendToDelivery();
    }
}

void Manager::preparePacks() {
    std::cout << "Менеджер " << name << " готовит упаковки к использованию" << std::endl;
}

void Manager::accept(IVisitor *visitor) {
    visitor->prepare(this);
}
