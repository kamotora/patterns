//
// Created by artem on 08.12.2019.
//

#ifndef PATTERNS_SMSLOGGER_H
#define PATTERNS_SMSLOGGER_H


#include "Logger.h"

class SmsLogger : public Logger {
private:
    std::string numPhone;
public:
    SmsLogger(int lvl, std::string numPhone = "124567");
protected:
    void writeMessage(std::string msg) override;
};


#endif //PATTERNS_SMSLOGGER_H
