//
// Created by artem on 26.11.2019.
//

#include "CreatorOrder.h"

CreatorOrder::CreatorOrder(IDialog *dialog) : dialog(dialog), order(nullptr) {}

IOrder *CreatorOrder::createNewOrder() {
    order =  dialog->showDialogForOrder();
    if(order != nullptr && order->getClient() != nullptr)
        chooseTypePayment(order);
    return order;
}

void CreatorOrder::chooseTypePayment(IOrder *order) {
    ICommand *type =  dialog->showDialogForPay(order);
    order->getClient()->setTypePay(type);
}
