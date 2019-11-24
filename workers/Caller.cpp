//
// Created by artem on 20.11.2019.
//

#include "Caller.h"

Caller::Caller(std::string name) : name(name){

}

void Caller::call(IOrder *order) {

        std::string str = order->getClient()->getTel();
        if(str.empty())
            std::cout << "Номер не указан" << std::endl;
        else
            std::cout << "Звоним клиенту по номеру " << str << "и сообщаем о начале доставки" << std::endl;

}
