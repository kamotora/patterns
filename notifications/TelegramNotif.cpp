//
// Created by artem on 11.11.2019.
//

#include <iostream>
#include "TelegramNotif.h"

void TelegramNotif::notify(IOrder *order) {
    if(wrappee != nullptr)
        wrappee->notify(order);
    std::string number = (order)->getClient()->getTel();
    if(number.empty())
        std::cout << "Ошибка при отправке смс в Telegram - номер не указан" << std::endl;
    else
        std::cout << "Уведомление в Telegram на номер " << number << ": Заказ №"<<order->getNumber()<<" передан в доставку" << std::endl;
}

TelegramNotif::TelegramNotif(INotifier *notifier) : NotifDecorator(notifier) {

}
