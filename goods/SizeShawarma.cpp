//
// Created by artem on 12.12.2019.
//

#include "SizeShawarma.h"

SizeShawarma::SizeShawarma(std::string nameSize, double coefForCost, std::string pathToImage) : nameSize(nameSize), coefForCost(coefForCost){
    //readImage(pathToImage);
}

const std::string &SizeShawarma::getNameSize() const {
    return this->nameSize;
}

double SizeShawarma::getCoefForCost() const {
    return coefForCost;
}

const std::vector<char> &SizeShawarma::getImage() const {
    return image;
}

void SizeShawarma::readImage(std::string pathToImage) {
        std::ifstream input(pathToImage, std::ios_base::binary);
        std::vector<char> inbuf;
        // get length of file:
        input.seekg (0, input.end);
        int length = input.tellg();
        input.seekg (0, input.beg);
        input.read(image.data(),length);
}

bool SizeShawarma::equals(std::string nameSize, double coefForCost) {
    return nameSize == this->nameSize && coefForCost == this->coefForCost;
}
