//
// Created by artem on 27.11.2019.
//

#include "TypePizzaFactory.h"
std::vector<TypePizza *> TypePizzaFactory::pizzaTypes =  {
    new TypePizza("Пицца 1", "Маленькая", 300),
    new TypePizza("Пицца 1", "Большая", 450),
    new TypePizza("Пицца 2", "Маленькая", 350),
    new TypePizza("Пицца 2", "Большая", 475),
    new TypePizza("Пицца 3", "Маленькая", 250),
    new TypePizza("Пицца 3", "Большая", 425)
};