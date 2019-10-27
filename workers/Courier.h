//
// Created by root on 24.10.2019.
//

#ifndef PATTERNS_COURIER_H
#define PATTERNS_COURIER_H


#include "IDeliver.h"
#include "Worker.h"

class Courier : Worker, IDeliver{
public:
    void deliver();
    void getPaid();

};


#endif //PATTERNS_COURIER_H
