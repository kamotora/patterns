#ifndef PATTERNS_IORDER_H
#define PATTERNS_IORDER_H
#include <vector>
#include "string"
#include "Status.h"
#include "../goods/Product.h"
#include "TypeDelivery.h"

using namespace std;

class Client;
class IDeliver;
class IOrder {
public:
    virtual Status::TypeStatus getStatus() = 0;
    virtual void setStatus(Status::TypeStatus  status) = 0;
    virtual string getAddress() = 0;
    virtual Client* getClient() = 0;
    virtual int getNumber() = 0;
    virtual double countPrice() = 0;
    virtual void addGood(Product *good) = 0;
    virtual vector<Product *> getGoods() = 0;
    virtual IDeliver *getDeliver() = 0;
    virtual void setTypeDelivery(TypeDelivery typeDelivery) = 0;
    virtual void setClient(Client *client) = 0;
    //virtual void deleteGood(Product * good) = 0;
};


#endif //PATTERNS_IORDER_H
