//
// Created by artem on 11.11.2019.
//

#ifndef PATTERNS_EMAILNOTIF_H
#define PATTERNS_EMAILNOTIF_H


#include "INotifier.h"

class EmailNotif : public INotifier {
public:
    EmailNotif() = default;
    void notify(IOrder *order) override;
};


#endif //PATTERNS_EMAILNOTIF_H
