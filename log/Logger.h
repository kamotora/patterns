//
// Created by artem on 08.12.2019.
//

#ifndef PATTERNS_LOGGER_H
#define PATTERNS_LOGGER_H


#include <string>
#include "iostream"
#include <utility>

class Logger {
public:
    const static int ERR = 3;
    const static int NOTIF = 5;
    const static int DEBUG = 7;
private:
    static Logger *startLogger;
protected:
    int myLvl;
    Logger *next;
    virtual void writeMessage(std::string msg) = 0;
public:
    Logger* setNext(Logger *next);
    void message(const std::string& msg, int priority);
    static Logger* getLogger();
    static void setStartLogger(Logger *logger);
};


#endif //PATTERNS_LOGGER_H
