//
// Created by artem on 27.11.2019.
//

#ifndef PATTERNS_TYPEPIZZAFACTORY_H
#define PATTERNS_TYPEPIZZAFACTORY_H


#include "TypePizza.h"

class TypePizzaFactory {
private:
    static std::vector<TypePizza *> pizzaTypes;
public:
    static TypePizza * getTypePizza(std::string namePizza, std::string nameType, double coefForCost){
        if(!pizzaTypes.empty()){
            for(auto typePizza: pizzaTypes){
                if(typePizza->equals(namePizza,nameType,coefForCost))
                    return typePizza;
            }
        }
        auto type = new TypePizza(namePizza,nameType,coefForCost);
        pizzaTypes.push_back(type);
        return type;
    }
};


#endif //PATTERNS_TYPEPIZZAFACTORY_H
