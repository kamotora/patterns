//
// Created by artem on 26.11.2019.
//

#ifndef PATTERNS_CONSOLEDIALOG_H
#define PATTERNS_CONSOLEDIALOG_H


#include "IDialog.h"
#include <iostream>

#include "../goods/Shawarma.h"
#include "../goods/TypePizzaFactory.h"
#include "../goods/Pizza.h"
#include "../client/TypeDelivery.h"
#include "../client/Order.h"
#include "../client/OrderBuilder.h"
#include "../client/Clients.h"



class ConsoleDialog : public IDialog{
protected:
    std::string ask(std::string question);
    IOrder *order = nullptr;
    OrderBuilder orderBuilder;
public:
    IOrder *showDialog() override;
    void askAboutGoods();

    void askAboutPizza();

    bool askAboutTypeConcrPizza(string namePizza);
};


#endif //PATTERNS_CONSOLEDIALOG_H
