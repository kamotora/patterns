//
// Created by root on 24.10.2019.
//

#include "Good.h"

const string &Good::getName() const {
    return name;
}

void Good::setName(const string &name) {
    Good::name = name;
}

double Good::getCost() const {
    return cost;
}

void Good::setCost(double cost) {
    Good::cost = cost;
}
