//
// Created by root on 24.10.2019.
//

#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include "Drone.h"

void Drone::goToCharge() {

}

void Drone::deliver(IOrder *order) {
    //ordersQueue.push_back(order);
    order->setStatus(Status::TypeStatus::DELIVER);
    std::cout << "Заказ №" << order->getNumber() << " добавлен на доставку дроном №" << num << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    std::cout << "Заказ №" << order->getNumber() << " доставлен дроном №" << num << endl;
    order->setStatus(Status::TypeStatus::COMPLETED);
}

Drone::Drone(int num) {
    this->num = num;
    typeDeliver = TypeDelivery::DRONE;
}

int Drone::getNum() const {
    return num;
}

Order *Drone::getCurOrder() const {
    return curOrder;
}

int Drone::getTimeToDead() const {
    return timeToDead;
}

int Drone::getChargeLevel() const {
    return chargeLevel;
}

TypeDelivery Drone::getTypeDeliver(){
    return typeDeliver;
}
