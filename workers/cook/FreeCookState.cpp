//
// Created by artem on 30.11.2019.
//
#include "FreeCookState.h"

void FreeCookState::work() {
    {
        auto order = cook->getNextOrder();
        //Если нет заказов, то состояние свободное
        if(order != nullptr){
            cook->setCurOrder(order);
            cook->setState(new BusyCookState(cook));
        }
    }
}

FreeCookState::FreeCookState(Cook *cook)  : cook(cook) {}
