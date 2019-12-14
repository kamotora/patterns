//
// Created by artem on 26.11.2019.
//

#ifndef PATTERNS_PIZZA_H
#define PATTERNS_PIZZA_H


#include "CookingGood.h"
#include "TypePizza.h"
#include "ICloneable.h"

class Pizza : public CookingGood, public ICloneable {
protected:
    TypePizza *typePizza;
public:
    Pizza(double saleCost);
    Pizza(double saleCost, TypePizza *type);
    void setTypePizza(TypePizza *typePizza);

    double getSaleCost() const override;

    const std::string getNamePizza();
    const std::string getNameTypePizza();
    const std::vector<char> & getImage();

    string toString() override;

    Product *clone() override;
};


#endif //PATTERNS_PIZZA_H
