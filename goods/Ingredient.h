//
// Created by artem on 11.11.2019.
//

#ifndef PATTERNS_INGREDIENT_H
#define PATTERNS_INGREDIENT_H


#include "Product.h"
#include <utility>
#include <sstream>

class Ingredient : public Product {
protected:
    struct tm * shelfTime;
    int count;
    double cost;
public:
    double getPrimeCost() const override;

    vector<Product *> * getChild() override;
    Ingredient(string name, double cost);
    Ingredient(string name, double cost, int count);

    string toString() override;

    double getSaleCost() const override;
};


#endif //PATTERNS_INGREDIENT_H
