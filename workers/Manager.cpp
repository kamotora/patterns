#include <iostream>
#include "Manager.h"
#include "Drone.h"

void Manager::sendToDelivery() {
    IDeliver *deliver = curOrder->getDeliver();
    deliver->deliver(curOrder);
}

Manager::Manager(string name, vector<IDeliver *> delivers) : Worker(name) {
    this->delivers = std::move(delivers);
}

void Manager::packOrder() {
    std::cout << "Заказ №" << curOrder->getNumber() << " упаковывается" << endl;
}

Client *Manager::addClient() {
    return nullptr;
}
