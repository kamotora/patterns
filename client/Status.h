#ifndef PATTERNS_STATUS_H
#define PATTERNS_STATUS_H
#include "string"

using namespace std;

enum typeStatus {
    //Оформлен
    DECORATED,
    //Оплачен
    PAID,
    //В очереди на приготовление
    IN_COOKING_QUEUE,
    //Готовится
    COOK,
    //В очереди на доставку
    IN_DELIVERY_QUEUE,
    //Доставляется
    DELIVERED,
    //Завершен
    COMPLETED,
    //Отменён
    CANCELED
};

class Status{
private:
    typeStatus name;
public:
    typeStatus getName() const;

    string getName();

    void setName(typeStatus name);
};
#endif //PATTERNS_STATUS_H
