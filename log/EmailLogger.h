//
// Created by artem on 08.12.2019.
//

#ifndef PATTERNS_EMAILLOGGER_H
#define PATTERNS_EMAILLOGGER_H

#include "Logger.h"

class EmailLogger : public Logger  {
private:
    std::string email;
public:
    EmailLogger(int lvl, std::string email = "test@mail.ru");
protected:
    void writeMessage(std::string msg) override;
};


#endif //PATTERNS_EMAILLOGGER_H
