//
// Created by root on 24.10.2019.
//

#ifndef PATTERNS_COOK_H
#define PATTERNS_COOK_H


#include "Worker.h"

class Cook : public Worker {
public:
    enum TypeCookingProduct{
        SHAWARMA,
        PIZZA
    };
private:
    TypeCookingProduct typeCookingProduct;
public:
    Cook(string name, TypeCookingProduct typeCookingProduct);
    void cook();

};


#endif //PATTERNS_COOK_H
