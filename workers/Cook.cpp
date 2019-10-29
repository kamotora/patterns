#include <iostream>
#include <thread>
#include "Cook.h"


Cook::Cook(string name, Cook::TypeCookingProduct typeCookingProduct) : Worker(name) {
    this->typeCookingProduct = typeCookingProduct;
}

void Cook::cook() {
    if(curOrder == nullptr || curOrder->getStatus() != Status::TypeStatus::IN_COOKING_QUEUE){
        return;
    }
    curOrder->setStatus(Status::TypeStatus::COOK);
    cout << "Заказ №" << curOrder->getNumber() << " готовится" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 7 * 1000));
    curOrder->setStatus(Status::TypeStatus::COOKED);
}
