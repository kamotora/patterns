//
// Created by artem on 26.11.2019.
//

#ifndef PATTERNS_CREATORORDER_H
#define PATTERNS_CREATORORDER_H

#include "IDialog.h"
#include "../client/Client.h"

class IOrder;

class CreatorOrder {
protected:
    IDialog *dialog;
    IOrder *order;
public:
    CreatorOrder(IDialog *dialog);
    virtual IOrder * createNewOrder();
    void chooseTypePayment(IOrder *order);
};


#endif //PATTERNS_CREATORORDER_H
