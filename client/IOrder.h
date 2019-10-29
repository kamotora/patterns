#ifndef PATTERNS_IORDER_H
#define PATTERNS_IORDER_H
#include <vector>
#include "string"
#include "Status.h"
#include "../goods/Good.h"
#include "TypeDelivery.h"

using namespace std;

class Client;

class IOrder {
public:
    virtual Status::TypeStatus getStatus() = 0;
    virtual void setStatus(Status::TypeStatus  status) = 0;
    virtual string getAddress() = 0;
    virtual Client* getClient() = 0;
    virtual int getNumber() = 0;
    virtual double countPrice() = 0;
    virtual void addGood(Good *good) = 0;
    virtual vector<Good *> getGoods() = 0;
    virtual TypeDelivery getTypeDelivery() = 0;
};


#endif //PATTERNS_IORDER_H
