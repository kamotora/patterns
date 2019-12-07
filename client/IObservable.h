//
// Created by artem on 02.12.2019.
//

#ifndef PATTERNS_IOBSERVABLE_H
#define PATTERNS_IOBSERVABLE_H

#include "Status.h"

class IObserver;
class IObservable {
public:
    virtual void addObserver(IObserver *observer, Status::TypeStatus typeStatusOrder) = 0;
    virtual void removeObserver(IObserver *observer) = 0;
    virtual void notifyObservers() = 0;
};


#endif //PATTERNS_IOBSERVABLE_H
