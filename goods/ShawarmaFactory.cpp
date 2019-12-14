//
// Created by artem on 12.12.2019.
//

#include "ShawarmaFactory.h"
std::vector<Shawarma *> ShawarmaFactory::shawarmas =  {
        new Shawarma("Шаурма 1", 0, nullptr),
        new Shawarma("Шаурма 2", 0, nullptr),
        new Shawarma("Шаурма 3", 0, nullptr),
};