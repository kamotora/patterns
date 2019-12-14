//
// Created by root on 24.10.2019.
//

#ifndef PATTERNS_CLIENT_H
#define PATTERNS_CLIENT_H
#include <string>
#include <vector>
#include "IOrder.h"
#include "ClientSnap.h"
#include "commands/ICommand.h"


using namespace std;


class Client  {
private:
    string name;
    string address;
    string tel;
    string email;
    vector<IOrder *> ordersHistory;
    IOrder * currentOrder = nullptr;
    ICommand *typePay;
public:
    Client(string name, string address, string tel);
    Client(string name, string address, string tel,string email);
    void pay();
    void addOrder(IOrder *order);
    bool changeInfo();
    void chooseDeliveryMethod();
    void addGoodToOrder();
    void delGoodFromOrder();
    string getAddress();

    const string &getTel() const;

    const string &getEmail() const;

    const string &getName() const;

    bool equals(std::string name,std::string address,std::string tel);

    bool equals(std::string name,std::string address,std::string tel,std::string email);

    ClientSnap * createSnap();
    void restoreFromSnap(ClientSnap *snap);

    void setTypePay(ICommand *typePay);

};


#endif //PATTERNS_CLIENT_H
