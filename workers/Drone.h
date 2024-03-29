//
// Created by root on 24.10.2019.
//

#ifndef PATTERNS_DRONE_H
#define PATTERNS_DRONE_H
#include "IDeliver.h"
#include "IVisitorElement.h"
#include "IVisitor.h"

class Drone : public IDeliver, public IVisitorElement {
private:
    int num;
    IOrder * curOrder = nullptr;
    int timeToDead;
    int chargeLevel;
    vector<IOrder *> ordersQueue;
public:
    Drone(int num);
    void deliver(IOrder *order) override;
    void goToCharge();

    int getNum() const;

    int getTimeToDead() const;

    int getChargeLevel() const;

    IOrder *getCurOrder() override;

    void accept(IVisitor *visitor) override;
};


#endif //PATTERNS_DRONE_H
