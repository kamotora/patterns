//
// Created by artem on 30.11.2019.
//

#ifndef PATTERNS_FREECOOKSTATE_H
#define PATTERNS_FREECOOKSTATE_H

#include "IState.h"
#include "BusyCookState.h"


class Cook;
class FreeCookState : public IState{
private:
    Cook * cook;
public:
    FreeCookState(){};
    FreeCookState(Cook *cook);
    void work() override;
};



#endif //PATTERNS_FREECOOKSTATE_H
