//
// Created by artem on 08.12.2019.
//

#include "ConsoleLogger.h"
void ConsoleLogger::writeMessage(std::string msg) {
    std::cout << "Сообщение в консоль: " << msg << std::endl;
}

ConsoleLogger::ConsoleLogger(int lvl){
    this->myLvl = lvl;
}
