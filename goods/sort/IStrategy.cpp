//
// Created by artem on 08.12.2019.
//

#include "IStrategy.h"

bool IStrategy::standartComparator(Product *a, Product *b) {
    return a->getPrimeCost() < b->getPrimeCost();
}
