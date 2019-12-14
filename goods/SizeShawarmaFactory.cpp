//
// Created by artem on 12.12.2019.
//

#include "SizeShawarmaFactory.h"
std::vector<SizeShawarma *> SizeShawarmaFactory::sizes =  {
        new SizeShawarma("Маленькая", 125),
        new SizeShawarma("Большая", 175),
};