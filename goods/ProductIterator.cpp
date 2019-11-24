//
// Created by artem on 11.11.2019.
//

#include "ProductIterator.h"

Product * ProductIterator::getNext() {
    Product * cur = nullptr;
    if(!myStack.empty()){
        curPair = myStack.top();
        myStack.pop();
        cur = curPair.first;
    }
    else if(hasNext()){
        Product * product = composite->at(curPos++);
        vector<pair<Product *,int>> *childs = product->getChild();
        if(childs != nullptr) {
            for (pair<Product *, int> pair : *childs)
                myStack.push(pair);
                //myStack.push(pair);
            curPair = myStack.top();
            myStack.pop();
            cur = curPair.first;
        } else{
            curPair = make_pair(product,1);
            cur = product;
        }

    }
    return cur;
}


bool ProductIterator::hasNext() {
    return size > curPos;
}

Product *ProductIterator::Delete(Product *product) {
    for(int i = 0; i < size; i++)
        if(composite->at(i) == product){
            composite->erase(composite->begin() + i);
            return product;
        }
    return nullptr;

}

ProductIterator::ProductIterator(vector<Product *> *composite) {
    this->composite = composite;
    curPos = 0;
    size = this->composite->size();
}

double ProductIterator::getPrimeCostCur() {
    return curPair.first->getPrimeCost()*curPair.second;
}

