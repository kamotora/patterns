#include <iostream>
#include <thread>
#include <utility>
#include "Cook.h"

Cook::Cook(string name, Cook::TypeCookingProduct typeCookingProduct) : Worker(std::move(name)) {
    this->typeCookingProduct = typeCookingProduct;
    this->state = new FreeCookState(this);
}

void Cook::cook() {
    if(state){
        state->work();
    } else
        cout<< "Ошибка. У повара нет состояния" << endl;
}

void Cook::setState(IState *state) {
    delete this->state;
    this->state = state;
    cook();
}

Cook::TypeCookingProduct Cook::getTypeCookingProduct() const {
    return typeCookingProduct;
}

void Cook::handleEvent(Status::TypeStatus typeStatusOrder, IOrder *order) {
    if(typeStatusOrder == Status::TypeStatus::PAID){
        order->setStatus(Status::TypeStatus::IN_COOKING_QUEUE);
        addOrder(order);
        cook();
    }
}

void Cook::prepareKitchen() {
    std::cout << "Повар " << name << "  всё подготовил на кухне" << std::endl;
}

void Cook::accept(IVisitor *visitor) {
    visitor->prepare(this);
}
