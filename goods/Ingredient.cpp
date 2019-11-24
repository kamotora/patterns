//
// Created by artem on 11.11.2019.
//

#include "Ingredient.h"

#include <utility>

double Ingredient::getPrimeCost() const {
    return cost;
}

vector<pair<Product *, int>> *Ingredient::getChild() {
    return nullptr;
}

Ingredient::Ingredient(string name, double cost){
    setName(name);
    this->cost = cost;
}

Ingredient::Ingredient(string name, double cost, int count) : Ingredient(std::move(name),cost){
    this->count = count;
}
