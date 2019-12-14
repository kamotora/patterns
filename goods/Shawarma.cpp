//
// Created by artem on 26.11.2019.
//

#include "Shawarma.h"

#include <utility>
#include <sstream>

Shawarma::Shawarma(string name, double saleCost, SizeShawarma *size) : CookingGood(std::move(name),saleCost){
    this->sizeShawarma = size;
}

Product* Shawarma::clone() {
    vector<Product *> newRecipe(recipe);
    return new Shawarma(name,saleCost,sizeShawarma,newRecipe);
}

Shawarma::Shawarma(string name, double saleCost, SizeShawarma *size, vector<Product *> recipe) : Shawarma(name,saleCost,size) {
    this->recipe = recipe;
}

string Shawarma::toString() {
    std::stringstream stream;
    stream << "Шаурма " << name << "Размер: " << sizeShawarma->getNameSize();
    if(!recipe.empty()){
        stream << " Дополнительно : ";
        for(auto ingred : recipe)
            stream << ingred->getName() << ", ";
    }
    stream << std::endl;
    return stream.str();
}

double Shawarma::getSaleCost() const {
    if(sizeShawarma == nullptr)
        return 0;
    double res = saleCost + sizeShawarma->getCoefForCost();
    for(auto ingr : recipe)
        res += ingr->getSaleCost();
    return res;
}

bool Shawarma::equals(string name, double saleCost, SizeShawarma *size) {
    return this->name == name && this->saleCost == saleCost && this->sizeShawarma->equals(size->getNameSize(), size->getCoefForCost());
}

void Shawarma::setSizeShawarma(SizeShawarma *sizeShawarma) {
    this->sizeShawarma = sizeShawarma;
}

