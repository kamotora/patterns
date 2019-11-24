//
// Created by artem on 11.11.2019.
//

#ifndef PATTERNS_INGREDIENT_H
#define PATTERNS_INGREDIENT_H


#include "Product.h"

class Ingredient : public Product {
protected:
    struct tm * shelfTime;
    int count;
    int cost;
public:
    double getPrimeCost() const override;

    vector<pair<Product *, int>> * getChild() override;
    Ingredient(string name, double cost);
    Ingredient(string name, double cost, int count);
};


#endif //PATTERNS_INGREDIENT_H
