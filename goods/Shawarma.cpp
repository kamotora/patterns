//
// Created by artem on 26.11.2019.
//

#include "Shawarma.h"

#include <utility>

Shawarma::Shawarma(string name, double saleCost, int kcal) : CookingGood(std::move(name),saleCost){
    this->kcal = kcal;
}

Product Shawarma::clone() {
    vector<Product *> newRecipe(recipe);
    return Shawarma(name,saleCost,kcal,newRecipe);
}

Shawarma::Shawarma(string name, double saleCost, int kcal, vector<Product *> recipe) : Shawarma(name,saleCost,kcal) {
    this->recipe = recipe;
}
