//
// Created by artem on 12.12.2019.
//

#ifndef PATTERNS_SIZESHAWARMA_H
#define PATTERNS_SIZESHAWARMA_H


#include <string>
#include <vector>
#include <fstream>

class SizeShawarma {
private:
    std::string nameSize;
    double coefForCost;
    std::vector<char> image;
public:
    SizeShawarma(std::string nameSize, double coefForCost, std::string pathToImage= "umolch");
    void readImage(std::string pathToImage);

    const std::string &getNameSize() const;

    double getCoefForCost() const;

    const std::vector<char> &getImage() const;

    bool equals(std::string nameSize, double coefForCost);
};


#endif //PATTERNS_SIZESHAWARMA_H
