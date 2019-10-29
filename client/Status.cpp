//
// Created by root on 24.10.2019.
//

#include "Status.h"

Status::TypeStatus Status::getName() const {
    return name;
}
 string Status::getName(){
    string status;
    switch(name){
        case DECORATED:
            status = "Оформлен";break;
        case CANCELED:
            status = "Отменён";break;
        case PAID:
            status = "Оплачен";break;
        case IN_COOKING_QUEUE:
            status = "В очереди на приготовление";break;
        case COOK:
            status = "Готовится";break;
        case IN_DELIVERY_QUEUE:
            status = "В очереди на доставку";break;
        case DELIVER:
            status = "Доставляется";break;
        case COMPLETED:
            status = "Завершен";break;
        default:
            status = "Неизвесный статус заказа";break;
    }
    return status;
}

void Status::setName(TypeStatus name) {
    Status::name = name;
}
