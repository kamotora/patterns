//
// Created by artem on 26.11.2019.
//

#ifndef PATTERNS_CREATORORDER_H
#define PATTERNS_CREATORORDER_H

#include "../dialogs/IDialog.h"

class IOrder;

class CreatorOrder {
protected:
    IDialog *dialog;
public:
    CreatorOrder(IDialog *dialog);
    virtual IOrder * createNewOrder();
};


#endif //PATTERNS_CREATORORDER_H
