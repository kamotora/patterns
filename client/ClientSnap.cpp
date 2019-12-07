//
// Created by artem on 04.12.2019.
//

#include "ClientSnap.h"

ClientSnap::ClientSnap(std::string name, std::string address, std::string tel, std::vector<IOrder *> prevOrders, IOrder *curOrder,
                       std::string email) : name(name), address(address),tel(tel), email(email), currentOrder(curOrder), ordersHistory(prevOrders){
}
