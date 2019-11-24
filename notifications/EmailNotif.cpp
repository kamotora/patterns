//
// Created by artem on 11.11.2019.
//

#include <string>
#include <iostream>
#include "EmailNotif.h"

void EmailNotif::notify(IOrder *order) {
    std::string email = (order)->getClient()->getEmail();
    if(email.empty())
        std::cout << "Ошибка при отправке уведомления на email - email не указан" << std::endl;
    else
        std::cout << "Уведомление на email " << email << ": Заказ №"<<order->getNumber()<<" передан в доставку" << std::endl;
}
