//
// Created by artem on 08.12.2019.
//

#include "BubbleSort.h"

void BubbleSort::sort(vector<Product *> *composite, bool (*comparator)(Product *, Product *)) {
    int size = composite->size();
    vector<bool> isSorted (size, false);
    for(int i = 0 ; i < size ; i++){
        for(int j = (size-1) ; j >= (i+1) ; j--){
            if(!composite->at(j)->getChild()->empty() && !isSorted[j]){
                sort(composite->at(j)->getChild(), comparator);
                isSorted[j] = true;
            }
            if(!composite->at(j - 1)->getChild()->empty() && !isSorted[j - 1]){
                sort(composite->at(j - 1)->getChild(), comparator);
                isSorted[j - 1] = true;
            }
            if(comparator(composite->at(j),composite->at(j-1))){
                Product * tmp = composite->at(j);
                composite->at(j) = composite->at(j-1);
                composite->at(j-1) = tmp;
            }
        }
    }
}


