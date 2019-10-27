#ifndef PATTERNS_IORDER_H
#define PATTERNS_IORDER_H

#include "string"
#include "Status.h"

using namespace std;

class Client;

class IOrder {
public:
    virtual Status* getStatus() = 0;
    virtual void setStatus(Status * status) = 0;
    virtual const string* getAddress() = 0;
    virtual Client* getClient() = 0;
    virtual double countPrice() = 0;
};


#endif //PATTERNS_IORDER_H
