#include <iostream>
#include <utility>
#include <unistd.h>
#include <chrono>
#include <thread>
#include "Courier.h"

void Courier::deliver(IOrder *order) {
    curOrder = order;
    order->setStatus(Status::TypeStatus::DELIVER);
    std::cout << "Заказ №" << order->getNumber() << " добавлен на доставку курьером " << name << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(7000));
    std::cout << "Заказ №" << order->getNumber() << " доставлен курьером " << name << endl;
    order->setStatus(Status::TypeStatus::COMPLETED);
    curOrder = nullptr;
}

void Courier::getPaid() {

}

Courier::Courier(string name) : Worker(std::move(name)) {
}

IOrder *Courier::getCurOrder(){
    return curOrder;
}

