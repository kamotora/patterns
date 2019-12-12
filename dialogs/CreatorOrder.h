//
// Created by artem on 26.11.2019.
//

#ifndef PATTERNS_CREATORORDER_H
#define PATTERNS_CREATORORDER_H

#include "IDialog.h"

class IOrder;

class CreatorOrder {
protected:
    IDialog *dialog;
    IOrder *order;
public:
    CreatorOrder(IDialog *dialog);
    virtual IOrder * createNewOrder();
    virtual void chooseTypePayment();
};


#endif //PATTERNS_CREATORORDER_H
