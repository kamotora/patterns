//
// Created by artem on 08.12.2019.
//

#include "EmailLogger.h"


void EmailLogger::writeMessage(std::string msg) {
    std::cout << "Сообщение на email "<< email <<": " << msg << std::endl;
}

EmailLogger::EmailLogger(int lvl, std::string email) : email(std::move(email)){
    this->myLvl = lvl;
}
