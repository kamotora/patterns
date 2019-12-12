//
// Created by artem on 08.12.2019.
//

#ifndef PATTERNS_BUBBLESORT_H
#define PATTERNS_BUBBLESORT_H


#include "IStrategy.h"

class BubbleSort : public IStrategy {
public:
    void sort(vector<Product *> *composite, bool (*comparator)(Product *, Product *) = standartComparator) override;
};


#endif //PATTERNS_BUBBLESORT_H
