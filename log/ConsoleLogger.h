//
// Created by artem on 08.12.2019.
//

#ifndef PATTERNS_CONSOLELOGGER_H
#define PATTERNS_CONSOLELOGGER_H

#include "Logger.h"

class ConsoleLogger  : public Logger {
public:
    ConsoleLogger(int lvl);
protected:
    void writeMessage(std::string msg) override;
};


#endif //PATTERNS_CONSOLELOGGER_H
