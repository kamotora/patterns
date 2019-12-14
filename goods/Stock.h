//
// Created by artem on 12.12.2019.
//

#ifndef PATTERNS_STOCK_H
#define PATTERNS_STOCK_H


#include "Ingredient.h"

class Stock {
private:
    static std::vector<Ingredient *> igredients;
public:
    static std::vector<Ingredient *> getIngerdients(){
        return Stock::igredients;
    }

    static void addIngredient(Ingredient *ingredient){
        igredients.push_back(ingredient);
    }
};


#endif //PATTERNS_STOCK_H
