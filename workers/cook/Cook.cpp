#include <iostream>
#include <thread>
#include "Cook.h"

Cook::Cook(string name, Cook::TypeCookingProduct typeCookingProduct) : Worker(name) {
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
}

Cook::TypeCookingProduct Cook::getTypeCookingProduct() const {
    return typeCookingProduct;
}
