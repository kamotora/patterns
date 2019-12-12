//
// Created by artem on 11.11.2019.
//

#ifndef PATTERNS_COOKINGGOOD_H
#define PATTERNS_COOKINGGOOD_H


#include "Product.h"
#include <vector>
class CookingGood : public Product{
protected:
    vector<Product *> recipe;
    double saleCost;
public:
    void addIngredient(Product * ingred);
    void deleteIngredient(Product * ingred);
    vector<Product *> * getChild() override ;

    double getSaleCost() const override;

    void setSaleCost(double saleCost) override;
    CookingGood(string name, double saleCost);
    CookingGood(double saleCost);
    CookingGood(string name, double saleCost, vector<Product *> recipe);



};


#endif //PATTERNS_COOKINGGOOD_H
