//
// Created by artem on 11.11.2019.
//

#include "ProductIterator.h"

Product * ProductIterator::getNext() {
    Product * cur = nullptr;
    if(!myStack.empty()){
        curProduct = myStack.top();
        myStack.pop();
        cur = curProduct;
    }
    else if(hasNext()){
        Product * product = composite->at(curPos++);
        vector<Product *> *childs = product->getChild();
        if(!childs->empty()) {
            for (Product * prod : *childs)
                myStack.push(prod);
                //myStack.push(pair);
            curProduct = myStack.top();
            myStack.pop();
            cur = curProduct;
        } else{
            curProduct = product;
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
    return curProduct->getPrimeCost();
}

void ProductIterator::sort(bool (*comparator)(Product *, Product *)) {
    if(typeSort == nullptr)
        Logger::getLogger()->message("Ошибка! Не выбран тип сортировки", Logger::ERR);
    else
        typeSort->sort(composite,comparator);
}

void ProductIterator::setTypeSort(IStrategy *typeSort) {
    this->typeSort = typeSort;
}

