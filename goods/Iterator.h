//
// Created by artem on 11.11.2019.
//

#ifndef PATTERNS_ITERATOR_H
#define PATTERNS_ITERATOR_H

class Product;

class Iterator {
public:
    virtual Product * getNext() = 0;
    virtual bool hasNext() = 0;
    virtual Product * Delete(Product *product) = 0;
};


#endif //PATTERNS_ITERATOR_H
