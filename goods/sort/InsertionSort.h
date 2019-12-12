//
// Created by artem on 08.12.2019.
//

#ifndef PATTERNS_INSERTIONSORT_H
#define PATTERNS_INSERTIONSORT_H


#include "IStrategy.h"

class InsertionSort : public IStrategy{
public:
    void sort(vector<Product *> *composite, bool (*comparator)(Product *, Product *)) override;
};


#endif //PATTERNS_INSERTIONSORT_H
