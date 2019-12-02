//
// Created by artem on 27.11.2019.
//

#ifndef PATTERNS_TYPEPIZZA_H
#define PATTERNS_TYPEPIZZA_H


#include <iostream>
#include <vector>
#include <fstream>

class TypePizza {
private:
    std::string namePizza;
    std::string nameType;
    double coefForCost;
    std::vector<char> image;
public:
    TypePizza(std::string namePizza, std::string nameType, double coefForCost, std::string pathToImage= "umolch");
    void readImage(std::string pathToImage);

    const std::string &getNamePizza() const;

    const std::string &getNameType() const;

    double getCoefForCost() const;

    const std::vector<char> &getImage() const;

    bool equals(std::string namePizza, std::string nameType, double coefForCost);
};


#endif //PATTERNS_TYPEPIZZA_H
