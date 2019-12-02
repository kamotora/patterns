//
// Created by artem on 30.11.2019.
//

#ifndef PATTERNS_ICLONEABLE_H
#define PATTERNS_ICLONEABLE_H

class Product;

class ICloneable {
public:
    virtual Product clone() = 0;
};


#endif //PATTERNS_ICLONEABLE_H
