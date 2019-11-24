//
// Created by artem on 11.11.2019.
//

#include "NotifierAdapter.h"

NotifierAdapter::NotifierAdapter(string name, INotifier *iNotifier) : name(name) {
    this->notifier = iNotifier;
}

void NotifierAdapter::call(IOrder *order) {
    //Уведомляем тем способом, который выбрал клиент
    notifier->notify(order);
}
