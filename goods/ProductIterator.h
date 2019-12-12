//
// Created by artem on 11.11.2019.
//

#ifndef PATTERNS_PRODUCTITERATOR_H
#define PATTERNS_PRODUCTITERATOR_H


#include "Iterator.h"
#include "Product.h"
#include "sort/IStrategy.h"
#include <vector>
#include "../log/Logger.h"
#include <stack>

using namespace std;


class ProductIterator : public Iterator {
private:
    vector<Product *> *composite;
    int curPos;
    Product *curProduct;
    int size;
    std::stack<Product *> myStack;
    IStrategy *typeSort;
public:
    ProductIterator(vector<Product *> *composite);
    Product * getNext() override;

    bool hasNext() override;

    Product *Delete(Product *product) override;

    double getPrimeCostCur();
    void setTypeSort(IStrategy *typeSort);
    void sort(bool (*comparator)(Product*, Product*));
};


#endif //PATTERNS_PRODUCTITERATOR_H
