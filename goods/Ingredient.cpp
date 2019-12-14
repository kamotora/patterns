//
// Created by artem on 11.11.2019.
//

#include "Ingredient.h"


double Ingredient::getPrimeCost() const {
    return cost;
}

vector<Product *> *Ingredient::getChild() {
    return nullptr;
}

Ingredient::Ingredient(string name, double cost){
    setName(name);
    this->cost = cost;
}

Ingredient::Ingredient(string name, double cost, int count) : Ingredient(std::move(name),cost){
    this->count = count;
}

string Ingredient::toString() {
    std::stringstream stream;
    stream << name << " " << cost << " руб." << std::endl;
    return stream.str();
}

double Ingredient::getSaleCost() const {
    return cost;
}
