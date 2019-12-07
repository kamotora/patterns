#include <iostream>
#include <thread>
#include <unistd.h>
#include <gtk/gtk.h>
#include "client/Client.h"
#include "workers/Manager.h"
#include "workers/Courier.h"
#include "workers/Drone.h"
#include "workers/cook/Cook.h"
#include "client/ProxyOrder.h"
#include "goods/Ingredient.h"
#include "goods/CookingGood.h"
#include "notifications/INotifier.h"
#include "notifications/EmailNotif.h"
#include "notifications/TelNotif.h"
#include "notifications/NotifierAdapter.h"
#include "notifications/TelegramNotif.h"
#include "workers/Caller.h"
#include "dialogs/LinuxFormDialog.h"
#include "dialogs/ConsoleDialog.h"
#include "client/ClientCareTaker.h"


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
/*
void queueWork(){
    while(true){
        //int count = 0;
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
                    //count++;
                    break;
                default:
                    //cout << "Заказ №" << order->getNumber() << ". " << temp(order->getStatus()) << endl;
                    sleep(1);
                    break;
            }
            sleep(1);
        }
        //if(count == orders.size())
          //  break;
    }
}


void cookWork(){
    while(true){
        for(Cook *cook:cooks){
            cook->cook();
        }
    }
}

void managerWork(){
    while(true){
        for(Manager *manager:managers){
            while (manager->getNextOrder() != nullptr){
                manager->packOrder();
                caller->call(manager->getCurOrder());
                manager->sendToDelivery();
            }
        }
    }
}
*/
vector<Product *> products;
void makeProducts(){
    auto *tomato = new Ingredient("Помидор",10);
    auto *cucumber = new Ingredient("Огурец",5);
    auto *cabbage = new Ingredient("Капуста",2);
    auto *cheese = new Ingredient("Сыр",20);
    auto *meat = new Ingredient("Колбаса",15);
    auto *meatCow = new Ingredient("Говядина",25);
    auto *meatPig = new Ingredient("Свинина",25);

    auto product1 = new CookingGood("Продукт 1",350);
    product1->addIngredient(tomato,3);
    product1->addIngredient(cabbage,2);
    product1->addIngredient(meat,3);

    auto product2 = new CookingGood("Продукт 2",400);
    product2->addIngredient(cucumber,5);
    product2->addIngredient(cheese,2);
    product2->addIngredient(meatCow,4);
    product2->addIngredient(tomato,2);


    auto product3 = new CookingGood("Продукт 2",500);
    product3->addIngredient(meatPig,3);
    product3->addIngredient(meat,3);
    product3->addIngredient(cheese,2);
    product3->addIngredient(meatCow,2);
    product3->addIngredient(tomato,2);

    products = {product1,product2,product3};
}

int main(int argc, char *argv[]) {
    srand(static_cast<unsigned int>(time(nullptr)));
    Courier *courier = new Courier("Вася");
    Cook *cook = new Cook("Повар",Cook::TypeCookingProduct::PIZZA);
    cooks.push_back(cook);
    Drone *drone = new Drone(1);
    Delivers::getInstance()->addDrone(drone);
    Delivers::getInstance()->addCourier(courier);
    vector<IDeliver*> delivers;
    delivers.push_back(drone);
    delivers.push_back(courier);
    //лр5
    CreatorOrder *creator = new CreatorOrder(new ConsoleDialog());
    IOrder *order1 = Clients::createNewOrder(creator);
    Client *client = order1->getClient();
    //end лр5

    Manager *manager = new Manager("Менеджер Саша");
    managers.push_back(manager);
    //лр4
    makeProducts();
    /*
    order1->addGood(products[0]);
    order1->addGood(products[1]);
    order1->addGood(products[2]);
    order1->countPrice();
    */
    INotifier *emailNotif = new EmailNotif();
    INotifier *telNotif = new TelNotif(emailNotif);
    INotifier *telegramNotif = new TelegramNotif(telNotif);

    //Было раньше
    //caller = new Caller("Звонильщик Коля");
    //Стало лучше
    auto caller = new NotifierAdapter("Автоматический звонильщик", telegramNotif);
    //

    //orders.push_back(new ProxyOrder((Order *)order1));
    ((Order *)order1)->addObserver(cook,Status::TypeStatus::PAID);
    ((Order *)order1)->addObserver(manager,Status::TypeStatus::COOKED);
    ((Order *)order1)->addObserver(caller,Status::TypeStatus::IN_DELIVERY_QUEUE);

    client->pay();
    //cook->addOrder(order1);
    /*
    Order *order2 = client->createNewOrder();
    client->pay();
    cook -> addOrder(order2);
    order2->setTypeDelivery(TypeDelivery::DRONE);
    orders.push_back(new ProxyOrder(order2));
    */
   //thread queueThread(queueWork);
    //sleep(1);

    //thread managerThread(managerWork);
    //managerThread.detach();
    //thread cookThread(cookWork);
    //cookThread.detach();
    char answ;
    do{
        cout << "Ещё заказ?(y,n)" << endl;
        cin >> answ;
        if(answ == 'y'){
            IOrder *newOrder = Clients::createNewOrder(creator);
            ((Order *)newOrder)->addObserver(cook,Status::TypeStatus::PAID);
            ((Order *)newOrder)->addObserver(manager,Status::TypeStatus::COOKED);
            ((Order *)newOrder)->addObserver(caller,Status::TypeStatus::IN_DELIVERY_QUEUE);

            //orders.push_back(newOrder);
            sleep(1);
            auto client1 = newOrder->getClient();
            client1->pay();
        }
    }while(answ != 'n');

    ClientCareTaker *careTaker = new ClientCareTaker();
    careTaker->save(client->createSnap());
    if(!client->changeInfo())
        client->restoreFromSnap(careTaker->restore());
    //queueThread.join();
    cout << "Все заказы обслужены" << endl;
    return 0;
}

