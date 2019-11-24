//
// Created by artem on 20.11.2019.
//

#ifndef PATTERNS_ICALLER_H
#define PATTERNS_ICALLER_H

class IOrder;
class ICaller {
public:
    virtual void call(IOrder * order) = 0;
};


#endif //PATTERNS_ICALLER_H
