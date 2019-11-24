//
// Created by artem on 11.11.2019.
//

#ifndef PATTERNS_COOKINGGOOD_H
#define PATTERNS_COOKINGGOOD_H


#include "Product.h"
#include <vector>
class CookingGood : public Product{
protected:
    vector<pair<Product *,int>> recipe;
    double saleCost;
public:
    void addIngredient(Product * ingred);
    void deleteIngredient(Product * ingred);
    vector<pair<Product *, int>> * getChild() override ;

    double getSaleCost() const override;

    void setSaleCost(double saleCost) override;

    void addIngredient(Product *ingred, int count);
    CookingGood(string name, double saleCost);
    CookingGood(string name, double saleCost, vector<pair<Product *,int>> recipe);



};


#endif //PATTERNS_COOKINGGOOD_H
