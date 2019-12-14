//
// Created by artem on 26.11.2019.
//

#ifndef PATTERNS_SHAWARMA_H
#define PATTERNS_SHAWARMA_H

#include "ICloneable.h"
#include "CookingGood.h"
#include "SizeShawarma.h"

class Shawarma : public CookingGood, public ICloneable{
protected:
    SizeShawarma *sizeShawarma;
public:
    Shawarma(string name, double saleCost, SizeShawarma *size);
    Shawarma(string name, double saleCost, SizeShawarma *size, vector<Product *> recipe);

    Product* clone() override;

    string toString() override;

    double getSaleCost() const override;

    void setSizeShawarma(SizeShawarma *sizeShawarma);

    bool equals(string name, double saleCost, SizeShawarma *size);
};


#endif //PATTERNS_SHAWARMA_H
