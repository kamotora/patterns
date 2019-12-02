//
// Created by artem on 26.11.2019.
//

#ifndef PATTERNS_SHAWARMA_H
#define PATTERNS_SHAWARMA_H

#include "ICloneable.h"
#include "CookingGood.h"

class Shawarma : public CookingGood, public ICloneable{
protected:
    int kcal;
public:
    Shawarma(string name, double saleCost, int kcal);
    Shawarma(string name, double saleCost, int kcal, vector<pair<Product *,int>> recipe);

    Product clone() override;
};


#endif //PATTERNS_SHAWARMA_H
