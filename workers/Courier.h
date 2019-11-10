#ifndef PATTERNS_COURIER_H
#define PATTERNS_COURIER_H


#include "IDeliver.h"
#include "Worker.h"

class Courier : public Worker, public IDeliver{
private:
    IOrder *curOrder = nullptr;
public:
    Courier(string name);
    void getPaid();
    IOrder *getCurOrder();
    void deliver(IOrder *order) override ;
};


#endif //PATTERNS_COURIER_H
