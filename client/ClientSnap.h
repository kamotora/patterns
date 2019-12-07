//
// Created by artem on 04.12.2019.
//

#ifndef PATTERNS_CLIENTSNAP_H
#define PATTERNS_CLIENTSNAP_H


#include <string>
#include <vector>
class IOrder;

class ClientSnap {
public:
    const std::string name;
    const std::string address;
    const std::string tel;
    const std::string email;
    const std::vector<IOrder *> ordersHistory;
    const IOrder * currentOrder = nullptr;
public:
    ClientSnap(std::string name, std::string address, std::string tel, std::vector<IOrder *> prevOrders, IOrder *curOrder,
               std::string email);
};


#endif //PATTERNS_CLIENTSNAP_H
