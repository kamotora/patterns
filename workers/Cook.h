//
// Created by root on 24.10.2019.
//

#ifndef PATTERNS_COOK_H
#define PATTERNS_COOK_H


#include "Worker.h"

class Cook : Worker {
private:
    string typeCookingProduct;
public:
    Cook();
    void cook();

};


#endif //PATTERNS_COOK_H
