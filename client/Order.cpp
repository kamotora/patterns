#include "Order.h"


Status::TypeStatus  Order::getStatus() {
    return status;
}

void Order::setStatus(Status::TypeStatus  status) {
    this->status = status;
    notifyObservers();
}

string Order::getAddress() {
    return address;
}

Client* Order::getClient() {
    return client;
}

double Order::countPrice() {
    double salePrice = 0.0;
    for(Product * good : goods)
        salePrice += good->getSaleCost();
    ProductIterator *iterator = new ProductIterator(&goods);
    iterator->setTypeSort(new BubbleSort());
    iterator->sort(IStrategy::standartComparator);
    double primePrice = 0.0;
    while(iterator->hasNext()){
        iterator->getNext();
        primePrice += iterator->getPrimeCostCur();
    }
    //std::cout << "Для заказа №" << this->number << " цена продажи = " << salePrice << ", цена себестоимости = " << primePrice << std::endl;
    return salePrice;
}

int Order::getNumber() {
    return number;
}

void Order::addGood(Product *good) {
    goods.push_back(good);
}

vector<Product *> Order::getGoods() {
    return goods;
}


Order::Order(Client *client, TypeDelivery typeDelivery) : client(client){
    if(client != nullptr)
        address = client->getAddress();
    status = Status::TypeStatus::DECORATED;
    time_t timeInSeconds;
    time(&timeInSeconds);
    date = localtime(&timeInSeconds);
    number = rand() % 100;
    if(typeDelivery != NONE)
        setTypeDelivery(typeDelivery);
}

Order::Order(Client *client, string address, TypeDelivery typeDelivery) : Order(client,typeDelivery){
    address = std::move(address);
}

Order::Order(Client *client, string address, TypeDelivery typeDelivery, vector<Product *> goods) : Order(client, address, typeDelivery){
    this->goods = std::move(goods);
}

IDeliver* Order::getDeliver() {
    return deliver;
}

void Order::setTypeDelivery(TypeDelivery typeDelivery) {
    switch(typeDelivery){
        case COURIER:
            deliver = Delivers::getInstance()->getFreeCourier();
            break;
        case DRONE:
            deliver = Delivers::getInstance()->getFreeDrone();
            break;
        case NONE:
            printf("Error! Неизвестный тип доставщика при создании заказа");
    }
    if(deliver == nullptr)
        printf("Error! Нет свободных доставщиков данного типа. Попробуйте выбрать другой тип доставки");
}

Order::Order(vector<Product *>  goods, Status::TypeStatus status, tm * date,
        int number, Client * client, string address,IDeliver *deliver):
        goods (std::move(goods)), status(status), date(date), number(number), client(client), address(std::move(address)), deliver(deliver) {}


void Order::removeObserver(IObserver *observer) {
    observers.erase(observer);
}

void Order::notifyObservers() {
    for(auto obj:observers)
        if(obj.second == status)
            obj.first->handleEvent(obj.second,this);
}

void Order::addObserver(IObserver *observer, Status::TypeStatus typeStatusOrder) {
    observers.insert(pair<IObserver *, Status::TypeStatus>(observer,typeStatusOrder));
}

void Order::setClient(Client *client) {
    this->client = client;
}


