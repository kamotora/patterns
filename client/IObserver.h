//
// Created by artem on 02.12.2019.
//

#ifndef PATTERNS_IOBSERVER_H
#define PATTERNS_IOBSERVER_H


#include "Status.h"

class IOrder;
class IObserver {
public:
    virtual void handleEvent(Status::TypeStatus typeStatusOrder, IOrder *order) = 0;
};


#endif //PATTERNS_IOBSERVER_H
