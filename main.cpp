#include <iostream>
#include <thread>
#include <unistd.h>
#include "client/Client.h"
#include "workers/Manager.h"
#include "workers/Courier.h"
#include "workers/Drone.h"
#include "workers/Cook.h"
#include "client/ProxyOrder.h"

vector<IOrder *> orders;
vector<Cook*> cooks;
vector<Manager*> managers;

using namespace std;

string temp(Status::TypeStatus name){
    string status;
    switch(name){
        case Status::TypeStatus::DECORATED:
            status = "Оформлен";break;
        case Status::TypeStatus::CANCELED:
            status = "Отменён";break;
        case Status::TypeStatus::PAID:
            status = "Оплачен";break;
        case Status::TypeStatus::IN_COOKING_QUEUE:
            status = "В очереди на приготовление";break;
        case Status::TypeStatus::COOK:
            status = "Готовится";break;
        case Status::TypeStatus::IN_DELIVERY_QUEUE:
            status = "В очереди на доставку";break;
        case Status::TypeStatus::DELIVER:
            status = "Доставляется";break;
        case Status::TypeStatus::COMPLETED:
            status = "Завершен";break;
        default:
            status = "Неизвесный статус заказа";break;
    }
    return status;
}

void queueWork(){
    while(true){
        int count = 0;
        for(IOrder *order :orders){
            switch (order->getStatus()){
                case Status::TypeStatus::PAID:
                    order->setStatus(Status::TypeStatus::IN_COOKING_QUEUE);
                    cooks.front()->addOrder(order);
                    break;
                case Status::TypeStatus::COOKED:
                    order->setStatus(Status::TypeStatus::IN_DELIVERY_QUEUE);
                    managers.front()->addOrder(order);
                    break;
                case Status::TypeStatus::COMPLETED:
                    count++;
                    break;
                default:
                    //cout << "Заказ №" << order->getNumber() << ". " << temp(order->getStatus()) << endl;
                    sleep(1);
                    break;
            }
        }
        if(count == orders.size())
            break;
    }
}


void cookWork(){
    while(true){
        for(Cook *cook:cooks){
            while (cook->getNextOrder() != nullptr){
                cook->cook();
            }
        }
    }
}

void managerWork(){
    while(true){
        for(Manager *manager:managers){
            while (manager->getNextOrder() != nullptr){
                manager->packOrder();
                manager->sendToDelivery();
            }
        }
    }
}

int main() {
    Client *client = new Client("Петя", "ул. Ленина, д.5", "01");
    Courier *courier = new Courier("Курьер");
    Cook *cook = new Cook("Повар",Cook::TypeCookingProduct::PIZZA);
    cooks.push_back(cook);
    Drone *drone = new Drone(1);
    vector<IDeliver*> delivers;
    delivers.push_back(drone);
    delivers.push_back(courier);
    Manager *manager = new Manager("Менеджер", delivers);
    Delivers::getInstance()->addDrone(drone);
    Delivers::getInstance()->addCourier(courier);
    managers.push_back(manager);
    Order *order1 = client->createNewOrder();
    orders.push_back(new ProxyOrder(order1));
    client->pay();
    cook->addOrder(order1);
    order1->setTypeDelivery(TypeDelivery::COURIER);
    Order *order2 = client->createNewOrder();
    client->pay();
    cook -> addOrder(order2);
    order2->setTypeDelivery(TypeDelivery::DRONE);
    orders.push_back(new ProxyOrder(order2));

    thread queueThread(queueWork);
    sleep(1);

    thread managerThread(managerWork);
    //managerThread.detach();
    thread cookThread(cookWork);
    //cookThread.detach();
    queueThread.join();
    cout << "Все заказы обслужены" << endl;
    return 0;
}

