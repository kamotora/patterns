//
// Created by root on 24.10.2019.
//

#ifndef PATTERNS_COOK_H
#define PATTERNS_COOK_H


#include "../Worker.h"
#include "IState.h"
#include "FreeCookState.h"


class Cook : public Worker {
public:
    enum TypeCookingProduct{
        SHAWARMA,
        PIZZA
    };
private:
    TypeCookingProduct typeCookingProduct;
    IState *state;
public:
    Cook(string name, TypeCookingProduct typeCookingProduct);
    void cook();
    void setState(IState *state);

    TypeCookingProduct getTypeCookingProduct() const;
};


#endif //PATTERNS_COOK_H
