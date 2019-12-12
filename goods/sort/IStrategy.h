//
// Created by artem on 08.12.2019.
//

#ifndef PATTERNS_ISTRATEGY_H
#define PATTERNS_ISTRATEGY_H


#include "../Product.h"

class IStrategy {
public:
    static bool standartComparator(Product *a, Product *b);
    virtual void sort(vector<Product *> *composite,bool (*comparator)(Product*, Product*) = standartComparator) = 0;
};


#endif //PATTERNS_ISTRATEGY_H
