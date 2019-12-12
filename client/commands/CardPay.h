//
// Created by artem on 07.12.2019.
//

#ifndef PATTERNS_CARDPAY_H
#define PATTERNS_CARDPAY_H


#include <iostream>
#include "ICommand.h"
#include "../IOrder.h"
#include "../../log/Logger.h"
#include <chrono>
#include <thread>

class CardPay : public ICommand {
private:
    std::string numCard;
    std::string cardholder;
    std::string cvv;
    IOrder *order;
public:
    CardPay(string numCard, string cardholder, string cvv, IOrder *order);

    void execute() override;
};


#endif //PATTERNS_CARDPAY_H
