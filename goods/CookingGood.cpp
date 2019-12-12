//
// Created by artem on 11.11.2019.
//

#include "CookingGood.h"

#include <utility>

double CookingGood::getSaleCost() const {
    return saleCost;
}



void CookingGood::setSaleCost(double saleCost) {
    this->saleCost = saleCost;
}

vector<Product *> * CookingGood::getChild() {
    /*
    vector<Product *> res(recipe.size());
    for(pair<Product *, int> pair : recipe)
        res.push_back(pair.first);
    */
    return &recipe;
}

void CookingGood::deleteIngredient(Product *ingred) {
    for(int i = 0; i < recipe.size(); i++)
        if(recipe[i] == ingred){
            recipe.erase(recipe.begin() + i);
            break;
        }
}

CookingGood::CookingGood(string name, double saleCost) {
    setName(name);
    this->saleCost = saleCost;
}

CookingGood::CookingGood(string name, double saleCost, vector<Product *> recipe) : CookingGood(std::move(name),saleCost){
    this->recipe = std::move(recipe);
}

CookingGood::CookingGood(double saleCost) : Product(saleCost) {
}

void CookingGood::addIngredient(Product *ingred) {
    recipe.push_back(ingred);
}
