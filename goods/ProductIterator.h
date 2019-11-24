//
// Created by artem on 11.11.2019.
//

#ifndef PATTERNS_PRODUCTITERATOR_H
#define PATTERNS_PRODUCTITERATOR_H


#include "Iterator.h"
#include "Product.h"
#include <vector>
#include <stack>

using namespace std;
class ProductIterator : public Iterator {
private:
    vector<Product *> *composite;
    int curPos;
    int size;
    std::stack<pair<Product *, int>> myStack;
    pair<Product *, int> curPair;
public:
    ProductIterator(vector<Product *> *composite);
    Product * getNext() override;

    bool hasNext() override;

    Product *Delete(Product *product) override;

    double getPrimeCostCur();
};


#endif //PATTERNS_PRODUCTITERATOR_H
