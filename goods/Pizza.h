//
// Created by artem on 26.11.2019.
//

#ifndef PATTERNS_PIZZA_H
#define PATTERNS_PIZZA_H


#include "CookingGood.h"
#include "TypePizza.h"

class Pizza : public CookingGood {
protected:
    TypePizza *typePizza;
public:
    Pizza(double saleCost);
    Pizza(double saleCost, TypePizza *type);
    void setTypePizza(TypePizza *typePizza);
    const std::string getNamePizza();
    const std::string getNameTypePizza();
    const std::vector<char> & getImage();
};


#endif //PATTERNS_PIZZA_H
