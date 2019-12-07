//
// Created by artem on 30.11.2019.
//

#include "BusyCookState.h"

void BusyCookState::work() {
    auto curOrder = cook->getCurOrder();
    //Если нет заказа или какой-то не тот
    if(curOrder == nullptr || curOrder->getStatus() != Status::TypeStatus::IN_COOKING_QUEUE){
        return;
    }
    curOrder->setStatus(Status::TypeStatus::COOK);
    cout << "Заказ №" << curOrder->getNumber() << " готовится" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 3 * 1000));
    curOrder->setStatus(Status::TypeStatus::COOKED);
    cook->setCurOrder(nullptr);
    cook->setState(new FreeCookState(cook));

}

BusyCookState::BusyCookState(Cook *cook)  : cook(cook) {
}
