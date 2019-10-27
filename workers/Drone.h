//
// Created by root on 24.10.2019.
//

#ifndef PATTERNS_DRONE_H
#define PATTERNS_DRONE_H


#include "IDeliver.h"

class Drone : public IDeliver {
public:
    void deliver();
    void goToCharge();
};


#endif //PATTERNS_DRONE_H
