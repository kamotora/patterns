//
// Created by artem on 26.11.2019.
//

#include "CreatorOrder.h"

CreatorOrder::CreatorOrder(IDialog *dialog) : dialog(dialog), order(nullptr) {}

IOrder *CreatorOrder::createNewOrder() {
    order =  dialog->showDialogForOrder();
    chooseTypePayment();
    return order;
}

void CreatorOrder::chooseTypePayment() {
    dialog->showDialogForPay();
}
