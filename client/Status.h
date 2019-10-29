#ifndef PATTERNS_STATUS_H
#define PATTERNS_STATUS_H
#include "string"

using namespace std;



class Status{
public:
    enum TypeStatus {
        //Оформлен
        DECORATED,
        //Оплачен
        PAID,
        //В очереди на приготовление
        IN_COOKING_QUEUE,
        //Готовится
        COOK,
        //Приготовлен
        COOKED,
        //В очереди на доставку
        IN_DELIVERY_QUEUE,
        //Доставляется
        DELIVER,
        //Завершен
        COMPLETED,
        //Отменён
        CANCELED
    };
private:
    TypeStatus name;
public:
    TypeStatus getName() const;

    string getName();

    void setName(TypeStatus name);


};
#endif //PATTERNS_STATUS_H
