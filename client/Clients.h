//
// Created by artem on 27.11.2019.
//

#ifndef PATTERNS_CLIENTS_H
#define PATTERNS_CLIENTS_H


#include <iostream>
#include "Client.h"

class Clients {
private:
    static std::vector<Client *> clients;
public:
    static Client *getClient(std::string name,std::string address,std::string tel){
        if(clients.empty()){
            for(auto client : clients){
                if(client->equals(name,address,tel))
                    return client;
            }
        }
        return new Client(name,address,tel);
    }

    static Client *getClient(std::string name,std::string address,std::string tel,std::string email){
        if(clients.empty()){
            for(auto client : clients){
                if(client->equals(name,address,tel,email))
                    return client;
            }
        }
        return new Client(name,address,tel,email);
    }

    static IOrder *createNewOrder(CreatorOrder *creator){
        auto order = creator->createNewOrder();
        //Order *order = new Order(this,this->address, TypeDelivery::COURIER);
        if(order == nullptr){
            std::cout << "Не удалось создать заказ" << std::endl;
            return nullptr;
        }
        cout << "Заказ №"<<order->getNumber() << " создан клиентом " << order->getClient()->getName() << endl;
        order->getClient()->addOrder(order);
        return order;
    }
};


#endif //PATTERNS_CLIENTS_H
