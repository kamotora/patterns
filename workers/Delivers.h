//
// Created by artem on 06.11.2019.
//

#ifndef PATTERNS_DELIVERS_H
#define PATTERNS_DELIVERS_H


#include "Worker.h"
#include "cook/Cook.h"
#include "Manager.h"
#include "Courier.h"
#include "Drone.h"

class Delivers {
private:
    vector<Courier *> couriers;
    vector<Drone *> drones;
    static Delivers * instance;
    Delivers()= default;
public:
    Courier *getFreeCourier() {
        for(Courier *deliver: couriers){
            if(deliver->getCurOrder() == nullptr)
                return deliver;
        }
        return nullptr;
    }

    Drone *getFreeDrone() {
        for(Drone *deliver: drones){
            if(deliver->getCurOrder() == nullptr)
                return deliver;
        }
        return nullptr;
    }
    void addCourier(Courier *deliver){
        couriers.push_back(deliver);
    }

    void addDrone(Drone *deliver){
        drones.push_back(deliver);
    }

    static Delivers* getInstance(){
        if(!instance)
            instance = new Delivers();
        return instance;
    }
};


#endif //PATTERNS_DELIVERS_H
