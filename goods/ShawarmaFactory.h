//
// Created by artem on 12.12.2019.
//

#ifndef PATTERNS_SHAWARMAFACTORY_H
#define PATTERNS_SHAWARMAFACTORY_H


#include "Shawarma.h"

class ShawarmaFactory {
private:
    static std::vector<Shawarma *> shawarmas;
public:
    static Shawarma * getTypePizza(string name, double saleCost, SizeShawarma *size){
        if(!shawarmas.empty()){
            for(auto product: shawarmas){
                if(product->equals(name, saleCost, size))
                    return product;
            }
        }
        auto product = new Shawarma(name,saleCost,size);
        shawarmas.push_back(product);
        return product;
    }
    static std::vector<Shawarma *> &getAll(){
        return shawarmas;
    }
};


#endif //PATTERNS_SHAWARMAFACTORY_H
