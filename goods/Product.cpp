//
// Created by root on 24.10.2019.
//

#include "Product.h"

const string &Product::getName() const {
    return name;
}

void Product::setName(const string &name) {
    Product::name = name;
}

double Product::getSaleCost() const {
    return saleCost;
}

void Product::setSaleCost(double cost) {
    this->saleCost = cost;
}

//TODO:Шо указывать?
double Product::getPrimeCost() const {
    return saleCost;
}

Product::Product(string name, double saleCost) : name(name), saleCost(saleCost){}

Product::Product(double saleCost) : saleCost(saleCost) {

}

vector<pair<Product *, int>> *Product::getChild() {
    return nullptr;
}

