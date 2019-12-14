//
// Created by artem on 12.12.2019.
//

#ifndef PATTERNS_SIZESHAWARMAFACTORY_H
#define PATTERNS_SIZESHAWARMAFACTORY_H


#include "SizeShawarma.h"

class SizeShawarmaFactory {
private:
    static std::vector<SizeShawarma *> sizes;
public:
    static std::vector<SizeShawarma *> &getAllTypes(){
        return sizes;
    }
    static SizeShawarma * getSizeShawarma(std::string nameSize, double coefForCost){
        if(!sizes.empty()){
            for(auto size: sizes){
                if(size->equals(nameSize,coefForCost))
                    return size;
            }
        }
        auto size = new SizeShawarma(nameSize,coefForCost);
        sizes.push_back(size);
        return size;
    }
    static SizeShawarma * getSizeShawarma(std::string nameSize){
        if(!sizes.empty()){
            for(auto size: sizes){
                if(size->getNameSize() == nameSize)
                    return size;
            }
        }
        return nullptr;
    }

};


#endif //PATTERNS_SIZESHAWARMAFACTORY_H
