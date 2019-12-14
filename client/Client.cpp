#include "Client.h"

#include <utility>
#include <iostream>

void Client::addGoodToOrder() {

}

void Client::pay() {
    typePay->execute();
}

bool Client::changeInfo() {
    cout << "Введите новое имя (для отмены - #): ";
    string newName;
    cin >> newName;
    if(newName[0] == '#')
        return false;
    this->name = newName;

    cout << "Введите новый телефон (для отмены - #): ";
    string tel;
    cin >> tel;
    if(tel[0] == '#')
        return false;
    this->tel = tel;

    cout << "Введите новый email (для отмены - #): ";
    string email;
    cin >> email;
    if(email[0] == '#')
        return false;
    this->email = email;

    cout << "Удалить историю заказов (y,n),(для отмены - #): ";
    string ask;
    cin >> ask;
    if(ask[0] == '#')
        return false;
    if(ask == "y")
        ordersHistory.resize(0);
    return true;
}

void Client::chooseDeliveryMethod() {

}

void Client::delGoodFromOrder() {

}

string Client::getAddress() {
    return address;
}

Client::Client(string name, string address, string tel) :name(std::move(name)), address(std::move(address)), tel(std::move(tel)){

}



const string &Client::getTel() const {
    return tel;
}

const string &Client::getEmail() const {
    return email;
}

Client::Client(string name, string address, string tel, string email) :Client(std::move(name),std::move(address),std::move(tel)){
    this->email = std::move(email);
}

bool Client::equals(std::string name, std::string address, std::string tel) {
    return this->name == name && this->address == address && this->tel == tel;
}

bool Client::equals(std::string name, std::string address, std::string tel, std::string email) {
    return equals(name,address,tel) && this->email == email;
}

void Client::addOrder(IOrder *order) {
    ordersHistory.push_back(order);
    currentOrder = order;
}

const string &Client::getName() const {
    return name;
}

ClientSnap *Client::createSnap() {
    return new ClientSnap(name,address,tel,ordersHistory,currentOrder,email);
}

void Client::restoreFromSnap(ClientSnap *snap) {
    this->name = snap->name;
    this->ordersHistory = snap->ordersHistory;
    this->email = snap->email;
    this->tel = snap->tel;
    this->currentOrder = const_cast<IOrder *>(snap->currentOrder);
    this->address = snap->address;
}

void Client::setTypePay(ICommand *typePay) {
    Client::typePay = typePay;
}




