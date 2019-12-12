//
// Created by artem on 08.12.2019.
//

#include "Logger.h"
Logger* Logger::startLogger = nullptr;

Logger *Logger::setNext(Logger *next) {
    this->next = next;
    return next;
}

void Logger::message(const std::string& msg, int priority) {
    if(priority <= myLvl)
        writeMessage(msg);
    else
        next->message(msg,priority);
}

Logger *Logger::getLogger(){
    if(startLogger == nullptr)
        std::cout << "startLogger == null" << std::endl;
    return startLogger;
}

void Logger::setStartLogger(Logger *logger) {
    Logger::startLogger = logger;
}
