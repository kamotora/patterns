//
// Created by artem on 26.11.2019.
//

#include "Pizza.h"

Pizza::Pizza(double saleCost, TypePizza *type) : CookingGood(saleCost) {
    setTypePizza(typePizza);
}

void Pizza::setTypePizza(TypePizza *typePizza) {
    Pizza::typePizza = typePizza;
}

Pizza::Pizza(double saleCost) : CookingGood(saleCost) {
}

const std::vector<char> &Pizza::getImage() {
    return typePizza->getImage();
}

const std::string Pizza::getNamePizza() {
    return typePizza->getNamePizza();
}

const std::string Pizza::getNameTypePizza() {
    return typePizza->getNameType();
}
