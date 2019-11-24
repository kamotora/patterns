//
// Created by artem on 11.11.2019.
//

#include "NotifDecorator.h"

void NotifDecorator::notify(IOrder *order) {
    if(wrappee != nullptr)
        wrappee->notify(order);
}

NotifDecorator::NotifDecorator(INotifier *notifier) {
    wrappee = notifier;
}
