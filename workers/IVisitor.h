//
// Created by artem on 07.12.2019.
//

#ifndef PATTERNS_IVISITOR_H
#define PATTERNS_IVISITOR_H

class Manager;
class Courier;
class Cook;
class Drone;

class IVisitor {
public:
    virtual void prepare(Manager * worker) = 0;

    virtual void prepare(Courier * worker) = 0 ;

    virtual void prepare(Cook * worker) = 0;

    virtual void prepare(Drone * worker) = 0;
};


#endif //PATTERNS_IVISITOR_H
