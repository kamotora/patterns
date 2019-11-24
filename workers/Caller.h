//
// Created by artem on 20.11.2019.
//

#ifndef PATTERNS_CALLER_H
#define PATTERNS_CALLER_H

#include <iostream>
#include "ICaller.h"
#include "../client/IOrder.h"
#include "../client/Client.h"
class Caller : public ICaller {
private:
    std::string name;
public:
    Caller(std::string name);
    void call(IOrder *order) override;
};


#endif //PATTERNS_CALLER_H
