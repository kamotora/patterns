//
// Created by artem on 11.11.2019.
//

#ifndef PATTERNS_TELNOTIF_H
#define PATTERNS_TELNOTIF_H


#include "NotifDecorator.h"
class INotifier;

class TelNotif : public NotifDecorator{
public:
    TelNotif(INotifier *notifier);
    void notify(IOrder *order) override;
};


#endif //PATTERNS_TELNOTIF_H
