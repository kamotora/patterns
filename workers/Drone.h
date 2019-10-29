//
// Created by root on 24.10.2019.
//

#ifndef PATTERNS_DRONE_H
#define PATTERNS_DRONE_H


#include "IDeliver.h"
#include "../client/Order.h"

class Drone : public IDeliver {
private:
    int num;
    Order * curOrder;
    int timeToDead;
    int chargeLevel;
    TypeDelivery typeDeliver;
    vector<IOrder *> ordersQueue;
public:
    Drone(int num);
    void deliver(IOrder *order);
    void goToCharge();

    int getNum() const;

    Order *getCurOrder() const;

    int getTimeToDead() const;

    int getChargeLevel() const;

    TypeDelivery getTypeDeliver() override ;
};


#endif //PATTERNS_DRONE_H
