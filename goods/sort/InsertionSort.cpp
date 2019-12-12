//
// Created by artem on 08.12.2019.
//

#include "InsertionSort.h"

void InsertionSort::sort(vector<Product *> *composite, bool (*comparator)(Product *, Product *)) {
    int size = composite->size();
    int i = 0;
    vector<bool> isSorted (size, false);
    for(int j = 1;j<size;j++){
        Product* key = composite->at(j);
        i = j-1;
        while(i>=0 && comparator(key,composite->at(i))){
            if(!composite->at(j)->getChild()->empty() && !isSorted[j]){
                sort(composite->at(j)->getChild(), comparator);
                isSorted[j] = true;
            }
            if(!composite->at(i)->getChild()->empty() && !isSorted[i]){
                sort(composite->at(i)->getChild(), comparator);
                isSorted[i] = true;
            }
            Product * tmp = composite->at(j);
            composite->at(j) = composite->at(j-1);
            composite->at(j-1) = tmp;
        }
    }



}
