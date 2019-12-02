//
// Created by artem on 27.11.2019.
//


#include "TypePizza.h"

TypePizza::TypePizza(std::string namePizza, std::string nameType, double coefForCost, std::string pathToImage) :
    namePizza(std::move(namePizza)), nameType(std::move(nameType)), coefForCost(coefForCost){
}

void TypePizza::readImage(std::string pathToImage) {
    std::ifstream input(pathToImage, std::ios_base::binary);
    std::vector<char> inbuf;
    // get length of file:
    input.seekg (0, input.end);
    int length = input.tellg();
    input.seekg (0, input.beg);
    input.read(image.data(),length);
}

const std::string &TypePizza::getNamePizza() const {
    return namePizza;
}

const std::string &TypePizza::getNameType() const {
    return nameType;
}

double TypePizza::getCoefForCost() const {
    return coefForCost;
}

const std::vector<char> &TypePizza::getImage() const {
    return image;
}

bool TypePizza::equals(std::string namePizza, std::string nameType, double coefForCost) {
    return this->namePizza == namePizza &&
           this->nameType == nameType &&
           this->coefForCost == coefForCost;
}

