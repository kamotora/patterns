//
// Created by artem on 26.11.2019.
//

#include "Shawarma.h"

Shawarma::Shawarma(string name, double saleCost, int kcal) : CookingGood(name,saleCost){
    this->kcal = kcal;
}

Product Shawarma::clone() {
    vector<pair<Product *,int>> newRecipe(recipe);
    return Shawarma(name,saleCost,kcal,newRecipe);
}

Shawarma::Shawarma(string name, double saleCost, int kcal, vector<pair<Product *, int>> recipe) : Shawarma(name,saleCost,kcal) {
    this->recipe = recipe;
}
