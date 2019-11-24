//
// Created by artem on 11.11.2019.
//

#ifndef PATTERNS_TELEGRAMNOTIF_H
#define PATTERNS_TELEGRAMNOTIF_H


#include "NotifDecorator.h"

class TelegramNotif : public NotifDecorator {
public:
    TelegramNotif(INotifier *notifier);
    void notify(IOrder *order) override;
};


#endif //PATTERNS_TELEGRAMNOTIF_H
