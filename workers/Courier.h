#ifndef PATTERNS_COURIER_H
#define PATTERNS_COURIER_H


#include "IDeliver.h"
#include "Worker.h"
#include "IVisitorElement.h"
#include "IVisitor.h"

class Courier : public Worker, public IDeliver, public IVisitorElement{
private:
    IOrder *curOrder = nullptr;
public:
    Courier(string name);
    void getPaid();
    IOrder *getCurOrder();
    void deliver(IOrder *order) override ;
    void prepareCar();

    void accept(IVisitor *visitor);
};


#endif //PATTERNS_COURIER_H
