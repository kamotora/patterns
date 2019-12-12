//
// Created by root on 24.10.2019.
//

#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include "Drone.h"

void Drone::goToCharge() {
    std::cout << "Дрон № "<< num << " заряжается" << std::endl;
}

void Drone::deliver(IOrder *order) {
    //ordersQueue.push_back(order);
    curOrder = order;
    order->setStatus(Status::TypeStatus::DELIVER);
    std::cout << "Заказ №" << order->getNumber() << " добавлен на доставку дроном №" << num << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    std::cout << "Заказ №" << order->getNumber() << " доставлен дроном №" << num << endl;
    order->setStatus(Status::TypeStatus::COMPLETED);
    curOrder = nullptr;
}

Drone::Drone(int num) {
    this->num = num;
}

int Drone::getNum() const {
    return num;
}

int Drone::getTimeToDead() const {
    return timeToDead;
}

int Drone::getChargeLevel() const {
    return chargeLevel;
}

IOrder *Drone::getCurOrder() {
    return curOrder;
}

void Drone::accept(IVisitor *visitor) {
    visitor->prepare(this);
}

