//
// Created by artem on 08.12.2019.
//

#include "SmsLogger.h"

void SmsLogger::writeMessage(std::string msg) {
    std::cout << "Экстренное сообщение на номер " << numPhone <<" по смс: " << msg << std::endl;
}

SmsLogger::SmsLogger(int lvl, std::string numPhone): numPhone(std::move(numPhone)) {
    this->myLvl = lvl;
}
