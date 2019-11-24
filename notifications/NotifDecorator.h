//
// Created by artem on 11.11.2019.
//

#ifndef PATTERNS_NOTIFDECORATOR_H
#define PATTERNS_NOTIFDECORATOR_H


#include "INotifier.h"

class NotifDecorator : public INotifier {
protected:
    INotifier * wrappee;
public:
    explicit NotifDecorator(INotifier *notifier);
    void notify(IOrder *order) override;
};


#endif //PATTERNS_NOTIFDECORATOR_H
