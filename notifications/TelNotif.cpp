//
// Created by artem on 11.11.2019.
//

#include <iostream>
#include "TelNotif.h"

void TelNotif::notify(IOrder *order) {
    //Уведомляем другими способами
    if(wrappee != nullptr)
        wrappee->notify(order);
    std::string number = (order)->getClient()->getTel();
    if(number.empty())
        std::cout << "Ошибка при отправке смс на номер - номер не указан" << std::endl;
    else
        std::cout << "Уведомление на номер " << number << ": Заказ №"<<order->getNumber()<<" передан в доставку" << std::endl;
}

TelNotif::TelNotif(INotifier *notifier) : NotifDecorator(notifier) {}
