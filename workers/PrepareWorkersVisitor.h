//
// Created by artem on 07.12.2019.
//

#ifndef PATTERNS_PREPAREWORKERSVISITOR_H
#define PATTERNS_PREPAREWORKERSVISITOR_H

#include "Manager.h"
#include "Courier.h"
#include "cook/Cook.h"
#include "Drone.h"

class PrepareWorkersVisitor : public IVisitor{
private:
public:
    void prepare(Manager * worker) override ;

    void prepare(Courier * worker) override ;

    void prepare(Cook * worker) override ;

    void prepare(Drone * worker) override ;

};


#endif //PATTERNS_PREPAREWORKERSVISITOR_H
