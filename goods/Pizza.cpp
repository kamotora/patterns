//
// Created by artem on 26.11.2019.
//

#include <sstream>
#include "Pizza.h"

Pizza::Pizza(double saleCost, TypePizza *type) : CookingGood(saleCost) {
    setTypePizza(type);
}

void Pizza::setTypePizza(TypePizza *typePizza) {
    this->typePizza = typePizza;
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

double Pizza::getSaleCost() const {
    double res = saleCost+typePizza->getCoefForCost();
    for(auto ingr : recipe)
        res += ingr->getSaleCost();
    return res;
}

string Pizza::toString() {
    std::stringstream stream;
    stream << "Пицца " << typePizza->getNamePizza() << " Тип: " << typePizza->getNameType();
    if(!recipe.empty()){
        stream << " Дополнительно : ";
        for(auto ingred : recipe)
            stream << ingred->getName() << ", ";
    }
    stream << std::endl;
    return stream.str();
}

Product *Pizza::clone() {
    return new Pizza(saleCost,typePizza);
}
