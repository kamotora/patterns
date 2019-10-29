#include <iostream>
#include "Manager.h"
#include "Drone.h"

//TODO: найти свободного, а не первого
void Manager::sendToDelivery() {
    TypeDelivery needType = curOrder->getTypeDelivery();
    for(IDeliver *pDeliver: delivers){
        if(pDeliver->getTypeDeliver() == needType){
            pDeliver->deliver(curOrder);
            break;
        }
    }
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
