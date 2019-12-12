//
// Created by artem on 07.12.2019.
//

#ifndef PATTERNS_WEBMONEYPAY_H
#define PATTERNS_WEBMONEYPAY_H


#include <iostream>
#include "ICommand.h"
#include "../IOrder.h"
#include "../../log/Logger.h"
#include <chrono>
#include <thread>

class WebmoneyPay : public ICommand {
private:
    std::string from;
    std::string to;
    IOrder *order;
public:
    WebmoneyPay(string from, string to, IOrder *order);

    void execute() override;
};


#endif //PATTERNS_WEBMONEYPAY_H
