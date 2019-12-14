//
// Created by artem on 26.11.2019.
//

#ifndef PATTERNS_IDIALOG_H
#define PATTERNS_IDIALOG_H

#include "../client/commands/ICommand.h"

class IOrder;
class IDialog {
public:
    virtual IOrder * showDialogForOrder() = 0;
    virtual ICommand *showDialogForPay(IOrder *order) = 0;
};


#endif //PATTERNS_IDIALOG_H
