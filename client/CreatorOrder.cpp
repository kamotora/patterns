//
// Created by artem on 26.11.2019.
//

#include "CreatorOrder.h"

CreatorOrder::CreatorOrder(IDialog *dialog) : dialog(dialog) {}

IOrder *CreatorOrder::createNewOrder() {
    return dialog->showDialog();
}
