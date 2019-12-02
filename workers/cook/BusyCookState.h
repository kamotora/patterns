//
// Created by artem on 30.11.2019.
//

#ifndef PATTERNS_BUSYCOOKSTATE_H
#define PATTERNS_BUSYCOOKSTATE_H


#include <iostream>
#include <chrono>
#include <thread>
#include "IState.h"
#include "Cook.h"
#include "FreeCookState.h"

class Cook;
class BusyCookState : public IState{
private:
    Cook * cook;
public:
    BusyCookState(Cook *cook);
    void work() override;
};

#endif //PATTERNS_BUSYCOOKSTATE_H
